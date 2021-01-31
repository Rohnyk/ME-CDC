/*
 * server.c: Server program
 *           to demonstrate interprocess commnuication
 *           with System V message queues
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
//create a file where the key for message queque will be stored
#define SERVER_KEY_PATHNAME "/tmp/mqueue_server_key"
//ID for the message queque
#define PROJECT_ID 'M'
//persmission for th message queque
#define QUEUE_PERMISSIONS 0660
	
//structure where the messages will be stroes buf strore the value
struct message_text {
    int qid;
    char buf [200];
};

//strcut to hold the message and the type
struct message {
    long message_type;
    struct message_text message_text;
};

int main (int argc, char **argv)
{
    key_t msg_queue_key; // key for the message
    int qid;	// queque id
    struct message message; //message 

//geenreate key using ftok with filename and project id
    if ((msg_queue_key = ftok (SERVER_KEY_PATHNAME, PROJECT_ID)) == -1) {
        perror ("ftok");
        exit (1);
    }
//create the queque id 
    if ((qid = msgget (msg_queue_key, IPC_CREAT | QUEUE_PERMISSIONS)) == -1) {
        perror ("msgget");
        exit (1);
    }

    printf ("Server: Hello, World!\n");

    while (1) {
        // read an incoming message using message receive 
        if (msgrcv (qid, &message, sizeof (struct message_text), 0, 0) == -1) {
            perror ("msgrcv");
            exit (1);
        }

        printf ("Server: message received.\n");

        // process message
        int length = strlen (message.message_text.buf);
        printf("length of message received: %d\n",length);
        char buf [20];
        sprintf (buf, " %d", length); 
        printf("Buffer: %s\n",buf);
        strcat (message.message_text.buf, buf);

        int client_qid = message.message_text.qid;
        message.message_text.qid = qid;

        // send reply message to client
        if (msgsnd (client_qid, &message, sizeof (struct message_text), 0) == -1) {  
            perror ("msgget");
            exit (1);
        }

        printf ("Server: response sent to client.\n");
    }
}
