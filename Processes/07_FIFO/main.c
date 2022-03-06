#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

#include<sys/stat.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<errno.h>
#include<fcntl.h>

int main(int argc, char* argv[]){
    if(mkfifo("myfifo1",0777) ==-1){
        if(errno!=EEXIT){
            printf("Could not create fifo file.\n");
            return 1;
        }
    }

    int fd = open("myfifo1", O_WRONLY);
    int x = 97;
    if(write(fd,&x, sizeof(x))==-1){
        return 2;
    }
    close(fd);
    return 0;
}