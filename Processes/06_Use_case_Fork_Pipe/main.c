#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<errno.h>

int main(int argc, char* argv[]){
    int arr[] = {1,2,3,4,1,2,6,3};
    int arrSize = sizeof(arr)/sizeof(int);
    int start, end;
    int fd[2];
    if(pipe(fd)==-1){
        return 1;
    }
    int id = fork();
    if(id==-1){
        return 2;
    }
    if(id==0){
        start = 0;
        end = start+arrSize/2;
    }else{
        start = arrSize/2;
        end = arrSize;
    }
    int sum =0;
    for(int i=start;start<end;i++){
        sum+=arr[i];
    }
    printf("Calculated partial Sum %d",sum);

    if(id==0){
        close(fd[0]);
        write(fd[1], &sum, sizeof(int));
        close(fd[1]);
    }else{
        int sumFromChild;
        close(fd[1]);
        read(fd[0], &sumFromChild, sizeof(int));
        close(fd[0]);

        int totalSum = sum+ sumFromChild;
        printf("Total sum is %d\n",totalSum);
        wait(NULL);
    }
    return 0;
}