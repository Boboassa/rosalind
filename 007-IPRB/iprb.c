/*
 * Simply calculating the probability of homozygus recessive offspring and then
 * subtracting it from 1
 * It would be cool to generalize this problem to return the 3 different
 * probabilities (respectively aa, Aa, and AA), in the future
*/

#include <stdio.h>
#include <stdlib.h>

float probRecessive(float k, float m, float n);

int main(int argc, char *argv[])
{

    if (argc != 4) {
        printf("Wrong number of arguments\n");
        exit(1);
    }

    float k, m, n, pDom;
    k = atof(argv[1]);
    m = atof(argv[2]);
    n = atof(argv[3]);
    pDom = 1 - probRecessive(k, m, n);
    printf("%f\n", pDom);

    return 0;
}

float probRecessive(float k, float m, float n)
{
    /* total population */
    float t;
    t = k + m + n;

    float pRec;

    pRec = n/t * (n-1)/(t-1) * 1;
    pRec += n/t * m/(t-1) * .5;
    pRec += m/t * n/(t-1) * .5;
    pRec += m/t * (m-1)/(t-1) * .25;
    
    return pRec;
}
