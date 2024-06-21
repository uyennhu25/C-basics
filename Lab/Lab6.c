#include <stdio.h>
#include <stdlib.h>

int main() {
    //Bai 1
    int x;
    printf("Lab 6.1\nNhap mot so tu nhien: ");
    scanf("%d", &x);
    for (int y=1; y<x;y++) {
        if (y%2==0) {
            printf("%d\n", y);
        }
    }

    //Bai 2
    int a, b;
    a = 25;
    b = 0;

    printf("Lab 6.2\nSo can doan co 2 chu so");
    scanf("%d", &b);
    while (a != b) {
        printf("Chua chinh xac!");
        scanf("%d", &b);
    }
    printf("Xin chuc mung, ban da doan dung!");
    return 0;

}