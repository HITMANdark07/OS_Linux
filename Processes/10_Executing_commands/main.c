#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<sys/wait.h>

int main(int argc, char* argv[]){

    int pid = fork();
    if(pid==-1) return 1;
    if(pid==0){
        execlp("ping", "ping", "-c", "3", "google.com", NULL);
    }else{
        wait(NULL);
        printf("Success! \n");
        printf("Some post processing goes here!\n");
    }
    return 0;
}