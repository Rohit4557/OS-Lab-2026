#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main()
{
    key_t key = ftok(".", 'A');

    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    char *shared_memory = (char *)shmat(shmid, NULL, 0);

    printf("Enter message: ");
    fgets(shared_memory, 1024, stdin);

    printf("Data written to shared memory\n");

    shmdt(shared_memory);

    return 0;
}