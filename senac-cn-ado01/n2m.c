#define _XOPEN_SOURCE 500

#include <stdio.h>
#include <stdlib.h>

#include "lib.h"

int main(int argc, char *argv[])
{
    if(argc != 4){
        printf("Número de Argumentos Invalidos\n");
        exit(1);
    }

    char alfabeto [] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    char* valorEntrada = argv[1];
    int baseN = atoi(argv[2]);
    int baseM = atoi(argv[3]);

    long int limite = potencia(2, 32);
    long int valorNaBase10 = convertePara10(valorEntrada, baseN);

    if(valorNaBase10 == 0){
        printf("0\n");
        exit(0);
    }
    if(valorNaBase10 < 0 || valorNaBase10 > limite){
        exit(1);
    }
    if(baseN < 2 || baseN > 36){
        exit(1);
    }
    printf("%s\n", converterParaM(valorNaBase10, baseN, alfabeto));
    exit(0);
}