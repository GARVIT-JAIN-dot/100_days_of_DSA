/* Problem: Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s

Output:
- Print YES if palindrome, otherwise NO

Example:
Input:
level

Output:
YES

Explanation: String reads same forwards and backwards */

#include<stdio.h>
#include<string.h>

int main (){
     char string[100];
     printf("Enter a lowercase string (no spaces):");
     scanf("%s",string);
   

     int left = 0;
     int right = strlen(string) - 1;
     int ispalindrome = 1;
     

     while (left < right) {
       if (string[left] != string[right]){
             ispalindrome = 0;
             break;
       }
        left++;
        right--;
     }

     if (ispalindrome) {
         printf("YES,This string is a palindrome.\n");
     } else {
         printf("NO,This string is not a palindrome.\n");
     }

    return 0;
}