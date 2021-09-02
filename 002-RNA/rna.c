/*
 * Rosalind Bioinformatics Stronghold Problem 2
 * Convert a DNA sequence to the analog RNA sequence
 *
 * INPUT:  string of nucleotides <1000 characters long
 * OUTPUT: string of nucleotides with 'T' replaced with 'U'
*/

#include <stdio.h>
#include <string.h>

int main( int argc, char *argv[])
{
    /* Declare variables */
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
                /* Replace nucleotides */
                if ( n == 'T' )
                {
                    n = 'U';
                }
                printf( "%c", n );
            }
            fclose( file );
        }
    }
    return 0;
}
