/*
 * Rosalind Bioinformatics Stronghold Problem 4
 * Return the number of rabbits in a population given 2 parameters
 *
 * INPUT: 2 integers:
 * - k<6 number of rabbits produced by a mature couple of rabbits
 * - n<41 number of generations to compute
*/

#include <stdio.h>
#include <stdlib.h>

/* gigahyper big numbers */
unsigned long long int rabbits ( int n, int k, int m, int death);

int main( int argc, char *argv[])
{
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    int m = atoi(argv[3]);

    /* If the wrong number of argument is present exit */
    if ( argc != 4 )
    {
        printf("Usage %s <n> <k> <m>\n", argv[0] );
        exit(1);
    }

    /* Print the result */
    printf("rabbits at generation %i: %llu\n", n, rabbits( n, k, m, 0));
    return 0;
}

unsigned long long int rabbits ( int n, int k, int m, int death)
{
    /* Recursion */
    if ( n > 2 ) {
        unsigned long long int prevGen;
        unsigned long long int prevPrevGen;
        unsigned long long int deathGen;

        prevGen = rabbits(n-1, k, m, 0);
        prevPrevGen = rabbits(n-2, k, m, 0);
        deathGen = rabbits(n-(m+1), k, m, 1);

        //return(prevGen + k * prevPrevGen - deathGen);
        return(prevGen + prevPrevGen - deathGen);
    }
    else if ( n == 1 || n == 2 ) {
        return(1);
    }
    /* we gotta go deeper than the generation 1 to find the first couple *
     * dead rabbits                                                      */
    else if ( (n == 0 || n == -2) && death ) {
        return(1);
    }
    else {
        return (0);
    }
}
