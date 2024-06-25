#include <stdio.h>
#include <stdlib.h>

#define YEARS 5
#define MONTHS 12

int prime(int i, int primeArr[], int primeCount);

int main() {
    int myArr[5] = {1, 3, 5, 7, 9};

    //Bai 1
    printf("Lab 7.1\n");
    int sizeOfArr= (int)(sizeof(myArr)/sizeof(myArr[0]));
    for (int i = 0; i < sizeOfArr; i++) {
        printf("%d", myArr[i]);
    }

    //Bai 2
    printf("\nLab 7.2\n");
    for (int i = sizeOfArr - 1; i > -1; i--) {
        printf("%d", myArr[i]);
    }

    //Bai 3
    printf("\nLab 7.3\n");
    int primeArr[50] = {2,3};
    int primeCount = 2;

    for (int i = 4; i<= 100; i++) {
        if (prime(i, primeArr, primeCount)==1) {
                primeArr[primeCount] = i;
                primeCount++;
        }
    }
    for (int i = 0; i < primeCount; i++) {
        printf("%d, ", primeArr[i]);
    }

    //Bai 4
    double rain[YEARS][MONTHS] = {
        {4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
        {8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3},
        {9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4},
        {7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2},
        {7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2}
    };

    int year, month;
    double subtot, total = 0.0;

    printf("\nYearly Totals:\n");
    for (year = 0; year < YEARS; year++) {
        subtot = 0.0;
        for (month = 0; month < MONTHS; month++) {
            subtot += rain[year][month];
        }
        printf("%5d \t%15.1f\n", 2010 + year, subtot);
        total += subtot;
    }

    printf("\nMonthly Averages:\n");
    for (month = 0; month < MONTHS; month++) {
        subtot = 0.0;
        for (year = 0; year < YEARS; year++) {
            subtot += rain[year][month];
        }
        printf("%4.1f ", subtot / YEARS);
    }
    printf("\nTotal Rainfall: %.1f\n", total);


    //Bai 5
    printf("\nLab 7.5\nNhap so luong phan tu: ");
    int n;
    scanf("%d", &n);
    while (n <= 0) {
        printf("So luong phan tu phai la so duong: ");
        scanf("%d", &n);
    }
    int a[n];
    for (int i = 0; i<n ; i++) {
        printf("Moi nhap phan tu so %d cua day so: ", i + 1);
        scanf("%d", &a[i]);
    }

    //Draw an algorithm visualizer for this -> recode for lab + use pointers
    int temp;
    for (int i = 0; i<n-1 ; i++) {
        for (int j = i+1; j<n ; j++) {
            if (a[i] < a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("Thu tu giam dan: ");
    for (int i = 0; i<n ; i++) {
        printf("%d, ", a[i]);
    }

    printf("\nThu tu tang dan: ");
    for (int i = n - 1 ; i>-1 ; i--) {
        printf("%d, ", a[i]);
    }
    return 0;

}

int prime(int i, int primeArr[], int primeCount) {
    for (int a = 0; a < primeCount; a++) {
        if (i % primeArr[a]==0) {
            return 0;
        }
    }
    return 1;
}