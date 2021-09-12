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
#include <string.h>

/* define max length for one sequence */
#define BUFFER 1000
/* define max length for one line */
#define LINE 80
/* define maximum strings */
#define MAX 10
/* ideally everything here ^ should be dynamically allocated */

/* every sequence has an ID, a sequence and a GC% content */
typedef struct {
    char id[LINE];
    char nucs[BUFFER];
    float gc;
}sequence;

int main(int argc, char *argv[]) {

    /* define sequences array */
    sequence seqArray[MAX];

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

    /* define temporary file to store the lines */
    char line[LINE];

    /* define a counter for the number of sequences */
    int count;

    /* read one line at a time in the file *
     * end the loop when feof is reached   */
    while (1) {
        fgets(line, LINE, f);
        if (feof(f)) {
            break;
        }
        if (line[0] == '>') {
            count++;
            /* remove first character of line by shifting the memory *
             * by one byte                                           */
            memmove(line, line+1, strlen(line));
            strcpy(seqArray[count-1].id, line);
            //printf("%s", seqArray[count-1].id);
        }
        if (line[0]=='A' | line[0]=='C' | line[0]=='G' | line[0]=='T') {
            strcat(seqArray[count-1].nucs, line);
        }
    }

    fclose(f);

    /* compute CG content */

    /* for each sequence */
    for (int i = 0; i < count; i++) {
        int numgc=0;
        int total=0;

        /* for each character of the string */
        for (int j = 0; j < BUFFER; j++) {
            if (seqArray[i].nucs[j]=='C' | seqArray[i].nucs[j]=='G') {
                numgc++;
                total++;
            } else if (seqArray[i].nucs[j]=='A' | seqArray[i].nucs[j]=='T') {
                total++;
            }
        }
        //printf("%i, %i\n", total, numgc);
        /* casting the integers to floats to have a float result */
        seqArray[i].gc = (float)numgc / (float)total * (float)100;
        //printf("%s%f\n", seqArray[i].id, seqArray[i].gc);
    }

    /* finally determine and print the highest GC content */

    /* set lowest value to impossible values */
    float highest=0;
    int highindex=MAX+1;
    for (int i = 0; i < count; i++) {
        if (seqArray[i].gc >= highest) {
            highest = seqArray[i].gc;
            highindex = i;
        }
    }

    printf("%s%f\n", seqArray[highindex].id, seqArray[highindex].gc);

    return 0;
}
