#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void addDistance(distance_t dst1, distance_t dst2);

struct ngaysinh {
    int ngay;
    int thang;
};

struct nhanvien {
    char ten[100];
    int id;
    float luong;
    struct ngaysinh ngaysinh;
}nv1;

typedef struct {
    int feet;
    int inch;
} distance_t;

struct hocsinh {
    char hoten[25];
    int tuoi;
    char diachi[128];
    float gpa;
};

int main () {
    printf("Nhap ten nv: ");
    fgets(nv1.ten, sizeof(nv1.ten), stdin);

    printf("Nhap id nv: ");
    scanf("%d", &nv1.id);

    printf("Nhap luong nv: ");
    scanf("%f", &nv1.luong);

    printf("Ten: %sId: %d\nLuong: %f\n", nv1.ten, nv1.id, nv1.luong);

    scanf("%d", &nv1.ngaysinh.ngay);
    scanf("%d", &nv1.ngaysinh.thang);

    printf("Ngay sinh: %d/%d", nv1.ngaysinh.ngay, nv1.ngaysinh.thang);

    distance_t distance_1 = {12, 13};
    distance_t distance_2 = {16, 27};

    addDistance(distance_1, distance_2);


    int choice;
    int i = 0;
    struct hocsinh hocsinh[30];
    printf("Hay lua chon\n1. Nhap thong tin hoc sinh\n2. Tim kiem hoc sinh\n3. Thoat\n");
    scanf("%d", &choice);
    printf("\n__________________________\n");
    switch (choice)

    {
    case 1:
        printf("Nhap ten hoc sinh: ");
        fgets(hocsinh[i].hoten, sizeof(hocsinh[i].hoten), stdin);

        printf("Nhap tuoi hoc sinh: ");
        scanf("%d", &hocsinh[i].tuoi);

        printf("Nhap dia chi hoc sinh: ");
        fgets(hocsinh[i].diachi, sizeof(hocsinh[i].diachi), stdin);

        printf("Nhap gpa hoc sinh: ");
        scanf("%f", &hocsinh[i].gpa);
        break;
    case 2:
        char search[25];
        scanf("%s", search);
        for (int a = 0; a < i; a++) {
            if (strcmp(hocsinh[i].hoten, search) == 0) {
                printf("Hoc sinh da ton tai!");
            }
            else {
                printf("Khong tim thay hoc sinh.");
            }
        }
        break;
    case 3:
        break;
    default:
        printf("Moi nhap lai lua chon");
        scanf("%d", &choice);
    }
    return 0;
} 

void addDistance(distance_t dst1, distance_t dst2) {
    distance_t sum = {dst1.feet + dst2.feet, dst1.inch + dst2.inch};
    printf("Tong cua hai khoang cach lan luot la: %d, %d\n", sum.feet, sum.inch);
}

