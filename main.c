#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#define MAX_ARGUMENT 5
#define MAX_BUFFER 200

/**
 * Basic shell implementation by Deepak Kumar & Mani Shah
 * May 9th 2021
 */

void parser();
void command_usage();
void append_history();


int main(int argc, char * argv[]) {

    int status_code;


    while(){
        /**
         * If status_code becomes 0, break out of for loop and call system exit with exit code zero.
         */
        if(argc != 0){
        }


    }


    exit(0);

    return 0;
}

