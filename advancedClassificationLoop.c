#include "NumClass.h"
#include <stdio.h>


int myPow(int base, int exponent){
    if(exponent == 0){
        return 1;
    }
    
    int ans = 1;
    int i = 1;
    while(i <= exponent){
        ans *= base;
        i++;
    }
    
    return ans;
}

/*
assuming the number doesn't include 0's at the beginning
*/
int isPalindrome(int num){
    int pal=0;
    int first_num=num;
    
    while(num>0){
        pal*=10;
        pal+=num%10;
        num/=10;
    }

    return (pal==first_num);
}


int isArmstrong(int num){
    int origin = num;
    int length = numLength(origin);
    int check = 0;

    while (num>0){
        int base = num%10;
        check += myPow(base, length);
        num = num/10;
    }

    if (check != origin){
        return 0;
    }
    
    return 1;
}

int numLength(int num){
    int length = 0;
    while (num != 0) {
        length++;
        num /= 10;
    }
    return length;
}