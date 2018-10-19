#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include <conio.h>
#include "Datos.h"


char dat_getChar(char cadena_a_mostrar[])
{
    char chara;
    printf("%s",cadena_a_mostrar);
    fflush(stdin);
    scanf("%c",&chara);
    return chara;
}

int dat_getInt(char cadena_a_mostrar[])
{
    int validInt, entero, letras;
    char auxiliar[128];
    char numero[6];
    printf("%s", cadena_a_mostrar);
    scanf("%s", auxiliar);

    validInt = val_validarEnteros(auxiliar);
    letras= strlen(auxiliar);

    while (validInt!=0 || letras>5)
    {
        printf("ERROR. n%cmero inv%clido... reintente por favor\n",163,160);
        printf("%s", cadena_a_mostrar);
        scanf("%s",auxiliar);
        validInt = val_validarEnteros(auxiliar);
        letras= strlen(auxiliar);
    }
    strcpy(numero, auxiliar);
    entero= atoi(numero);

    return entero;
}

long int dat_getLongInt(char cadena_a_mostrar[], int enteroL_len) //para DNI 8
{
    long int validInt, enteroL, letras;
    char auxiliar[128];
    char numero[11];
    printf("%s", cadena_a_mostrar);
    scanf("%s", auxiliar);

    validInt = val_validarEnteros(auxiliar);
    letras= strlen(auxiliar);

    while (validInt!=0 || letras>enteroL_len || letras<enteroL_len)
    {
        printf("ERROR. n%cmero inv%clido... reintente por favor\n",163,160);
        printf("%s", cadena_a_mostrar);
        scanf("%s",auxiliar);
        validInt = val_validarEnteros(auxiliar);
        letras= strlen(auxiliar);
    }
    strcpy(numero, auxiliar);
    enteroL= atol(numero);

    return enteroL;
}

float dat_getFloat (char cadena_a_mostrar[])
{
    int validF, letras;
    float flotante;
    char numero[21];

    printf("%s", cadena_a_mostrar);
    scanf("%s", numero);

    letras = strlen(numero);
    validF = val_validarFlotantes(numero);

    while (validF!=0 || letras>20)
    {
        printf("ERROR. el numero no puede contener letras, ni s%cmbolos a excepci%cn del punto (coma)... reintente por favor\n",161, 162);
        printf("%s", cadena_a_mostrar);
        scanf("%s",numero);
        validF = val_validarFlotantes(numero);
    }
    flotante = atof(numero);
    //printf("en func %.3f\n ",flotante);

    return flotante;
}

void dat_getTexto(char cadena_a_mostrar[],char save[],int texto_len)
{
    char auxiliar [1024];
    int letras, validText;

    printf("%s",cadena_a_mostrar);
    fflush(stdin);
    scanf("%[^\n]", auxiliar);

    letras = strlen(auxiliar);
    validText = val_validarTexto(auxiliar);

    while (validText!=0 || letras >texto_len)
    {
        printf("ERROR. reintente por favor:\n");
        printf("%s", cadena_a_mostrar);
        fflush(stdin);
        scanf("%[^\n]", auxiliar);
        letras = strlen(auxiliar);
        validText = val_validarTexto(auxiliar);
    }
    strcpy(save, auxiliar);
}

void dat_getName(char save[])
{
    char nombre[41];
    char apellido [41];
    char apellidoynombre[83];
    int i;

    dat_getTexto("Ingrese un nombre: ", nombre,41);
    dat_getTexto("ingrese un apellido: ", apellido,41);

    strlwr(nombre);
    strlwr(apellido);
    nombre[0]= toupper(nombre[0]);
    apellido[0]= toupper(apellido[0]);
    for (i=0; i<41; i++)
    {
        if(nombre[i]==' ' && nombre [i+1]!= ' ')
        {
            nombre[i+1] = toupper(nombre[i+1]);
        }
    }
    for (i=0; i<41; i++)
    {
        if(apellido[i]==' ' && apellido [i+1]!= ' ')
        {
            apellido[i+1] = toupper(apellido[i+1]);
        }
    }

    strcpy(apellidoynombre, apellido);
    strcat(apellidoynombre, ", ");
    strcat(apellidoynombre, nombre);

    strcpy(save, apellidoynombre);
}
