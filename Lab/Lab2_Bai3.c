#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ten[32];                               //Tao bien char co kich thuoc 32 phan tu
    printf("What's your name?\n");              //Hien thi cau hoi
    scanf("%s", ten);                           //Nhap du lieu ten tu ban phim
    printf("Hello %s. How are you?", ten);      //Hien thi cau tra loi kem ten

    return 0;
}
