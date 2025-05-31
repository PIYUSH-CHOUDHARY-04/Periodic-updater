#include "json_parser.h"

/**
 * @brief array to the key strings of the json file, used by parse_json() routine.
 */
char* json_key_array[KEY_COUNT]={CLIENT_ID, PROJECT_ID, AUTH_URI, TOKEN_URI, AUTH_PROVIDER_X509_CERT_URL, CLIENT_SECRET, REDIRECT_URI};

/**
 * @brief Parses the .json file and creates a .conf binary file which can be interpreted as some struct
 * @param param1 passes the path to the json file
 * @param param2 passes the pointer to the api_metadata structure
 * @return returns 0 on success
 */
int parse_json(const char* json_path, api_metadata* api_md){
	FILE* json_fptr=fopen(json_path,"r");
	// No need to check for null ptr cuz functions invoked before this in main() would have thrown error if file doesn't exist.
	// getting the file size first.
	if(fseek(json_fptr, 0, SEEK_END)!=0){
		perror("fseek() failed");
		return -4;
	}
	long int json_size=ftell(json_fptr);
	printf("json file size : %ld\n",json_size);
	rewind(json_fptr);
	char* json_str=(char*)malloc(sizeof(char)*json_size+1);
	json_str[json_size]='\0';
	if(fread(json_str, sizeof(char), json_size, json_fptr)!=json_size){
		perror("fread() failed");
		return -5;
	}
	fclose(json_fptr);
	
	
	// let's now search for all hardcoded keys which we already know and populate the api_metadata structure.
	char* marker0=NULL;
	char* marker1=NULL;
	unsigned short int value_size=0;

	for(int i=0;i<KEY_COUNT-1;i++){ // -1 cuz we need to handle last key manually since it as [] in value field.
		
		if(i==0){
			marker0=strstr(json_str,json_key_array[i]);
			marker0+=(JSON_STRUCTURAL_DIFF+strlen(json_key_array[i]));	// now, marker pointing to the first char of the corresponding value i.e. next to the opening double quote.			
		}
		// we don't know the size of the value string, thus either we need to search for closing double quote char by char or we just search for next key string and then we'll move back by JSON_STRUCTURAL_DIFF 
		marker1=strstr(json_str,json_key_array[i+1]);
		// now size of the value string for ith key is marker1-JSON_STRUCTURAL_DIFF-marker0
		memcpy(api_md,marker0,marker1-JSON_STRUCTURAL_DIFF-marker0);
		marker0=marker1+strlen(json_key_array[i+1])+JSON_STRUCTURAL_DIFF;
		api_md=(api_metadata*)((char*)api_md+METADATA_ATTR_MAXSIZE);
	}
	// handling last key manually cuz of [] in value.
	marker0++;
	memcpy(api_md,marker0,strstr(marker0,"\"]}}")-marker0);
	free(json_str);
	return 0;
}
