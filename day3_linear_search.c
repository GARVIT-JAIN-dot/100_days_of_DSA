/* Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

Input:
- First line: integer n (array size)
- Second line: n space-separated integers
- Third line: integer k (key to search)

Output:
- Line 1: "Found at index i" OR "Not Found"
Line 2: "Comparisons = c"

Example:
Input:
5
10 20 30 40 50
30

Output:
Found at index 2
Comparisons = 3

Explanation: Compared with 10, 20, 30 (found at index 2 with 3 comparisons)  */

#include<stdio.h>
int main () {
  int n;
  printf( "Enter the size of array:" );
  scanf( "%d" ,&n );

  int arr[n];
  printf( "Enter %d numbers:" ,n );

  for( int i = 0; i < n; i++ ) {
    scanf( "%d" ,&arr[i] );
   }
   

   int comparisons=0,k,a = -1;
   printf("Enter the element to search:");
   scanf("%d",&k);

   for(int i = 0; i < n; i++ ) {
    comparisons ++;

      if( arr[i] == k ){
        a = i;
        break;
      } 
   }
   
   if ( a == -1 )
    {
         printf( "Not found\ncomparisons = %d" ,comparisons );
    } 
   else 
    {
         printf( "key found at input:%d\ncomparisons = %d" ,a,comparisons );
    }
  
   return 0;
}