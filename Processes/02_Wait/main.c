#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char* argv[]){
    int id = fork();
    int n;
    if(id==0){
        n=1;
    }else{
        n=6;
    }
    if(id!=0){
        wait();
    }
    int i;
    for(i=0;i<n+5;i++){
        printf("%d", i);
        fflush(stdout);
    }

    return 0;
}