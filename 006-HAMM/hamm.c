/*
 * Rosalind Bioinformatics Stronghold Problem 2
 * Convert a DNA sequence to the analog RNA sequence
 *
 * INPUT:  string of nucleotides <1000 characters long
 * OUTPUT: string of nucleotides with 'T' replaced with 'U'
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 1000

int main( int argc, char *argv[])
{
    /* only the file name with the input string should be present as argument */
    if ( argc != 2 )
    {
        printf( "Usage: %s <FILENAME>\n", argv[0] );
        exit(1);
    }

    /* Open the file specified as the only argument on read-only mode */
    FILE *file;
    file = fopen( argv[1], "r" );

    char seq1[BUFFER], seq2[BUFFER];

    /* If the file is not valid or empty? Return error */
    if ( file == NULL )
    {
        printf( "Could not open file/n" );
        exit(1);
    }

    fgets(seq1, BUFFER, file);
    fgets(seq2, BUFFER, file);

    fclose( file );

    int len = strlen(seq1);
    int count;
    for (int i=1; i < len; i++)
    {
        /* Check for different nucleotides */
        if ( seq1[i] != seq2[i] ) {
            count++;
        }
    }
    printf( "%i\n", count );

    return 0;
}
