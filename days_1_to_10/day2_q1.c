//Delete an element from an array

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