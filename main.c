#include <stdio.h>
#include "NumClass.h"



int main(){

    

    int n, m, small, big;
    printf("enter first number\n");
    scanf("%d", &n);
    printf("enter second number\n");
    scanf("%d", &m);

    if(n>m){
        int tmp = n;
        n = m;
        m = tmp;
    }
    

    small = n;
    big = m;
    printf("The Armstrong numbers are:");
    while (small <= big){
        if(isArmstrong(small)){
            printf(" %d", small);
        }
        small++;
    }
    
    small = n;
    printf("\nThe Palindromes are:");
    while(small<big){
        if(isPalindrome(small)){
            printf(" %d", small);
        }
        small++;
    }
   
    small = n;
    printf("\nThe Prime numbers are:");
    while (small <= big){
        if(isPrime(small)){
            printf(" %d", small);
        }
        small++;
    }

    small = n;
    printf("\nThe Strong numbers are:");
    while (small <= big){
        if(isStrong(small)){
            printf(" %d", small);
        }
        small++;
    }

    printf("\n");

    return 0;
}