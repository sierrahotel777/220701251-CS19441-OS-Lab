#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define SharedMemSize 50

void main()
{
    char c;
    int shmid;
    key_t key;
    char *shared_memory;
    key = 5677;
    if((shmid = shmget(key,SharedMemSize,0666))<0)
    {
        perror("shmget");
        exit(1);
    }

    //Attach the segment to our dataa space
    if((shared_memory=shmat(shmid,NULL,0))==(char *)-1)
    {
        perror("shmat");
        exit(1);
    }

    printf("Message Received: %s /n",shared_memory);
    exit(0); 
}
