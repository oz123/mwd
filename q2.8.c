#include <stdio.h>
#include <math.h>

int triangular(int);
void find_triplet(int in, int out[]);
int find_next_triangular(int in);

/*
 Fermat's polygonal number theorem:
 any natural number can be expressed as the sum of at
 most three triangular numbers. 
 */
int main(void){
    int arr[] = {0,0,0};
    int i, num1, num2, num3;
    for ( i = 1; i<101; i++){
        find_triplet(i, arr);
        num1 = triangular(arr[0]);
        num2 = triangular(arr[1]);
        num3 = triangular(arr[2]);
        printf("%i = %i + %i + %i\n", i, num1, num2, num3);
    }
return 0;
}

/* return the triangular number of i*/
int triangular(int i){
    int sum = 0;
    while (i){
        sum = sum + i;
        i = i-1;
    }
    return sum;
}

/*
 find the index of the largest 
 triangular number smaller then a given
 integer
 */
int find_next_triangular(int in){
    int idx;
    for (idx = 0; idx < in ; idx++){
        if (triangular(idx) > in)
            break;
    }
    return idx;
}


/*
 find a triplet of triangular numbers
 which sum to a given in number 
*/
void find_triplet(int in, int out[]){
    int big ;
    int i, j, k;

    big = find_next_triangular(in);
    for ( i = 0; i <= big; i++)
        for ( j = 0; j <= i; j++ )
            for ( k = 0; k <= j; k++ ){
                if (triangular(i)+triangular(j)+triangular(k) == in){
                    out[0] = i;
                    out[1] = j;
                    out[2] = k;
                    i = j = k = big;
                    }
                }
}
