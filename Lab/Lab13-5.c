#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

int renameFile();
int removeFile();

int main () {
    /*FILE *pfile = NULL;
    char *filename = "test.txt";


    pfile = fopen(filename, "w");
    if (pfile == NULL) {
    printf("Failed to open %s.'n", filename);
    }
    fclose(pfile);*/

    printf("%d %d", renameFile(), removeFile());


    return 0;
}

int renameFile() {
    char oldname[MAX], newname[MAX];
    printf("Hay nhap ten file can doi\n");
    scanf("%s", oldname);

    printf("Hay nhap ten moi\n");
    scanf("%s", newname);

    int re = rename(oldname, newname);
    return re;
}
int removeFile() {
    char buffer[MAX];
    printf("Hay nhap ten file can xoa\n");
    scanf("%s", buffer);

    int rem = remove(buffer);
    return rem;
}

