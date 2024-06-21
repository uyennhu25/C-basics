#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXLENGTH 100

void chuoiNguoc();
bool cmpString(const char s1[], const char s2[]);
int max();
void searchString(int *x, int *y);
void swapString(int *x, int *z);
int add(int *pnum1, int *pnum2);
void swapNum(int *pnum1, int *pnum2);
void findFact(int n, int *f);
void JsonExtract(char json[], char hoten[], char gioitinh[], char sdt[], char email[]);
char *multi_tok(char *input, char *delimiter);

int main() {
    chuoiNguoc();
    printf("\n%d\n", cmpString("hoang", "hoang"));
    printf("\nMax: %d", max());

    int x[6] = {1,2,3,4,5,6};
    int y = 5;
    int *pX = &x[0];
    int *pY = &y;
    searchString(pX, pY);

    int z[3] = {10,11,12};
    int *pZ = &z[0];
    swapString(pX, pZ);

    int a = 3, b =4;
    int *pnum1 = &a;
    int *pnum2 = &b;
    printf("\n%d + %d = %d", *pnum1, *pnum2, add(pnum1, pnum2));

    swapNum(pnum1, pnum2);

    int n = 4;
    int result;
    int *f = &result;
    findFact(n, f);

    char JSON[] = "[\
{\"hoten\":\"Le Thi My Duyen\",\"gioitinh\":\"nu\",\"sodienthoai\":\"0935777888\",\"email\":\"duyen86@gmail.com\"},\
{\"hoten\":\"Tran Trung Thanh\",\"gioitinh\":\"nam\",\"sodienthoai\":\"0976333444\",\"email\":\"thanhtt98.com\"},\
{\"hoten\":\"Huynh Anh Hoang\",\"gioitinh\":\"nu\",\"sodienthoai\":\"0939745220\",\"email\":\"hahoang88@gmail.com\"},\
{\"hoten\":\"Nguyen Minh Khoi\",\"gioitinh\":\"nam\",\"sodienthoai\":\"0703666777\",\"email\":\"khoimaster@gmail.com\"}]";
    char hoten[MAXLENGTH], gioitinh[MAXLENGTH], sdt[MAXLENGTH], email[MAXLENGTH];

    /*JsonExtract(JSON, hoten, gioitinh, sdt, email);

    printf("\nThong tin cua doi tuong JSON: \n");
    printf("Ho ten:        %s\n", hoten);
    printf("Gioi tinh:     %s\n", gioitinh);
    printf("So dien thoai: %s\n", sdt);
    printf("Email:         %s\n", email);*/

    char khachhang[MAXLENGTH];
    char hoten_nam[10][MAXLENGTH];
    int s1_nam = 0;
    int s1_khachhang = 0;
    int i = 0;

    char* token = multi_tok(JSON, "},{");

    while (token != NULL) {
        strcpy(khachhang,token);
        JsonExtract(khachhang, hoten, gioitinh, sdt, email);
        printf("\nThong tin cua doi tuong JSON: \n");
        printf("Ho ten:        %s\n", hoten);
        printf("Gioi tinh:     %s\n", gioitinh);
        printf("So dien thoai: %s\n", sdt);
        printf("Email:         %s\n", email);
        if (strcmp(gioitinh, "nam") == 0) {
            strcpy(hoten_nam[i], hoten);
            s1_nam++;
            i++;
        }
        s1_khachhang++;
        token = multi_tok(NULL, "},{");
    }

    printf("\nCo tong cong %d khach hang nam / tong so so %d khach hang \n", s1_nam, s1_khachhang);

    if (s1_nam > 0) {
        printf("Ho ten cac khach hang nam: \n");
        for (i = 0; i < s1_nam; ++i) {
            printf("%d. %s\n", i+1, hoten_nam[i]);
        }
    }

    

    return 0;
}

void chuoiNguoc() {
    char str[MAXLENGTH];
    char *pStr = str;
    printf("Nhap chuoi de dao nguoc: ");
    scanf("%s", pStr);

    int i = 0;
    while (*(pStr + i) != '\0') {
        i++;
    }
    i--;
    printf("\nChuoi sau khi dao nguoc: ");
    for (int j = i; j >= 0; j--) {
        printf("%c", *(pStr + j));
    }
}

bool cmpString(const char s1[], const char s2[]) {
    const char *pStr1 = s1;
    const char *pStr2 = s2;

    int i = 0;

    while ( *(pStr1 + i) == *(pStr2 + i) && *(pStr1 + i) != '\0' && *(pStr2 + i) != '\0') {
        ++i;
    }

    if ( *(pStr1 + i) == '\0' && *(pStr2 + i) == '\0') {
        return true;
    }
    return false;
}

int max() {
    int n = 101;
    while (n > MAXLENGTH) {
        printf("So luong phan tu: ");
        scanf("%d", &n);
    }

    int arr[n], *ptr;
    ptr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu so %d: ", i+1);
        scanf("%d", (ptr + i));
    }
    int max = ptr[0];
    for (int i = 1; i < n; i++) {
        if (max < *(ptr + i)) {
            max = *(ptr + i);
        }
    }
    free(ptr);
    return max;
}

void searchString(int *x, int *y) {
    
    int i, f = 0;

    
    for (i = 0; i<5; i++) {
        if (*(x + i) == *y) {
            f = 1;
            break;
        }
        else {
            continue;
        }
    }
    if (f == 1) {
        printf("\nSearch completed.\n");
    }
    else {
        printf("\nSearch failed.\n");
    }
}

void swapString(int *x, int *z) {
    int temp, i;
    for (i = 0;i < 3; i++) {
        temp = *(z+i);
        *(z+i) = *(x+i);
        *(x+i) = temp;
    }
    printf("Array X: ");
    for (i = 0; i < 6; i++) {
        printf("%d, ", *(x+i));
    }
    printf("\nArray Z: ");
    for (i = 0; i < 3; i++) {
        printf("%d, ", *(z+i));
    }
}

int add(int *pnum1, int *pnum2) {
    return (*pnum1 + *pnum2);
}

void swapNum(int *pnum1, int *pnum2) {
    int temp = *pnum1;
    *pnum1 = *pnum2;
    *pnum2 = temp;
    printf("\nSau khi swap, a: %d, b: %d", *pnum1, *pnum2);
}

void findFact(int n, int *f) {
    int i;
    *f = 1;
    for (i = 1; i <= n; i++) {
        *f = *f * i;
    }
    printf("\nKet qua %d! = %d", n, *f);
}

void JsonExtract(char json[], char hoten[], char gioitinh[], char sdt[], char email[]) {
    char info[4][MAXLENGTH];
    int i;

    char* token = strtok(json, ",");
    i = 0;

    while (token != NULL){
        strcpy(info[i], token);
        ++i;
        token = strtok(NULL, ",");
    }

    char *hoten_token = strtok(info[0], ":");
    strcpy(hoten, strtok(NULL, ":\""));

    token = strtok(NULL, ",");
    char *gioitinh_token = strtok(info[1], ":");
    strcpy(gioitinh, strtok(NULL, ":\""));

    token = strtok(NULL, ",");
    char *sdt_token = strtok(info[2], ":");
    strcpy(sdt, strtok(NULL, ":\""));

    token = strtok(NULL, ",");
    char *email_token = strtok(info[3], ":");
    strcpy(email, strtok(NULL, ":\""));

    if (email[strlen(email)-1] == '}') {
        email[strlen(email)-1] = '\0';
    }
}

char *multi_tok(char *input, char *delimiter) {
    static char *string;
    if (input != NULL) {
        string = input;
    }
    if (string == NULL) {
        return string;
    }

    char *end = strstr(string, delimiter);
    if (end == NULL) {
        char *temp = string;
        string = NULL;
        return temp;
    }

    char *temp = string;

    *end = '\0';
    string = end + strlen(delimiter);
    return temp;
}

