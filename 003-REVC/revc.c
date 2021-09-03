/*
 * Rosalind Bioinformatics Stronghold Problem 3
 * Return the reverse complementary sequence to the one given
 *
 * INPUT:  string of nucleotides <1000 characters long
 * OUTPUT: a string complementary and reversed to the one given, substitutions
 * between A, T and C, G
*/

#include <stdio.h>
#include <stdlib.h>

/* set maximum length constant */
#define BUFFER 1000

int main( int argc, char *argv[])
{
    FILE *f = NULL;

    /* buffer */
    char buffer[BUFFER];

    /* length of the input */
    int length;

    /* check argument number */
    if ( argc != 2 )
    {
        printf( "Usage: %s <FILENAME>\n", argv[0] );
        exit(EXIT_FAILURE);
    }
    /* Open the file specified as the only argument on read-only mode */
    f = fopen( argv[1], "r" );

    /* If the file is not valid or empty? Return error */
    if ( f == 0 )
    {
        printf( "Could not open file/n" );
        exit(EXIT_FAILURE);
    }

    /* read contents of file into buffer */
    length = fread(&buffer, sizeof(char), BUFFER, f);

    /* close file */
    fclose( f );

    /* I don't really understand why I have to subtract 2
     * from length insead of 1 */
    for ( length -= 2; length >= 0; --length ) {
        switch ( buffer[length] )
        {
        case 'A':
            buffer[length] = 'T';
            break;
        case 'C':
            buffer[length] = 'G';
            break;
        case 'G':
            buffer[length] = 'C';
            break;
        case 'T':
            buffer[length] = 'A';
            break;
            /* this doesn't work as a control for rogue characters*/
//        default:
//            printf( "Wrong character found, check input\n" );
//            exit(EXIT_FAILURE);
        }
        printf( "%c", buffer[length] );
    }
        printf( "\n" );
    return 0;
}
