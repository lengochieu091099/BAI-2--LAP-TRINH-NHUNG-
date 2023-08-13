#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "kiemtranguyento.h"
 
int main(int argc, char *argv[]) {
  if (argc != 3) {
        printf("Please enter arguments:");
        return 1;
    }
  int num1 = atoi(argv[1]);
  int num2 = atoi(argv[2]); 
  int b = pow(10,9);
  if(num1<1 || num1>num2 || num2>b){
    printf("Your argument entered is incorrect. Please re-enter the argument:\n");
    return 1;
  }
  printf("Prime numbers in the range from %d to %d :\n ",num1,num2);
    for(int i=num1; i<=num2 ;i++){
        if(ktnguyento(i)){
            printf("%d  ",i);
        }
 }
}