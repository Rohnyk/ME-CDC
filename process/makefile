processes=process1 process2 process3 process4 process5 process6 zombie_process7

all: process1 process2 process3 process4 process5 process6 zombie_process7  

process1:
	$(CC) -o process1 process1.c -I.
	./process1

process2:
	$(CC) -o process2 process2.c -I.
	./process2		

process3:
	$(CC) -o process3 process3.c -I.
	./process3

process4:
	$(CC) -o process4 process4.c -I.
	./process4

process5:
	$(CC) -o process5 process5.c -I.
	./process5

process6:
	$(CC) -o process6 process6.c -I.
	./process6

zombie_process7:
	$(CC) -o zombie_process7 zombie_process7.c -I.
	./zombie_process7

process_combine: process4  process2
	./process2

cleanex:
	$(RM) $(processes)