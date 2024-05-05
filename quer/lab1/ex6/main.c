#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/*
	Write a C program that receives two integer values on the command line,
	h and n, and it generates a process tree of height h and degree n.
	
	For example, if h=3 and n=2:
	- the primary process creates two processes and exits
	- each one of these two processes creates two other processes and exit
	- each one of these four processes creates two other processes and exit
	at this point, eight processes run on the tree leaf, and the program
	stops.
	
	More in detail, each node of the tree is a process.
	The initial process generates n child jobs and exits.
	All child processes must do the same thing, causing a number of
	processes on the tree leaves equal to n^h.
	Processes on the leaves must all display their own PID and end.
*/

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <h> <n>\n", argv[0]);
        return 1;
    }

    int h = atoi(argv[1]); 
    int n = atoi(argv[2]); 

    printf("h = %d\n", h);
    printf("n = %d\n", n);

    return 0;
}