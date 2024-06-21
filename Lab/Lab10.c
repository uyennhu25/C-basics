#include <stdio.h>
#include <stdlib.h>

int main() {
    //Lab 10.1
    int a = 1;
    float b = 2.0;
    char c = '3';

    int *pInt = &a;
    float *pFloat = &b;
    char *pChar = &c;

    printf("%p\n %p\n %p\n", pInt, pFloat, pChar);
    printf("%d\n %f\n %c\n", *pInt, *pFloat, *pChar);

    //Lab 10.2
    int *ptr = (int *)&a;
    *ptr = 5;
    printf("\n%d", a);

    //Lab 10.3
    int num1, num2;
    int *pnum1 = &num1;
    int *pnum2 = &num2;

    scanf("%d", pnum1);
    scanf("%d", pnum2);

    if (*pnum1 > *pnum2) {
        printf("So %d lon nhat trong 2 so", *pnum1);
    }
    else if (*pnum1 < *pnum2) {
        printf("So %d lon nhat trong 2 so", *pnum2);
    } 
    else {
        printf("Hai so bang nhau");
    }

    printf("Tong cua hai so la: %d\n", (*pnum1) + (*pnum2));
    
    int temp = *pnum1;
    *pnum1 = *pnum2;
    *pnum2 = temp;
    printf("Hai so sau khi hoan doi la %d va %d", *pnum1, *pnum2);

    return 0;

}