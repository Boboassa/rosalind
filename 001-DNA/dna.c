/*
 * Rosalind Bioinformatics Stronghold Problem 1
 * Count the number of nucleotides in a sequence <1000 characters long
 *
 * INPUT:  string of nucleotides <1000 characters long
 * OUTPUT: four integers corresponding each to the number of appearances of
 *         A, C,G, and T, e.g. "20 34 93 22"
*/

#include <stdio.h>
#include <string.h>
int main( int argc, char *argv[])
{
    /* Declare variables, named list for each base */
    struct { int A; int C; int G; int T; } nucleotides[] = { 0, 0, 0, 0 };
    char n;
    /* only the file name with the input string should be present as argument */
    if ( argc != 2 )
    {
        printf( "Usage: %s <FILENAME>\n", argv[0] );
    }
    else
    {
        /* Open the file specified as the only argument on read-only mode */
        FILE *file = fopen( argv[1], "r" );
        /* If the file is not valid or empty? Return error */
        if ( file == 0 )
        {
            printf( "Could not open file/n" );
        }
        else
        {
            while ( ( n = fgetc( file ) ) != EOF )
            {
                /* Count the actual nucleotides */
                    if ( n == 'A' )
                    {
                        nucleotides->A += 1;
                    }
                    if ( n == 'C' )
                    {
                        nucleotides->C += 1;
                    }
                    if ( n == 'G' )
                    {
                        nucleotides->G += 1;
                    }
                    if ( n == 'T' )
                    {
                        nucleotides->T += 1;
                    }
                //printf( "%c", n );
            }
            fclose( file );
            printf( "%i %i %i %i\n", nucleotides->A, nucleotides->C, nucleotides->G, nucleotides->T);
        }
    }
    return 0;
}
