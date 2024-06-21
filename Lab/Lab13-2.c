#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

int main () {
    FILE *pfile = NULL;
    char *filename = "test.txt";


    char search[MAX];

    printf("Search file: ");
    scanf("%s", search);

    pfile = fopen(filename, "r");
    if (pfile == NULL) {
    printf("Failed to open %s.'n", filename);
    } else {
        while (fgets(search, MAX, pfile) != NULL) {
            printf("%s", search);
        }
        fclose(pfile);
    }

    return 0;
}