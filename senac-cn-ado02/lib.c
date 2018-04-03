#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "lib.h"

double seno(double x)
{
    double seno = 0;
    int i;
    for(i=0;i<16;i++){
        seno += ((pontecia(-1, i) / fatorial(2 * i)) * pontecia(x, 2 * i + 1));
    }
    return seno;
}

double cosseno(double x)
{
    double cosseno = 0;
    int i;
    for(i=0;i<16;i++){
        cosseno += ((pontecia(-1, i) / ((fatorial(2 * i)) * pontecia(x, 2 * i + 1))));
    }
    return cosseno;
}

double potencia(double x, double y)
{
    int i;
    double novoValor = 1;

    while(i < y)
    {
        novoValor *= x;
        i++;
    }
    return novoValor;
}

double fatorial(int num)
{
    double rfat;

    if(num <= 1){
        return 1;
    }
    else{
        rfat = num * fatorial(num - 1);
        return rfat;
    }
}