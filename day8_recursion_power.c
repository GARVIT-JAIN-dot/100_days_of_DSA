/* Problem: Given integers a and b, compute a^b using recursion without using pow() function.

Input:
- Two space-separated integers a and b

Output:
- Print a raised to power b

Example:
Input:
2 5

Output:
32

Explanation: 2^5 = 2 * 2 * 2 * 2 * 2 = 32 */

#include<stdio.h>

int power(int a,int b);

int main(){
     int a;
     printf("Enter integer value:");
     scanf("%d",&a);
     int b;
     printf("Enter power of integer:");
     scanf("%d",&b);

     printf("power of %d^%d:%d\n",a,b,power(a,b));
 
     return 0;
}

 int power(int a,int b){
     int value = a;
     if (b == 0) {
        return 1;
     } else {
        return a * power(a,b - 1);
     }
}