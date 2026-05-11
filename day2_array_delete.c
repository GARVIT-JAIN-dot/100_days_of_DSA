/* Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer pos (1-based position to delete)

Output:
- Print the updated array with (n-1) elements, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
10 30 40 50

Explanation: Delete position 2 (element 20), remaining elements shift left */
#include<stdio.h>

int main () {

    int n;
    printf("Enter the size of array:");
    scanf( "%d" ,&n );

    int arr[n];
    printf( "Enter %d numbers:" ,n );

    for( int i = 0; i < n; i++ ) {
        scanf( "%d" ,&arr[i] );
    }

    int pos;
    printf( "Enter the index position in array to delete element:" );
    scanf( "%d" ,&pos );
     
    pos=pos-1;

    if( pos < 0 || pos >= n ){
        printf( "invalid index!\n" );
        return -1;
    }

    arr[n-1];

    for ( int i = pos; i < n-1; i++ ){
        arr[i]=arr[i+1];
        
    }

    printf("New array is:");

    for( int i = 0; i < n-1; i++ ) {
        printf( "%d " ,arr[i] );
    }

    return 0;

}