#include "sign_utils.h"
#include <limits.h>
#include <stdio.h>

struct SignBit {
    int unused : 31; 
    int sign : 1;    
};

int getNumber()
{
    int n;
    while (1) {
        printf("Enter the number: ");
        if (scanf_s("%d", &n) != 0) {
            if ((getchar()) != '\n' || n > INT_MAX || n < INT_MIN) {
                printf("Error: enter the number!\n");
                while ((getchar()) != '\n')
                    continue;
            }
            else {
                break;
            }
        }
        else {
            printf("Error: enter the number!\n");
            while ((getchar()) != '\n')
                continue;
        }
    }
    return n;
}

int getSign(int num) {
    struct SignBit* s = (struct SignBit*)&num;
    return s->sign;
}