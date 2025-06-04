#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<linux/vt.h>
#include<sys/ioctl.h>
#include<string.h>



void main(void){
	char* tty_path=ttyname(0);
	int tty_file_fd=open(tty_path, O_RDWR|O_NONBLOCK);
	printf("Current TTY : %s\n",tty_path);


	struct vt_mode mode;
	memset(&mode, 0, sizeof(mode));
	if(ioctl(tty_file_fd,VT_GETMODE, &mode)<0){
		printf("ioctl failed.\n");
	}

	if(mode.mode==VT_AUTO){
		printf("TTY in VT_AUTO mode i.e. CLI mode");
	}else if(mode.mode==VT_PROCESS){
		printf("TTY in VT_PROCESS mode i.e. GUI mode");
	}else{
		printf("Unknown mode : %d\n",mode.mode);
	}
	close(tty_file_fd);


}
