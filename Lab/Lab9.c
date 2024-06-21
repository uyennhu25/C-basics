#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXLENGTH 20

int stringLength(const char *string);
void mergeString(char *arr, const char *str1, const char *str2);
bool cmpString(const char *str1, const char *str2);
void arrangeString(int n, char *arr);
bool chuoiCon();
void loaiBoKyTu();

int main() {
    char str1[] = "Hello";
    char str2[] = "Hello";
    
    printf("%d %d", stringLength(str1), cmpString(str1, str2));


    int n;
    printf("\nEnter number of strings: ");
    scanf("%d", &n);
    char *arr = malloc(n*MAXLENGTH);
    arrangeString(n, arr);
    chuoiCon();
    loaiBoKyTu();
}

int stringLength(const char *string) {
    int i = 0;
    while (string[i] != '\0') {
        i++;
    }
    return i;
}

void mergeString(char *arr, const char *str1, const char *str2) {
    int a, b;
    for (int a = 0; str1[a] != '\0'; a++) {
        arr[a] = str1[a];
    }

    for (int b = 0; str2[b] != '\0'; b++) {
        arr[a + b] = str2[b];
    }
}

bool cmpString(const char *str1, const char *str2) {
    int i = 0;
    while (str1[i] != '\0' || str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return false;
        }
        i++;
    }
    return true;
}

void arrangeString(int n, char *arr) {
    
    for (int i = 0; i < n; i++) {
        scanf("%19s", arr + i * MAXLENGTH);
    }

    for (int i = 0; i < n -1; i++) {
        for (int j = 0; j < n - i-1; j++) {
            if (strcmp(arr + j * MAXLENGTH, arr + (j + 1) * MAXLENGTH) > 0) {
                char temp[MAXLENGTH];
                strcpy(temp, arr + j * MAXLENGTH);
                strcpy(arr + j * MAXLENGTH, arr + (j + 1) * MAXLENGTH);
                strcpy(arr + (j + 1) * MAXLENGTH, temp);
            }
        }
    }
    for (int i = 0; i< n; i++) {
        printf("%s, ", arr + i*MAXLENGTH);
    }
}

bool chuoiCon(){
    char str1[MAXLENGTH], str2[MAXLENGTH];
    printf("\nEnter first string: ");
    scanf("%s", str1);
    printf("\nEnter first string: ");
    scanf("%s", str2);

    /*int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            printf("Khong phai chuoi con");
            return false;
        }
        i++;
    }
    printf("La chuoi con");
    return true;*/
    char temp[MAXLENGTH];
    if (strlen(str1) < strlen(str2)) {
        strcpy(temp, str1);
        strcpy(str1, str2);
        strcpy(str2,str1);
    }
    int i;
    for (i = 0; i <= strlen(str1) - strlen(str2); i++) {
        if (strncmp(str1 + i, str2, strlen(str2)) == 0) {
            printf("La chuoi con");
            return true;
        }
    }
    printf("Khong phai chuoi con");
    return false;
}

void loaiBoKyTu() {
    int i,j;
    char str[MAXLENGTH];
    printf("\nEnter string: ");
    scanf("%s", str);

    for (i = 0; str[i]!='\0'; ++i) {
        while (!( (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || str[i] == '\0') ) {
            for (j=i; str[j] != '\0'; ++j) {
                str[j] = str[j+1];
            }
            str[j] = '\0';
        }
    }
    printf("%s", str);
}