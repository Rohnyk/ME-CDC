/* ----------------------------------------------------------------- */
/* PROGRAM  server.c                                                 */
/*    This program serves as the server similar to the one in shm.c. */
/* The difference is that the client is no more a child process.     */
/* Thus, some mechanism must be established between the server and   */
/* the client.  This program uses a naive one.  The shared memory    */
/* has an indicator whose possible values are NOT_READY, FILLED and  */
/* TAKEN.  Before the server completes filling data, the status is   */
/* NOT_READY, after filling data it is FILLED.  Then, the server just*/
/* wait (busy waiting) until the status becomes TAKEN.               */
/*    Note that the server must be started first.  The client can    */
/* only be started as the server says so.  Otherwise, the client may */
/* not be able to use the shared memory of the data therein.         */
/* ----------------------------------------------------------------- */

#include  <stdio.h>
#include  <stdlib.h>
#include  <sys/types.h>
#include  <sys/ipc.h>
#include  <sys/shm.h>

#include  "shm-02.h" //header file where structure is defined

void  main(int  argc, char *argv[])
{
     key_t          ShmKEY; //shared memory key variale
     int            ShmID; // shared memory id 
     struct Memory  *ShmPTR; //pointer to the structure memory defined in shm-02.h
     
     if (argc != 5) { //check for the CLA count 
          printf("Use: %s #1 #2 #3 #4\n", argv[0]);
          exit(1);
     }
     
     //generating key using ftok
     ShmKEY = ftok(".", 'x');
     printf("Shmkey %d",ShmKEY);

     //creating shared memory 
     ShmID = shmget(ShmKEY, sizeof(struct Memory), IPC_CREAT | 0666);
     if (ShmID < 0) {
          printf("*** shmget error (server) ***\n");
          exit(1);
     }
     


     printf("Server has received a shared memory of four integers...\n");
     //server process gets attached to the shared memory
     ShmPTR = (struct Memory *) shmat(ShmID, NULL, 0);
     if ((int) ShmPTR == -1) {
          printf("*** shmat error (server) ***\n");
          exit(1);
     }
     printf("Server has attached the shared memory...\n");
     //makes the status as NOT READY as not data is written to memory  by server process
     ShmPTR->status  = NOT_READY;
     ShmPTR->data[0] = atoi(argv[1]);
     ShmPTR->data[1] = atoi(argv[2]);
     ShmPTR->data[2] = atoi(argv[3]);
     ShmPTR->data[3] = atoi(argv[4]);
     printf("Server has filled %d %d %d %d to shared memory...\n",
            ShmPTR->data[0], ShmPTR->data[1], 
            ShmPTR->data[2], ShmPTR->data[3]);
     //server process changes the status to FILLED as data it has read from CLA and written
     ShmPTR->status = FILLED;
     
     printf("Please start the client in another window...\n");
     //waits fro the client to change the state to "TAKEN" until server process sleeps
     while (ShmPTR->status != TAKEN)
          sleep(1);
          
     printf("Server has detected the completion of its child...\n");
     //server process detachs from the shared memory once the child reads the data from the memory
     shmdt((void *) ShmPTR);
     printf("Server has detached its shared memory...\n");
     //the memory is removed 
     shmctl(ShmID, IPC_RMID, NULL);
     printf("Server has removed its shared memory...\n");
     printf("Server exits...\n");
     exit(0);
}
