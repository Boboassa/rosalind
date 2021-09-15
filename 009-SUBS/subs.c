/*
 * Finding a motif in a DNA sequence
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

    char seq[MAX_NUCS];
    char sub[MAX_NUCS];
    fgets(seq, MAX_NUCS, f);
    fgets(sub, MAX_NUCS, f);
    fclose(f);

    int seqLen = strlen(seq) - 1;
    int subLen = strlen(sub) - 1;

    printf("seq: %i\nsub: %i\n", seqLen, subLen);

    for (int i=0; i < seqLen; i++)
    //for (int i=0; i < (seqLen - subLen +1); i++)
    {
        for (int j=0; j < (subLen); j++)
        {
            printf("%c %i %c %i\n", seq[i+j], i+j, sub[j], j);
            if (sub[j] != seq[i+j])
            {
                printf("Break\n");
                break;
            }
            else if ((subLen) == j)
            {
                printf("%i ", (i+1));
            }
        }
    }
    printf("\n");

    return 0;
}
