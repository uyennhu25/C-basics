#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, y;
    printf("Nhap 1 so nguyen bat ki: " );
    scanf("%d", &x);

    //Bai 1
    printf("Lab 4.1\nBit thu 3 la bit %d.\n\n", (x>>2)&1);

    //Bai 2
    printf("Lab 4.2\nGia tri cua %d khi bit so 5 dat thanh 1 la %d.\n\n", x, x|(1<<4));

    //Bai 3
    printf("Lab 4.3\nSo nam: %d\nSo tuan:%d \nSo ngay: %d\n\n", x/365, (x%365)/7, (x%365%7));

    //Bai 4
    printf("Lab 4.4\n%d phut tuong duong voi %d ngay hay %d nam.\n", x, (x/60/24), (x/60/24/365));

    //Bai 5
    printf("Lab 4.5\nGia tri byte cua char: %llu, int: %llu, long: %llu, long long: %llu, float: %llu, double: %llu.\n\n", sizeof(char), sizeof(int), sizeof(long), sizeof(long long), sizeof(float), sizeof(double));

    //Bai 6
    int a, b;
    printf("Lab 4.6\na = "); scanf("%d", &a);
    printf("b = "); scanf("%d", &b);
    printf("%d chia %d = %f.\n\n", a, b, (double)a/(double)b);

    //Bai 7
    float mot, hai, ba, bon;
    printf("Lab 4.7\n");
    scanf("%f", &mot);
    scanf("%f", &hai);
    scanf("%f", &ba);
    scanf("%f", &bon);
    printf("Trung binh cong cua %f, %f, %f va %f la %f.\n\n", mot, hai, ba, bon, (mot + hai + ba + bon)/4);

    //Bai 8
    printf("Lab 4.8\n");
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &a);
    scanf("%d", &b);
    printf("Binh phuong cua %d la %d, cua %d la %d, cua %d la %d, cua %d la %d", x, x*x, y, y*y, a, a*a, b, b*b);

    //Bai 9
    printf("Lab 4.9\n");
    unsigned int id, work_hours, hourly_wage;
    printf("ID nhan vien: ");
    scanf("%u", &id);
    printf("So gio lam viec: ");
    scanf("%u", &work_hours);
    printf("Tien luong moi gio: ");
    scanf("%u", &hourly_wage);
    printf("Tien luong thang cua nhan vien #%u la %u", id, work_hours*hourly_wage);

    return 0;
}