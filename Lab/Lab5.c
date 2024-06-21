#include <stdio.h>
#include <stdlib.h>

#define PAYRATE 12.00
#define TAXRATE_300 0.15
#define TAXRATE_450 0.20
#define TAXRATE_REST 0.25
#define OVERTIME 40

int main() {
    //Bai 1
    float sothunhat, sothuhai;
    printf("Lab 5.1\nNhap so thu nhat va so thu hai\n");
    scanf("%f %f", &sothunhat, &sothuhai);

    if ((sothunhat != (int)sothunhat) || (sothuhai != (int)sothuhai)) {
        printf("So nhap vao khong phai so nguyen. \n");
    } else {
        if (sothuhai == sothunhat) {
            printf("So thu nhat bang so thu hai.");
        } else if (sothuhai < sothunhat) {
            printf("So thu nhat lon hon so thu hai.");
        } else {
            printf("So thu nhat be hon so thu hai.");
        }
    }

    //Bai 2
    int a;
    printf("\n\nLab 5.2\nNhap mot so bat ki: ");
    scanf("%d", &a);
    if ((a%2) == 0){
        printf("%d la so chan.", a);
    } else {
        printf("%d la so le.", a);
    }

    //Bai 3
    int temp;
    printf("\n\nLab 5.3\nNhiet do hom nay la: ");
    scanf("%d",&temp);
    if (temp<0) {
        printf("Thoi tiet lanh cong");
    } else if (temp<10) {
        printf("Thoi tiet rat lanh");
    } else if (temp<20) {
        printf("Thoi tiet lanh");
    } else if (temp<30){
        printf("Thoi tiet tuyet voi");
    } else if (temp<40) {
        printf("Thoi tiet nong");
    } else {
        printf("Thoi tiet rat nong");
    }

    //Bai 4
    unsigned int hours = 0;
    double grossPay = 0.0;
    double taxes = 0.0;
    double netPay = 0.0;
    printf("\n\nLab 5.4\nTotal hours worked: ");
    scanf("%u", &hours);

    if (hours <=40) {
        grossPay = hours * PAYRATE;
    }
    else {
        grossPay= 40 * PAYRATE;
        double overTimePay = (hours - 40) * (PAYRATE * 1.5); 
        grossPay+= overTimePay;
    }

    if (grossPay <= 300) {
        taxes = grossPay * TAXRATE_300;
    }
    else if(grossPay > 300 && grossPay <= 450) {
        taxes = 300* TAXRATE_300;
        taxes += (grossPay - 300) * TAXRATE_450;
    }
    else if (grossPay > 450) {
        taxes = 300 * TAXRATE_300;
        taxes += 150 * TAXRATE_450;
        taxes += (grossPay - 450) * TAXRATE_REST;
    } 

    netPay = grossPay - taxes;
    
    printf("Your gross pay this week is: %.2f\n", grossPay);
    printf("Your taxes this week is: %.2f\n", taxes);
    printf("Your net pay this week is: %.2f\n", netPay);

    return 0;
}