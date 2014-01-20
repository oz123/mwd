#include <stdio.h>
#include <math.h>
/*
 * write a program to create an array of 100 integers, 
 * and then fill the array with the squares (so the 
 * the_array[7] will hold 49. Then, print a message like
 * "7 squared is 49" for each element of the array */

int main(void){
    int the_array[100];
    int i;
    for (i=0; i<100; i++) {
        the_array[i] = pow(i,2);
        printf( "%i squared is %i\n" ,i, the_array[i] );
        }
    
    return 0;
}
