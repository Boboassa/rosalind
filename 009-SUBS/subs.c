/*
 * Finding a motif in a DNA sequence
 *
 * INPUT: 2 strings:
 *      - Sequence (seq) which is <1000 bases long
 *      - Substring (sub) which is <1000 bases long
 *
 * OUTPUT: a series of integers rapresenting the start of every occurrence of
 * substring in sequence
 *
 * Sample input:
 * ACGATATCTTCATATATGATCAGAGATCAGATCAG
 * ATAT
 *
 * Sample output:
 * 4 11 13
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUCS 1000

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Wrong number of arguments\n");
        exit(1);
    }

    FILE *f;
    f = fopen(argv[1], "r");
    if (f == NULL) {
        printf("Couldn't open file\n");
        exit(1);
    }

    /* Define strings */
    char seq[MAX_NUCS];
    char sub[MAX_NUCS];

    /* Get file strings */
    fgets(seq, MAX_NUCS, f);
    fgets(sub, MAX_NUCS, f);

    fclose(f);

    /* strlen() counts also the \n characters, which are not important here */
    int seqLen = strlen(seq) - 1;
    int subLen = strlen(sub) - 1;

    /* Debug */
    printf("seq: %i\nsub: %i\n", seqLen, subLen);

    /* For every character in the sequence string */
    for (int i=0; i < seqLen; i++)
    //for (int i=0; i < (seqLen - subLen +1); i++)
    {
        /* For every character in the substring */
        for (int j=0; j < (subLen); j++)
        {
            printf("%c %i %c %i\n", seq[i+j], i+j, sub[j], j);       /* Debug */

            /* Check if the characters are equal */
            if (sub[j] != seq[i+j])
            {
                printf("Break\n");
                /* Exit the loop */
                break;
            }
            /* If the characters are all equal including the last one */
            else if ((subLen) == j)
            {
                /* Print the number of the first character of the string */
                printf("%i ", (i+1));
            }
        }
    }
    printf("\n");

    return 0;
}
