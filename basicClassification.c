#include <stdio.h>


int isPrime(int num){

    if(num<=1) {
        return 0; //Means false
    }
    if(num%2 == 0 || num%3 == 0) {
        return 0;
    }
    else if (num <= 3) {
        return 1; //Means true
    }
    else if (num%2 == 0 || num%3 == 0) {
        return 0;
    }

    int i = 5;
    while(i*i <= num) {
        if(num%i == 0 || num%(i+2) == 0) {
            return 0;
        }
        i+=6;
    }
   
    return 1;
}

int isStrong(int num){
    int origin=num;
    int factorial[] = {1,1,2,6,24,120,720,5040,40320,362880};

    while(num>0){
        origin -= factorial[num%10];
        if(origin<0){return 0;}
        num = num/10;
    }
    if(origin>0){
        return 0;
    }
    
    return 1;
}