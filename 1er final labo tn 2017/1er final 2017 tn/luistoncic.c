#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>
#include "luistoncic.h"
#include "ArrayList.h"
#include "final.h"


int lt_menu(char cadenas_del_menu[])
{
    int choice;
    printf("%s", cadenas_del_menu);
    choice= lt_getInt("\nElija una opcion: ");
    return choice;
}

void lt_opciones(char cadenas_del_menu[],ArrayList* lista1)
{
    char seguir='s';
    int choice, numero, baja, venta, anular, broke, informeVenta, informeProductos, producto, generar, arch;
    int check0=-1, check1=-1, check2=-1, aux=-1, checkCLIENT=-1, checkSALE=-1,fileCLIENT=-1,fileSALE=-1;

    //funcion de archivos con check0 aqui!!!!!!!!!!!!!!!!!!!!!
    checkCLIENT= final_loadClientFile(lista1);
    checkSALE= final_loadSaleFile(lista1);
    if(checkCLIENT==0 && checkSALE==0)
    {
        printf("Archivos cargados con exito\n");
        check0=0;
    }
    lt_sleep(1720);
    do
    {
        system("cls");
        lt_begin();
        choice= lt_menu(cadenas_del_menu);

        switch (choice)
        {
        case 1:
            check1= final_altaCliente(lista1);
            if(check1==0)
            {
                printf("Cliente dado de alta\n");
                check0=0;
            }
            fileCLIENT=final_saveClientFile(lista1);
            if(fileCLIENT==0)
                printf("\nArchivo actualizado\n\n");
            break;
        case 2://Modificar
            if(check0!=0)
            {
                printf("No hay clientes ingresados...\n");
                break;
            }
            else
            {
                final_printCliente(lista1);
                numero=lt_getInt("Ingrese el numero de Id del cliente que desea modificar: \n");

                if(numero<=al_len(lista1))
                    final_modificarCliente(lista1, numero);
                else
                {
                    printf("Error, el numero ingresado, no corresponde a un cliente en la base de datos\n");
                }
            }
            fileCLIENT=final_saveClientFile(lista1  );
            if(fileCLIENT==0)
                printf("\nArchivo actualizado\n\n");
            break;
        case 3://BAJA CLIENTE
            if(check0!=0)
            {
                printf("No hay clientes ingresados...\n");
                break;
            }
            else
            {
                final_printCliente(lista1);
                baja=lt_getInt("Ingrese el numero de Id del cliente que desea modificar: \n");

                if(baja<=al_len(lista1))
                    final_bajaCliente(lista1, baja);
                else
                {
                    printf("Error, el numero ingresado, no corresponde a un cliente en la base de datos\n");
                }
            }
            if((aux=final_checkList(lista1))!=0)
                check0=-1; //lista vacia, o con clientes cargados pero dados de baja.
                fileCLIENT=final_saveClientFile(lista1);
            if(fileCLIENT==0)
                printf("\nArchivo actualizado\n\n");
            break;
        case 4: // LISTAR clientes
            if(check0!=0)
            {
                printf("No hay clientes ingresados...\n");
                break;
            }
            else
            {
                final_surnameSort(lista1);
                final_printCliente(lista1);
            }
            break;
        case 5: //realizar venta
            if(check0!=0)
            {
                printf("No hay clientes ingresados...\n");
                break;
            }
            else
            {
                final_printCliente(lista1);
                venta=lt_getInt("Ingrese el numero de Id del cliente que desea modificar: \n");

                if(venta<=al_len(lista1))
                    check2=final_ventaNuevaCliente(lista1, venta);
                if(check2==0)
                {
                    printf("Venta realizada con exito!\n");
                }

                if(check2==-1)
                {
                    printf("Error, el numero ingresado, no corresponde a un cliente en la base de datos\n");
                }
            }
            fileSALE=final_saveSaleFile(lista1);
            if(fileSALE==0)
                printf("\nArchivo actualizado\n\n");
            break;
        case 6: //ANULAR VENTA
            if((broke=final_getLastIdVenta(lista1))==0)
                printf("No hay ventas realizadas...\n");
            else
            {
                final_printCliente(lista1);
                anular=lt_getInt("Ingrese el Numero de Id de venta que desea anular: \n");
                if(anular<=broke)
                {
                    final_anularVenta(lista1,venta);
                }
                else
                {
                    printf("Error, el numero ingresado, no corresponde a una venta en la base de datos\n");
                }
            }
            fileSALE=final_saveSaleFile(lista1);
            if(fileSALE==0)
                printf("\nArchivo actualizado\n\n");
            break;
        case 7: //INFORMAR VENTAS (pantalla)
            if((informeVenta=final_getLastIdVenta(lista1))==0)
                printf("No hay ventas realizadas...\n");
            else
            {
                final_printCliente(lista1);
            }
            break;
        case 8: //INFORMAR VENTAS POR PRODUCTO
            if((informeProductos=final_getLastIdVenta(lista1))==0)
                printf("No hay ventas realizadas...\n");
            else
            {
                printf("PRODUCTOS\n1.-TV LG 32\n2.-PS4\n3.-IPHONE7");
                producto=lt_getInt("\nIngrese el producto por el cual desea listar las ventas: ");

                if(producto>0 && producto<4)
                    final_informeVentasProductos(lista1,producto);
                else
                {
                    printf("Error, el numero ingresado no corresponde a un producto en la base de datos\n");
                }
            }
            break;
        case 9: //Generar archivo informe.txt
            if(check0!=0)
            {
                printf("No hay clientes ingresados...\n");
            }
            else if ((generar=final_getLastIdVenta(lista1))==0)
            {
                printf("No hay ventas realizadas...\n");
            }
            else
            {
                arch= final_volcadoArchivos(lista1);
                if(arch==0)
                    printf("\nARCHIVO GENERADO Y GUARDADO CON EXITO\n");
            }
            break;
        case 10: // Informar ventas por cliente (pantalla)
            final_ventasXcliente(lista1);
            break;
            case 0:
            seguir = 'n';
            break;
        case 1720:
            //final_getLastId(lista1);
            //printf("swtich %d\n\n",gdsg);
            break;
        default:
            printf("\nOpci%cn inv%clida. Reintente por favor...\n\n", 162, 160);
            break;
        }
        system("pause");
    }
    while (seguir=='s');

}

char lt_getChar(char cadena_a_mostrar[])
{
    char chara;
    printf("%s",cadena_a_mostrar);
    fflush(stdin);
    scanf("%c",&chara);
    return chara;
}

int lt_getInt(char cadena_a_mostrar[])
{
    int validInt, entero, letras;
    char auxiliar[128];
    char numero[6];
    printf("%s", cadena_a_mostrar);
    scanf("%s", auxiliar);

    validInt = lt_validarEnteros(auxiliar);
    letras= strlen(auxiliar);

    while (validInt!=0 || letras>5)
    {
        printf("ERROR. n%cmero inv%clido... reintente por favor\n",163,160);
        printf("%s", cadena_a_mostrar);
        scanf("%s",auxiliar);
        validInt = lt_validarEnteros(auxiliar);
        letras= strlen(auxiliar);
    }
    strcpy(numero, auxiliar);
    entero= atoi(numero);

    return entero;
}

long int lt_getLongInt(char cadena_a_mostrar[], int enteroL_len) //para DNI 8
{
    long int validInt, enteroL, letras;
    char auxiliar[128];
    char numero[11];
    printf("%s", cadena_a_mostrar);
    scanf("%s", auxiliar);

    validInt = lt_validarEnteros(auxiliar);
    letras= strlen(auxiliar);

    while (validInt!=0 || letras>enteroL_len || letras<enteroL_len)
    {
        printf("ERROR. n%cmero inv%clido... reintente por favor\n",163,160);
        printf("%s", cadena_a_mostrar);
        scanf("%s",auxiliar);
        validInt = lt_validarEnteros(auxiliar);
        letras= strlen(auxiliar);
    }
    strcpy(numero, auxiliar);
    enteroL= atol(numero);

    return enteroL;
}

float lt_getFloat (char cadena_a_mostrar[])
{
    int validF, letras;
    float flotante;
    char numero[21];

    printf("%s", cadena_a_mostrar);
    scanf("%s", numero);

    letras = strlen(numero);
    validF = lt_validarFlotantes(numero);

    while (validF!=0 || letras>20)
    {
        printf("ERROR. el numero no puede contener letras, ni s%cmbolos a excepci%cn del punto (coma)... reintente por favor\n",161, 162);
        printf("%s", cadena_a_mostrar);
        scanf("%s",numero);
        validF = lt_validarFlotantes(numero);
    }
    flotante = atof(numero);
    //printf("en func %.3f\n ",flotante);

    return flotante;
}

void lt_getTexto(char cadena_a_mostrar[],char save[],int texto_len)
{
    char auxiliar [1024];
    int letras, validText;

    printf("%s",cadena_a_mostrar);
    fflush(stdin);
    scanf("%[^\n]", auxiliar);

    letras = strlen(auxiliar);
    validText = lt_validarTexto(auxiliar);

    while (validText!=0 || letras >texto_len)
    {
        printf("ERROR. reintente por favor:\n");
        printf("%s", cadena_a_mostrar);
        fflush(stdin);
        scanf("%[^\n]", auxiliar);
        letras = strlen(auxiliar);
        validText = lt_validarTexto(auxiliar);
    }
    strcpy(save, auxiliar);
}

void lt_getName(char save[])
{
    char nombre[41];
    char apellido [41];
    char apellidoynombre[83];
    int i;

    lt_getTexto("Ingrese un nombre: ", nombre,41);
    lt_getTexto("ingrese un apellido: ", apellido,41);

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

void lt_inicializarArray(Struct1 vec[], int cant_elementos, int valor_a_ingresar)
{
    int i;
    for (i=0; i<cant_elementos; i++)
    {
        vec[i].estado = valor_a_ingresar;
    }
    /*for (i=0;i<cant_elementos;i++)
    {
        printf("%d \n",vec[i].estado);
    }*/
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






//VALIDACIONES

int lt_validarTexto(char cadena[])
{
    int i, max, ans;
    max=strlen(cadena);

    for(i=0; i<max; i++ )
    {
        if((cadena[i] == ' ') || (cadena[i] >= 'A' && cadena[i] <= 'Z') || (cadena[i] >= 'a' && cadena[i] <= 'z'))
        {
            ans=0;
        }
        else
        {
            ans=1;
            break;
        }
    }
    return ans;
}

int lt_validarEnteros(char cadena[])
{
    int i, max, ans;
    max=strlen(cadena);

    for(i=0; i<max; i++ )
    {
        if (cadena[i] >= '0' && cadena[i] <= '9')
        {
            ans=0;
        }
        else
        {
            ans=1;
            break;
        }
    }
    return ans;
}

int lt_validarFlotantes(char cadena[])
{
    int i, max, ans;
    int contpuntos,neg;

    contpuntos = lt_contadorCadena(cadena);
    neg= lt_allowNeg(cadena);
    max=strlen(cadena);

    for(i=0; i<max; i++ )
    {
        if ((contpuntos==1) && (neg==1) && ((cadena[i]=='.')||(cadena[i] >= '0' && cadena[i] <= '9')||(cadena[i]=='-')))
        {
            ans=0;
        }
        else
        {
            ans=1;
            break;
        }
    }
    return ans;
}

int lt_contadorCadena(char cadena[])
{
    int i, max, ans;
    int contadorpuntos=0;

    max=strlen(cadena);

    for(i=0; i<max; i++ )
    {
        if(cadena[i]=='.')
        {
            contadorpuntos++;
        }
    }
    if(contadorpuntos==1 || contadorpuntos==0)
    {
        ans=1;
    }
    else
    {
        ans=0;
    }

    return ans;
}

int lt_allowNeg(char cadena[])
{
    int ans,i,max;
    int esnegativo=0,flag=0;

    max=strlen(cadena);

    if(cadena[0]=='-')
    {
        esnegativo++;
        flag=1;
    }

    for(i=1; i<max; i++)
    {
        if(cadena[i]=='-')
            esnegativo++;
    }

    if((esnegativo==1 && flag==1 )|| esnegativo==0)
    {
        ans=1;
    }
    else
    {
        ans=0;
    }

    return ans;
}




//Davila`s

char lt_getNumeroAleatorio(int desde, int hasta, int iniciar)
{
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}

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




//

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





// DATA MANAGEMENT
/*


void dm_setInput(input inputArray[],int freePlaceIndex, int aux1, char aux2, int aux3, int aux4)
{

}

void dm_showArray(input inputArray[], int arrayLenght)
{
    int i;
    printf("\n| CODIGO |                 TITULO                 | AUTOR | STOCK |");
    for (i=0;i<arrayLenght;i++)
    {
        if(inputArray[i].estado !=-1)
            printf("\n| %6d | %-40s | %5d |%5d |",inputArray[i].AAA,inputArray[i].BBB,inputArray[i].CCC,inputArray[i].DDD);
    }
}


*/


/*
void lt_opciones()
{
    char seguir='s';
    int tramite=0;

    do
    {
        system("cls");
        switch(menu("1.-TRAMITE URGENTE\n2.-TRAMITE REGULAR\n3.-PROXIMO CLIENTE\n4.-LISTAR\n5.-INFORMAR\n6.-SALIR\n"))
        {
        case 1: //Turgente

            tramite=1;
            break;
        case 2 : //Tregular

            tramite=1;
            break;
        case 3 : //proximo cliente
            if (tramite!=0)
            {

            }
            else
            {
                printf("\nDEBE HABER INGRESADO AL MENOS UN TRAMITE PARA CONTINUAR");
            }
            break;
        case 4: //listar
            if (tramite!=0)
            {

            }
            else
            {
                printf("\nDEBE HABER INGRESADO AL MENOS UN TRAMITE PARA PODER LISTAR");
            }
            break;
        case 5: //informar
            if (tramite!=0)
            {

            }
            else
            {
                printf("\nDEBE HABER INGRESADO AL MENOS UN TRAMITE PARA PODER INFORMAR");
            }
            break;
        case 6: //salir
            seguir='n';
            break;
        default:
            printf("\nOpci%cn inv%clida. Reintente por favor...\n\n", 162, 160);
            break;
        }
        system("pause");
    }
    while (seguir=='s');

}
*/

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief ejecuta un switch, en base a la opcion seleccionada.
 *
 * \param choice int es la opcion seleccionada por el usuario.
 *
 * \return no retorna datos
 *
 */
//void lt_opciones(int choice);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



