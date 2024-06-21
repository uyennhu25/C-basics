#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

int main() {
    char file1[MAX], file2[MAX], result[MAX];
    FILE *pf1, *pf2, *pf3;

    pf1 = fopen("file1.txt", "r");
    if (pf1 == NULL) {
        printf("Không thể mở file1.txt.\n");
    }

    pf2 = fopen("file2.txt", "r");
    if (pf2 == NULL) {
        printf("Không thể mở file2.txt.\n");
    }

    //result[0] = '\0';

    while (fgets(file1, MAX, pf1) != NULL) {
        strcat(result, file1);
    }

    while (fgets(file2, MAX, pf2) != NULL) {
        strcat(result, file2);
    }


    pf3 = fopen("output.txt", "w");
    if (pf3 == NULL) {
        printf("Không thể tạo file output.txt.\n");
    }

    fputs(result, pf3);
    fclose(pf1);
    fclose(pf2);
    fclose(pf3);

    return 0;
}
