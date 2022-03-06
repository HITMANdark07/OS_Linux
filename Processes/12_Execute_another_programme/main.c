#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<process.h>

int main(int argc, char* argv[]){

    _execl("C:\\windows\\System32\\ping.exe", "C:\\windows\\System32\\ping.exe", "google.com", NULL);
    printf("Program finished executing \n");
    return 0;
}