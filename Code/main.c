#include "main.h"

// global data
unsigned char flag = 0x00;
int retval=0x00000000;


// Routines

int copy_file(const char* dest, const char* file_path){
	int src_fd=open(file_path,O_RDONLY);
	if(src_fd<0){
		perror("open() for source file failed");
		return -1;
	}

	int dest_fd=open(dest, O_WRONLY|O_CREAT|O_TRUNC, 0666);
	if(dest_fd<0){
		perror("open() for destination path failed");
		close(src_fd);
		return -2;
	}
	short int data_copied_this_iter=0;
	unsigned int total_data_copied=0;
	while(1){
		data_copied_this_iter=copy_file_range(src_fd, NULL, dest_fd, NULL, COPY_FILE_BLOCKSIZE, 0);
		if(data_copied_this_iter<0){
			perror("copy_file_range() failed");
			close(src_fd);
			close(dest_fd);
			return -3;
		}
		
		total_data_copied+=(unsigned int)data_copied_this_iter;

		if(data_copied_this_iter<COPY_FILE_BLOCKSIZE){
			break;
		}
	}
	printf("file %s copied successfully to %s , %d bytes copied.\n", file_path, dest, total_data_copied);
	close(src_fd);
	close(dest_fd);
	return 0;
}

   


int main(void){
	char app_dir[PATH_MAX]={0};
	short int rl=readlink(READLINK_PATH, app_dir, sizeof(app_dir));
	if(rl<0){
		perror("readlink() failed");
		return -1;
	}
	//readlink() provides the absolute path to the executable and string is not null terminated 
	//e.g : /home/.../dirX/app.exe , thus need to strip it off.
	memset(app_dir+rl-sizeof(APP_NAME),0,sizeof(APP_NAME)+1); // +1 for nullifying 1 byte beyond what syscall returned.

	DIR* app_dir_ptr = opendir(app_dir);
	if(app_dir_ptr==NULL){
		perror("opendir() failed");
		return -2;
	}

	struct dirent* entry0=NULL;
	while((entry0=readdir(app_dir_ptr))!=NULL){
		if(strncmp(API_CREDS_JSON_FILE,entry0->d_name,API_CREDS_JSON_FILE_STRLEN)==0){
			// This means .json file is already there, program is not running very first time.
			flag|=API_CREDS_JSON_FOUND_FLAG;
			break;
		}		
	}

	if(flag & API_CREDS_JSON_FOUND_FLAG == 0){
		// This means .json file not found and program is likely running first time or creds are cleared.
		// Need to copy the .json from user given path into the CWD for future execution usage.
		char json_path[PATH_MAX]={0}; // Null-terminated path.
		fgets(json_path,PATH_MAX,stdin);
		//input path string is terminated with '\n' , thus we need to search for it and replace it with '\0'
	//	json_path[strcspn(json_path,"\n")]='\0';   // path already null-terminated.
		// let's now copy the .json file to program directory.
		if((retval=copy_file(app_dir, json_path))!=0){
			printf("copy_file() failed with retval : %d\n",retval);
			return -3;
		} 
		// let's now parse json file, make auth request and capture the code.
		api_metadata* api_auth_req = (api_metadata*)malloc(sizeof(api_metadata));
		if((retval=parse_json(json_path,api_auth_req))!=0){
			printf("parse_json() failed with retval : %d\n",retval);
			return -4;
		}
	
	
	
	}

	




	return 0;

}
