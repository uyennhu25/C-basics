#include <stdio.h>
#include <stdlib.h>

int main()
{
    float width, length, perimeter, area;
    printf("Chieu rong la: ");
    scanf("%f", &width);
    printf("Chieu dai la: ");
    scanf("%f", &length);

    perimeter = 2*(width+length);
    area = width * length;

    printf("Chu vi cua hinh chu nhat co chieu rong %g va chieu dai %g la %g\n", width, length, perimeter);
    printf("Dien tich cua hinh chu nhat co chieu rong %g va chieu dai %g la %g", width, length, area);
}
