#include <stdio.h>
#include <signal.h>
#include "phglobal.h"
#include <pthread.h>
#include <fcntl.h>
#define Server_FIFO_Name "/tmp/Phddns_fifo"
void write_pipe(void){
	char MSG[8]="STOP";
	int server_fifo_fd;
	int rst;        
	//打开服务器管道，开始写入. 采用NON_BLOCK方式，所以需要服务器先打开。
	server_fifo_fd = open(Server_FIFO_Name,O_WRONLY | O_NONBLOCK);
	if(server_fifo_fd==-1){         
		return;
	}   
	//向管道中写入数据：发送.
	write(server_fifo_fd,MSG,strlen(MSG));          
	close(server_fifo_fd);                          
	return ;
}
int main(int argc,char **argv){
	//write_pipe();
	int pid;
	pid=atoi(argv[1]);
	kill(pid,SIGUSR2);
	return 0;
}
