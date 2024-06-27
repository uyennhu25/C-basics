#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int arr[10] = {5, 3, 9 ,1, 2, 10, 7, 4, 6, 8};
    int temp;

    //the normal way apparently
    for (int i = 0; i < 10; i++) {
        for(int y = i + 1; y < 10; y++) {
            if (arr[i] > arr[y]) {
                temp = arr[i];
                arr[i] = arr[y];
                arr[y] = temp;
            }
        }
    }
    for(int i = 0; i < 10; i++) {
        printf("%d,", arr[i]);
    }

    int arr1[10] = {5, 3, 9 ,1, 2, 10, 7, 4, 6, 8};
    int *ptr = arr1;
    //the pointer way, no diff honestly;
    for (int i = 0; i < 10; i++) {
        for(int y = i + 1; y < 10; y++) {
            if (*(ptr + i) > *(ptr + y)) {
                temp = *(ptr + i);
                *(ptr + i) = *(ptr + y);
                *(ptr + y) = temp;
            }
        }
    }
    for(int i = 0; i < 10; i++) {
        printf("%d, ", *(ptr + i));
    }

    char big[] = "school";
    char small[] = "ool";
    if (strstr(big, small) != NULL) {
        printf("day la chuoi con");
    }
}