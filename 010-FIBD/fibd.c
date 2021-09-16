/*
 * Rosalind Bioinformatics Stronghold Problem 4
 * Return the number of rabbits in a population given 2 parameters
 *
 * INPUT: 2 integers:
 * - k<6 number of rabbits produced by a mature couple of rabbits
 * - n<41 number of generations to compute
 *
 * This code doesn't work because it's too slow, each time the function
 * runs the function is called recursively 3 times, for a huge number of 
 * executions
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_GEN 100

/* gigahyper big numbers */
//unsigned long long int rabbits ( int n, int k, int m, int death);

int main( int argc, char *argv[])
{
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    unsigned long long int rabbits[MAX_GEN];
    rabbits[0] = 1;
    rabbits[1] = 1;

    /* If the wrong number of argument is present exit */
    if ( argc != 3 )
    {
        printf("Usage %s <n> <k> <m>\n", argv[0] );
        exit(1);
    }

    for (int i = 2; i < n; i++) {
        if ( (i-(m+1)) >= 0) {
            rabbits[i] = rabbits[i-1] + rabbits[i-2] - rabbits[(i-(m+1))];
        } else if ( (i-(m+1)) == -3 || (i-(m+1)) == -1) {
            rabbits[i] = rabbits[i-1] + rabbits[i-2] - 1;
        } else {
            rabbits[i] = rabbits[i-1] + rabbits[i-2];
        }
    }

    /* Print the result */
    for (int i=0; i<n; i++) {
    printf("rabbits at generation %i: %llu\n", i+1, rabbits[i]);
    }
    //printf("rabbits at generation %i: %llu\n", n, rabbits[n-1]);
    return 0;

}

