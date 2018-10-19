#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>
#include "luistoncic.h"



int lt_menu(char cadenas_del_menu[])
{
    int choice;
    printf("%s", cadenas_del_menu);
    choice= dat_getInt("\nElija una opcion: ");
    return choice;
}

void lt_miMenu(char cadenas_del_menu[])
{
    char seguir='s';
    int choice;

    do
    {
        lt_begin();
        choice= lt_menu(cadenas_del_menu);

        switch (choice)
        {
        case 1:
            lt_opcion1();
            break;
        case 2:
            lt_opcion2();
            break;
        case 3:
            lt_opcion3();
            break;
        case 4:
            lt_opcion4();
            break;
        case 5:
            lt_opcion5();
            break;
        case 6:
            lt_opcion6();
            break;
        case 7:
            lt_opcion7();
            break;
        case 8:
            lt_opcion8();
            break;
        case 9:
            lt_opcion9();
            break;
        case 10:
            lt_opcion10();
            break;
        case 0:
            seguir = 'n';
            break;
        case 1720:
            lt_opcion1720();
            break;
        default:
            printf("\nOpci%cn inv%clida. Reintente por favor...\n\n", 162, 160);
            break;
        }
        system("pause");
    }
    while (seguir=='s');
}

void lt_opcion1()
{
    examen_rename1();
}

void lt_opcion2()
{
    examen_rename2();
}

void lt_opcion3()
{
    examen_rename3();
}

void lt_opcion4()
{
    examen_rename4();
}

void lt_opcion5()
{
    examen_rename5();
}

void lt_opcion6()
{
    examen_rename6();
}

void lt_opcion7()
{
    examen_rename7();
}

void lt_opcion8()
{
    examen_rename8();
}

void lt_opcion9()
{
    examen_rename9();
}

void lt_opcion10()
{
    examen_rename10();
}

void lt_opcion1720()
{
    examen_rename1720();
}

int lt_enterOrEsc (char cadena_a_mostrar[])
{
    char conf;
    int ans;

    printf("%s", cadena_a_mostrar);
    printf("\npresione ENTER para continuar o ESC para cancelar?\n\n");
    fflush(stdin);
    conf= getch();
    while (!(conf==27 || conf==13))
    {
        printf("\nERROR. presione ENTER para continuar o ESC para cancelar?\n\n");
        fflush(stdin);
        conf= getch();
    }
    if (conf!= 27 )
    {
        ans= 1;
    }
    else
    {
        printf("\nACCION CANCELADA POR EL USUARIO\n\n");
        ans= 0;
    }
    return ans;
}



void lt_end()
{
    printf("\n*************************************************************\n*\t\t\t\t\t\t\t    *\n*\t=============\t  GRACI");
    printf("AS!!\t=============       *\n*\t\t\t\t\t\t\t    *\n*************************************************************\n");
}

void lt_begin()
{
    lt_clear();
    printf("\n*************************************************************\n*\t\t\t\t\t\t\t    *\n*  Luis A. Ton");
    printf("cic   DNI:33.655.967   leg:106877   div: 1_F  *\n*\t\t\t\t\t\t\t    *\n*\t =====  Examen Final - Labo");
    printf("ratorio  I  =====\t    *\n*\t\t\t\t\t\t\t    *\n*************************************************************\n");
    lt_sleep(172);
}


//Davila`s

char lt_getNumeroAleatorio(int desde, int hasta, int iniciar)
{
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}

void lt_showDate(void) // muestra la hora y dia actual.
{
    time_t timer;
    char buffer[26];
    struct tm* tm_info;

    time(&timer);
    tm_info = localtime(&timer);

    strftime(buffer, 26, "%Y:%m:%d %H:%M:%S", tm_info);
    puts(buffer);
}

void lt_clear(void)   // limpia pantalla usando secuencias ANSI escape.
{
#ifdef __unix__
    system("clear");
#else
    system("cls");
#endif // __unix__
}

void lt_sleep(int msc) //realiza un retraso. ms = cantidad de milisegundos.
{
#ifdef __unix__
    usleep(ms*1000);
#else
    Sleep(msc);
#endif // __unix__
}

void lt_flush(void)
{
#ifdef __unix__
    setbuf(stdin,NULL);
#else
    fflush(stdin);
#endif // __unix__
}



/*
void lt_mezclaRandom (Struct1 vec[])
{
    int i, j, limite_array=49; //igualar a constante
    Struct1 auxiliar;

    lt_getNumeroAleatorio(0,1,1);
    for(i=0; i<limite_array-1; i++)
    {
        for(j=0; j<limite_array; j++)
        {
            if(lt_getNumeroAleatorio(0,1,0))
            {
                auxiliar=vec[i];
                vec[i]=vec[j];
                vec[j]=auxiliar;
            }
        }
    }
}




void lt_inicializarArray(Struct1 vec[], int cant_elementos, int valor_a_ingresar)
{
    int i;
    for (i=0; i<cant_elementos; i++)
    {
        vec[i].estado = valor_a_ingresar;
    }
    //for (i=0;i<cant_elementos;i++)
    //{
      //  printf("%d \n",vec[i].estado);
    //}
}

int lt_obtenerPrimerOcurrencia(Struct1 vec[], int cant_elementos, int valor_a_buscar)
{
    int ans=-1, i;
    for (i=0; i<cant_elementos; i++)
    {
        if(vec[i].estado == valor_a_buscar)
        {
            ans=i;
            break;
        }
    }
    //printf("ok %d \t", i);
    return ans;
}

*/





