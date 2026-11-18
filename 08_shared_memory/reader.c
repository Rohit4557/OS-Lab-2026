#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
    key_t key = ftok(".", 'A');

    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    char *shared_memory = (char *)shmat(shmid, NULL, 0);

    printf("Data from shared memory: %s\n", shared_memory);

    shmdt(shared_memory);

    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}