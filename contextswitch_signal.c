#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

int current_process = 1;

void context_switch(int signum){
	if(current_process == 1){
		printf("switching from p1 to p2\n");
		current_process = 2;
	}
	else{
		printf("switching from p2 to p1\n");
		current_process = 1;
	}
	alarm(1);
}

void process1(){
	if(current_process==1){
		printf("p1 is running\n");
		sleep(1);
	}
}

void process2(){
	if(current_process==2){
		printf("p2 is running\n");
		sleep(1);
	}
}


int main(){
	if (signal(SIGALRM, context_switch) == SIG_ERR) {
        perror("signal");
        exit(EXIT_FAILURE);
    }
    alarm(1);
	for(int i=0;i<10;i++){
		printf("In Current Context %d \n", current_process);
		if(current_process==1){
			process1();
		}
		else{
			process2();
		}
	}
	return 0;
}
