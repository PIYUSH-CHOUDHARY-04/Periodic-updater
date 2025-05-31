#include "json_parser.h"

api_metadata s1;
char* path = "/home/mercx/Desktop/Computer Tech/Softwares/Project Periodic update/Code/testing/json_parser_testing/api_creds.json";

char* ptr=(char*)&s1;

void main(void){
	parse_json(path,&s1);
	for(int i=0;i<7;i++){
		printf("attr[%d] : %s\n",i,ptr);
		ptr+=METADATA_ATTR_MAXSIZE;

	}



}
