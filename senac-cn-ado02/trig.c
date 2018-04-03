#define _XOPEN_SOURCE 500

#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    FILE *dat;
    dat = fopen("seno.dat","w");
    dat = fopen("seno.dat","a");

    int i;
    for(i=0;i<=720;i++){
        double rad = i * (pi/180);
        double erroAbsoluto = fabs(sin(rad) - seno(rad));
        double erroRelativo = fabs(erroAbsoluto / seno(rad));

        fprintf(dat, "%d\t%f\t%f\t%f\n", i, seno(rad), erroAbsoluto, erroRelativo);
    }
    fclose(dat);

    dat = fopen("cosseno.dat","w");
    dat = fopen("cosseno.dat","a");

    for(i=0;i<=720;i++){
        double rad = i * (pi/180);
        double erroAbsoluto = fabs(cos(rad) - cosseno(rad));
        double erroRelativo = fabs(erroAbsoluto / cosseno(rad));

        fprintf(dat, "%d\t%f\t%f\t%f\n", i, cosseno(rad), erroAbsoluto, erroRelativo);
    }
    fclose(dat);

    FILE *plotagem;
    plotagem = popen("gnuplot -persistent", "w");
    fprintf(plotagem,"%s\n", "set terminal png size 400,300\nset output'seno.png'", "plot 'seno.dat'\n");
    fprintf(plotagem,"%s\n", "set terminal png size 400,300\nset output'cosseno.png'", "plot 'cosseno.dat'\n");

    exit(0);
}