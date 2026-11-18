#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

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

    msg.type = 1;

    printf("Enter message: ");
    fgets(msg.text, sizeof(msg.text), stdin);

    msgsnd(msgid, &msg, sizeof(msg.text), 0);

    printf("Message sent\n");

    return 0;
}