/*
 * The dataset is DNA, this program requires an RNA sequence:
 * run the dataset through the DNA to RNA converter first
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* define max length for one sequence */
#define NUCLEOTIDES 10000
#define AMINOACIDS 10000

int main(int argc, char *argv[]) {

    // 3 dimensional array, base order is "UCAG"
    static const char *codons[4][4] = {
        {
            "FFLL",
            "SSSS",
            "YY00",
            "CC0W",
        },
        {
            "LLLL",
            "PPPP",
            "HHQQ",
            "RRRR",
        },
        {
            "IIIM",
            "TTTT",
            "NNKK",
            "SSRR",
        },
        {
            "VVVV",
            "AAAA",
            "DDEE",
            "GGGG",
        }
    };

    /* check number of arguments */
    if (argc != 2) {
        printf("Wrong number of arguments\n");
        exit(1);
    }

    /* check and open file */
    FILE *f;

    f = fopen(argv[1], "r");

    if(f == NULL) {
        printf("Unable to open file\n");
        exit(1);
    }

    char sequence[NUCLEOTIDES];
    char protein[AMINOACIDS];

    fgets(sequence, NUCLEOTIDES, f);

    fclose(f);

    int started = 0;
    while (strlen(sequence) > 2) {
        /* check first codon */
        int index[3];
        for (int i=0; i < 3; i++) {
            switch (sequence[i]) {
                case 'U' :
                    index[i] = 0;
                    break;
                case 'C' :
                    index[i] = 1;
                    break;
                case 'A' :
                    index[i] = 2;
                    break;
                case 'G' :
                    index[i] = 3;
                    break;
                default :
                    break;
            }
        //printf("%i\n", index[i]);
        }
        if (codons[ index[0] ][ index[1] ][ index[2] ] == 'M') {
            started = 1;
        } else if (codons[ index[0] ][ index[1] ][ index[2] ] == '0') {
            started = 0;
        }

        if (started == 1) {
            printf("%c", codons[ index[0] ][ index[1] ][ index[2] ]);
            memmove(sequence, sequence+3, strlen(sequence));
        } else {
            memmove(sequence, sequence+1, strlen(sequence));
        }


        /* Remove first 3 characters of the sequence */
    }


    printf("\n");

    return 0;
}
