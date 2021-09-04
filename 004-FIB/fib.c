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
unsigned long long int rabbits ( int n, int k);

int main( int argc, char *argv[])
{
    /* Argument 1 (n) must be an integer */
    char *a = argv[1];
    int n = atoi(a);

    /* Same as argument 1 for k */
    a = argv[2];
    int k = atoi(a) ;

    /* If the wrong number of argument is present exit */
    if ( argc != 3 )
    {
        printf("Usage %s <n> <k>\n", argv[0] );
        exit(EXIT_FAILURE);
    }

    /* Print the result */
    printf("rabbits at generation %i: %llu\n", n, rabbits( n, k));
    return 0;
}

unsigned long long int rabbits ( int n, int k)
{
    /* Recursion */
    if ( n > 2 )
    {
        return( n-1, k, rabbits( n-1, k) + k * rabbits( n-2, k ));
    }

    /* The first 2 generations */
    else if ( n == 1 || n == 2 )
    {
        return( 1 );
    }
    //else if ( n == 0 )
    //{
    //    return( 0 );
    //}

    /* Error if n is a different number */
    else
    {
        printf("Error: wrong number of generations\n");
        exit(EXIT_FAILURE);
    }
}
