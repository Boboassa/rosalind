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
            /* remove first character */
            memmove(line, line+1, strlen(line));
            strcpy(seqArray[count-1].id, line);
            //printf("%s", seqArray[count-1].id);
        }
        if (line[0]=='A' | line[0]=='C' | line[0]=='G' | line[0]=='T') {
            strcat(seqArray[count-1].nucs, line);
        }
    }

    fclose(f);

    char consensus[4][BUFFER]; /* A, C, G, T */
    int i = 0;

    /* for each sequence */
    for (i = 0; i < count; i++) {

        /* for each character of the string */
        for (int j = 0; j < strlen(seqArray[i].nucs); j++) {
            switch (seqArray[i].nucs[j]) {
                case 'A':
                    consensus[0][j]++;
                    break;
                case 'C':
                    consensus[1][j]++;
                    break;
                case 'G':
                    consensus[2][j]++;
                    break;
                case 'T':
                    consensus[3][j]++;
                    break;
                default:
                    break;
            }

        }

        //printf("%s%f\n", seqArray[i].id, seqArray[i].gc);
    }

    /* finally determine and print the highest GC content */

    printf("A: ");
    for (i = 0; i < BUFFER; i++) {
        printf("%c ", consensus[0][i]);
    }
    printf("\n");
    printf("C: ");
    for (i = 0; i < BUFFER; i++) {
        printf("%c ", consensus[1][i]);
    }
    printf("\n");
    printf("G: ");
    for (i = 0; i < BUFFER; i++) {
        printf("%c ", consensus[2][i]);
    }
    printf("\n");
    printf("T: ");
    for (i = 0; i < BUFFER; i++) {
        printf("%c ", consensus[3][i]);
    }


    /* set lowest value to impossible values */
    /*
    float highest=0;
    int highindex=MAX+1;
    for (int i = 0; i < 4; i++) {
        if (seqArray[i].gc >= highest) {
            highest = seqArray[i].gc;
            highindex = i;
        }
    }
     */

    //printf("%s%f\n", seqArray[highindex].id, seqArray[highindex].gc);

    printf("\n");
    return 0;
}
