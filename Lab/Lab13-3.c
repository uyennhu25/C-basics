#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

int main () {
    FILE *pfile = NULL;
    char *filename = "test.txt";


    int ch;
    int linesCount = 0;


    pfile = fopen(filename, "r");
    if (pfile == NULL) {
    printf("Failed to open %s.'n", filename);
    } else {
        while ((ch = fgetc(pfile)) != EOF) {
            if (ch == '\n') {
                linesCount++;
            }
        }
    }

    printf("Total number of lines are %d\n", ++linesCount);


    fclose(pfile);
    return 0;
}