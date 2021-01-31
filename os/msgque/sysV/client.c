/*
 * client.c: Client program
 *           to demonstrate interprocess commnuication
 *           with System V message queues
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

//key file
#define SERVER_KEY_PATHNAME "/tmp/mqueue_server_key"
//id
#define PROJECT_ID 'M'

//strcuture
struct message_text {
    int qid;
    char buf [200];
};


//strcuture 
struct message {
    long message_type;
    struct message_text message_text;
};


//main
int main (int argc, char **argv)
{
    key_t server_queue_key;//key 
    int server_qid, myqid; //server qid & client qid
    struct message my_message, return_message; //client message and return message from server

    // create my client queue for receiving messages from server
    if ((myqid = msgget (IPC_PRIVATE, 0660)) == -1) {
        perror ("msgget: myqid");
        exit (1);
    }

    //server queque key 
    if ((server_queue_key = ftok (SERVER_KEY_PATHNAME, PROJECT_ID)) == -1) {
        perror ("ftok");
        exit (1);
    }

    //server qid
    if ((server_qid = msgget (server_queue_key, 0)) == -1) {
        perror ("msgget: server_qid");
        exit (1);
    }

    //clinet message 
    my_message.message_type = 1;
    my_message.message_text.qid = myqid;

    printf ("Please type a message: ");
    //the message typed is stored in buf via stdin ..note the usage of fgets
    while (fgets (my_message.message_text.buf, 198, stdin)) {
        // remove newline from string
        int length = strlen (my_message.message_text.buf);
        if (my_message.message_text.buf [length - 1] == '\n')
           my_message.message_text.buf [length - 1] = '\0'; //add \0 at the end

        // send message to server
        if (msgsnd (server_qid, &my_message, sizeof (struct message_text), 0) == -1) {
            perror ("client: msgsnd");
            exit (1);
        }

        // read response from server
        if (msgrcv (myqid, &return_message, sizeof (struct message_text), 0, 0) == -1) {
            perror ("client: msgrcv");
            exit (1);
        }

        // process return message from server
        printf ("Message received from server: %s\n\n", return_message.message_text.buf);  

        printf ("Please type a message: ");
    }
    // remove message queue
    if (msgctl (myqid, IPC_RMID, NULL) == -1) {
            perror ("client: msgctl");
            exit (1);
    }

    printf ("Client: bye\n");

    exit (0);
}
