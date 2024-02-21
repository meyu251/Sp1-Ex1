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


int sumOfArmstrong(int n, int power){
    if (n<10){
        return myPow(n, power);
    }
    return myPow(n%10, power)+sumOfArmstrong(n/10, power);
}


int numLength(int num){
    int length = 1;
    while (num > 9) {
        length++;
        num /= 10;
    }
    return length;
}

int isPalindromeRec(int num, int length){
    if(length == 1){
        return 1;
    }
    if(length == 2){
        if(num%10 == num/10){
            return 1;
        }
        return 0;
    }

    int mod = myPow(10, length-1);

    int right = num % 10;
    int left = num/mod;
    if(right != left){
        return 0;
    }
    
    num = num % mod;
    num = num/10;

    return isPalindromeRec(num, length-2);
}

int isPalindrome(int num){
    int length = numLength(num);
    if(length == 1){
        return 1;
    }
    if(length == 2){
        if(num%10 == num/10){
            return 1;
        }
        return 0;
    }
    
    return isPalindromeRec(num, length);
}



int isArmstrong(int n){
    int length = numLength(n);
    int sum = sumOfArmstrong(n, length);
    return(n==sum);
}