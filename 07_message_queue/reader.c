#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct message
{
    long type;
    char text[100];
};

int main()
{
    key_t key = ftok(".", 'A');
    int msgid = msgget(key, 0666 | IPC_CREAT);

    struct message msg;

    msgrcv(msgid, &msg, sizeof(msg.text), 1, 0);

    printf("Message received: %s\n", msg.text);

    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}