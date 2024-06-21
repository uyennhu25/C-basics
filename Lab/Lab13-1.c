#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

int main () {
    FILE *pfile = NULL;
    char *filename = "test.txt";


    char input[MAX];

    pfile = fopen(filename, "w");
    if (pfile == NULL) {
    printf("Failed to open %s.'n", filename);
    }

    printf("Input file: ");
    scanf("%s", input);
    fprintf(pfile, "%s", input);

    fclose(pfile);
    return 0;
}