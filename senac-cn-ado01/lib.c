#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "lib.h"

int para10(char c)
{
    if(c>='0' && c<='9'){
        return (int) c - '0';
    }
    else{
        return (int) c - 'A' + 10;
    }
}

long int convertePara10(char *numeroConverter, int baseAtual)
{
    long int i = 0, valor10 = 0, converter = strlen(numeroConverter);

    for (i=0;i<converter;i++){
        valor10 += para10(numeroConverter[converter - 1 - i] * potencia(baseAtual), i);
    }
    return valor10;
}

char *converterParaM(long int valor10, int novaBase, char alfabeto[])
{
    long int novoValor = valor10;

    char *novaString = (char*) calloc(1000, 1000 * sizeof(char));

    int i = 0;
    while(novoValor > 0)
    {
        int resto = novoValor % novaBase;
        novoValor /= novaBase;
        novaString[i] = alfabeto[resto];
        i++;
    }
    
    int j = 0;
    int tamanhoStr = strlen(novaString);
    char *valor = (char*) calloc(tamanhoStr, tamanhoStr * sizeof(char));
    for (j=0;j<tamanhoStr;j++){
        valor[j] = novaString[tamanhoStr-(j+1)];
    }
    return valor;
}

long int potencia(int x, int y)
{
    int i;
    double novoValor = 1;

    while(i<y)
    {
        novoValor *= x;
        i++;
    }
    return novoValor;
}