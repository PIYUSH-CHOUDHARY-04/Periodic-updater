#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

void main(int argc, char** argv, char** environ){
	//char** ptr=environ;
	//while(*ptr!=NULL){
	//	printf(">> %s\n",*ptr);
	//	ptr++;
	//}

    const char* xdg_session_type=getenv("XDG_SESSION_TYPE");
    const char* xdg_current_desktop=getenv("XDG_CURRENT_DESKTOP");
    const char* desktop_session=getenv("DESKTOP_SESSION");
    const char* display=getenv("DISPLAY");

    if( (strcmp(xdg_session_type,"tty")!=0) || (xdg_current_desktop != NULL && strlen(xdg_current_desktop)>0) || (desktop_session != NULL && strlen(desktop_session)>0) || (display != NULL && strlen(display)>0) ){
        printf("GUI detected, program running in GUI with details : \nXDG_SESSION_TYPE=%s\nXDG_CURRENT_DESKTOP=%s\nDESKTOP_SESSION=%s\nDISPLAY=%s\n",(xdg_session_type),(xdg_current_desktop),(desktop_session),(display));
    }else{
        printf("No GUI detected, program running in TTY mode.\n");
    }

}
