#define _XOPEN_SOURCE 500

#include <stdio.h>
#include "lib.h"
#include <math.h>

void eulerFloat()
{
    FILE *plotagem1 = popen("gnuplot -persisten", "w");
    fprintf(plotagem1, "set terminal png\n");
    fprintf(plotagem1, "set output 'euler_flt.png'\n");
    fprintf(plotagem1, "set logscale x\n");

    fprintf(plotagem1, "plot '-' w l\n");

    float euler = 0.0;

    int i;
    for (i=0;i<=20;i++){
        float n powf(10, i);
        euler = powf((1 + 1 / n), n);

        fprintf(plotagem1, "%f %f\n", n, euler);
    }
    fprintf(plotagem1, "e");
    pclose(plotagem1);
}

void eulerDouble()
{
    FILE *plotagem2 = popen("gnuplot -persisten", "w");
    fprintf(plotagem2, "set terminal png\n");
    fprintf(plotagem2, "set output 'euler_dbl.png'\n");
    fprintf(plotagem2, "set logscale x\n");

    fprintf(plotagem1, "plot '-' w l\n");

    double euler = 0.0;

    int i;
    for (i=0;i<=20;i++){
        double n pow(10, i);
        euler = pow((1 + 1 / n), n);

        fprintf(plotagem2, "%lf %lf\n", n, euler);
    }
    fprintf(plotagem2, "e");
    pclose(plotagem2);
}

void eulerLongDouble()
{
    FILE *plotagem3 = popen("gnuplot -persisten", "w");
    fprintf(plotagem3, "set terminal png\n");
    fprintf(plotagem3, "set output 'euler_ldbl.png'\n");
    fprintf(plotagem3, "set logscale x\n");

    fprintf(plotagem3, "plot '-' w l\n");

    long double euler = 0.0;

    int i;
    for (i=0;i<=20;i++){
        long double n powl(10, i);
        euler = powl((1 + 1 / n), n);

        fprintf(plotagem3, "%LF %LF\n", n, euler);
    }
    fprintf(plotagem3, "e");
    pclose(plotagem3);
}