#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char* argv[]){
    int id = fork();
    printf("Curretn ID %d, Parent ID: %d\n", getpid(), getppid());
    return 0;
}