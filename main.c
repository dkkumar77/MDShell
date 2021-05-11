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
void append_history(char **, int argc, FILE * pointer);
void append_errors(char * sequence [], int code, FILE * file);

int main(int argc, char * argv[]) {

    /* _________________________________________________________________________________ */
    const char HISTORY_PATH = "/shellhistory";
    int status_code;
    FILE *hist_file;
    char directory_buffer[100];
    char * final = getcwd(directory_buffer, sizeof(directory_buffer));
    char * buff = malloc(sizeof(final)+sizeof(HISTORY_PATH));
    strcpy(buff,final);
    strcat(buff, HISTORY_PATH);
    /* _________________________________________________________________________________ */

    hist_file = fopen(buff,"a");
    if(hist_file == NULL){
        perror("input stream error");
    }
    append_history(argv, argc, hist_file);
        /**
         * If status_code becomes 0, break out of for loop and call system exit with exit code zero.
         */
        if(argc != 0){
        }

        fclose(hist_file);

        free(buff);

    exit(0);
}

void append_history(char * sequence [], int arg_count, FILE * fpointer){
    for(int i = 0 ; i < arg_count; i++) {
        fprintf(fpointer, "%s ", sequence[i]);
    }
    fprintf(fpointer, "\n");
}
void append_errors(char * sequence [], int code, FILE * fpointer){
    fprintf(fpointer, "ERROR:\n\n '%s' exited with code %d", sequence, code);


}
