#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validar.h"

#define MAX_INPUT_BUFFER 500

int val_soloNumeros(char cadena[])
{
    int i, max, ans;
    max=strlen(cadena);

    for(i=0; i<max; i++ )
    {
        if (cadena[i] >= '0' && cadena[i] <= '9')
        {
            ans=1;
        }
        else
        {
            ans=0;
            break;
        }
    }
    return ans;
}

int val_soloLetras(char cadena[])
{
    int i, max, ans;
    max=strlen(cadena);

    for(i=0; i<max; i++ )
    {
        if((cadena[i] == ' ') || (cadena[i] >= 'A' && cadena[i] <= 'Z') || (cadena[i] >= 'a' && cadena[i] <= 'z'))
        {
            ans=1;
        }
        else
        {
            ans=0;
            break;
        }
    }
    return ans;
}

int val_alfaNumerico(char cadena[])
{
    int i, max, ans;
    max=strlen(cadena);

    for(i=0; i<max; i++ )
    {
        if((cadena[i] == ' ') || (cadena[i] >= 'A' && cadena[i] <= 'Z') || (cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] >= '0' && cadena[i] <= '9'))
        {
            ans=1;
        }
        else
        {
            ans=0;
            break;
        }
    }
    return ans;
}






/** \brief obtiene un dato con fgets, asigna '\0' al LF
 * \param buffer donde guarda lo que ingresa el usuario
 * \param limite caracteres
 * \param archivo
 */

void myFgets(char* buffer, int limite,FILE* archivo)
{
    int i=0;
    fgets(buffer, limite,archivo);
    buffer[limite-1] = '\0';
    while(buffer[i] != '\0')
    {
        if(buffer[i] == 10)//10 -> LF
        {
            buffer[i] = '\0';
            break;
        }
        i++;
    }
}


/** \brief Obtiene input usuario (myFgets) que deben ser solo letras (validarNombre)
 * \param array de caracteres del destino
 * \param mensaje con indicaciones para el usuario
 * \param mensaje de error
 * \param cantidad oportunidades que el usuario tiene para ingresar los datos correctamente
 * \param longitud del array destino
 * \return -1 ingreso erroneo luego de los intentos o error d parametros -- 0 ok
 */

int val_getNombre(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{

    int retorno = -1;
    char buffer[50];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {
            myFgets(buffer, limite,stdin);

            if(val_validarNombre(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/**
 * \brief Verifica si el valor recibido contiene letras
 * \param char buffer con la cadena a ser analizada
 * \return 0 si solo contiene letras y -1 error
 *
 */

int val_validarNombre(char* buffer)
{
    int i=0;
    int retorno = 0;
    while(buffer[i] != '\0')
    {
        if((buffer[i] != ' ') && (buffer[i] != '-') && (buffer[i] != 39) && (buffer[i] < 'a' || buffer[i] > 'z') && (buffer[i] < 'A' || buffer[i] > 'Z'))
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}

/** \brief Obtiene input usuario (myFgets) que deben ser solo letras y/o numeros, y un punto (validarNombreVideo)
 * \param array de caracteres del destino
 * \param mensaje con indicaciones para el usuario
 * \param mensaje de error
 * \param cantidad oportunidades que el usuario tiene para ingresar los datos correctamente
 * \param longitud del array destino
 * \return -1 ingreso erroneo luego de los intentos o error d parametros -- 0 ok
 */
int val_getNombreVideo(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{

    int retorno = -1;
    char buffer[50];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {
            myFgets(buffer, limite,stdin);

            if(val_validarNombreVideo(buffer) == 0)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/**
 * \brief Verifica si el valor recibido contiene los caracteres aceptados en el nombre de un archivo de video, letras, numeros y un punto
 * \param char buffer con la cadena a ser analizada
 * \return 0 si solo contiene letras, numeros y un punto y -1 error
 *
 */

int val_validarNombreVideo(char str[])
{
    int i=0;

    int cantidadPuntos=0;
    while(str[i] != '\0')
    {
        if (str[i] == '.' && cantidadPuntos == 0)
        {
            cantidadPuntos++;
            i++;
            continue;

        }
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
            return 0;
        i++;
    }
    return 1;
}

/** \brief Obtiene input usuario (myFgets) que deben ser solo numeros (validarUnsignedInt)
 * \param array de caracteres del destino
 * \param mensaje con indicaciones para el usuario
 * \param mensaje de error
 * \param cantidad oportunidades que el usuario tiene para ingresar los datos correctamente
 * \param longitud del array destino
 * \return -1 ingreso erroneo luego de los intentos o error d parametros -- 0 ok
 */
int val_getUnsignedInt(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {

            myFgets(buffer, limite,stdin);

            if(val_validarUnsignedInt(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/**
 * \brief Verifica si el valor recibido contiene solo numeros
 * \param str Array con la cadena a ser analizada
 * \return 0 si solo contiene numeros y -1 error
 *
 */
int val_validarUnsignedInt(char* buffer)
{
    int i=0;
    int retorno = 0;
    while(buffer[i] != '\0')
    {
        if(buffer[i] < '0' || buffer[i] > '9' )
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}

/** \brief Obtiene CUIT input usuario (myFgets) que deben ser solo numeros (val_esCuit)
 * \param array de caracteres del destino
 * \param mensaje con indicaciones para el usuario
 * \param mensaje de error
 * \param cantidad oportunidades que el usuario tiene para ingresar los datos correctamente
 * \param longitud del array destino
 * \return -1 ingreso erroneo luego de los intentos o error d parametros -- 0 ok
 */
int val_getCuit(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {

            myFgets(buffer, limite,stdin);

            if(val_esCuit(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/**
 * \brief Verifica si el valor recibido contiene solo numeros, y dos guiones (CUIT)
 * \param str Array con la cadena a ser analizada
 * \return 0 si solo contiene numeros y -1 error
 *
 */
int val_esCuit(char* buffer)
{

    int i=0;
    int cantidadGuiones = 0;
    int retorno = 0;
    while(buffer[i] != '\0')
    {
        if((buffer[i] < '0' || buffer[i] > '9') && buffer[i] != '-' )
        {
            retorno = -1;
            break;
        }
        if (buffer[i] == '-')
        {
            cantidadGuiones++;
        }

        i++;
    }
    if (cantidadGuiones != 2)
    {
        retorno = -1;
    }
    return retorno;
}

/** \brief Obtiene un enterp (myFgets) que deben ser numericos 0 o 1 (val_validarTipoPantalla)
 * \param array de caracteres del destino
 * \param mensaje con indicaciones para el usuario
 * \param mensaje de error
 * \param cantidad oportunidades que el usuario tiene para ingresar los datos correctamente
 * \param longitud del array destino
 * \return -1 ingreso erroneo luego de los intentos o error d parametros -- 0 ok
 */
int val_getTipoPantalla(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {

            myFgets(buffer, limite,stdin);

            if(val_validarTipoPantalla(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}


/**
 * \brief Verifica si el valor recibido contiene los numeros 0 o 1
 * \param str Array con la cadena a ser analizada
 * \return 0 si es 0 o 1 y -1 error
 *
 */
int val_validarTipoPantalla(char* buffer)
{
    int i=0;
    int retorno = 0;
    while(buffer[i] != '\0')
    {
        if(buffer[i] < '0' || buffer[i] > '1' )
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}


/**
 * \brief Verifica si el valor recibido contiene solo letras, números y espacios
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int val_esAlfaNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
            return 0;
        i++;
    }
    return 1;
}

/** \brief Obtiene un flotante (myFgets) que deben ser numericos aceptando flotantes (val_esNumericoFlotante)
 * \param array de caracteres del destino
 * \param mensaje con indicaciones para el usuario
 * \param mensaje de error
 * \param cantidad oportunidades que el usuario tiene para ingresar los datos correctamente
 * \param longitud del array destino
 * \return -1 ingreso erroneo luego de los intentos o error d parametros -- 0 ok
 */
int val_getFloat(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {
            myFgets(buffer, limite,stdin);

            if(val_esNumericoFlotante(buffer) == 0)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
/**
 * \brief Verifica si el valor recibido es numérico aceptando flotantes
 * \param buffer Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int val_esNumericoFlotante(char* buffer)
{
    int i=0;
    int cantidadPuntos=0;
    while(buffer[i] != '\0')
    {
        if (i == 0 && buffer[i] == '-')
        {
            i++;
            continue;

        }
        if (buffer[i] == '.' && cantidadPuntos == 0)
        {
            cantidadPuntos++;
            i++;
            continue;

        }
        if(buffer[i] < '0' || buffer[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

/** \brief Obtiene una direccion, arrat de char (myFgets) que deben ser alfanumericos aceptando espacios (val_esALfaNumerico)
 * \param array de caracteres del destino
 * \param mensaje con indicaciones para el usuario
 * \param mensaje de error
 * \param cantidad oportunidades que el usuario tiene para ingresar los datos correctamente
 * \param longitud del array destino
 * \return -1 ingreso erroneo luego de los intentos o error d parametros -- 0 ok
 */
int val_getDireccion(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{

    int retorno = -1;
    char buffer[50];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {
            myFgets(buffer, limite,stdin);

            if(val_esAlfaNumerico(buffer) == 0)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/* devuelve un int en lugar de char
int val_getUnsignedInt2(int* destino, char* mensaje,char* mensajeError,int intentos)
{
    int retorno = -1;
    char buffer[50];

        printf(mensaje);
        for( ; intentos>0; intentos--)
        {

            myFgets(buffer, 50,stdin);

            if(val_validarUnsignedInt(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                *destino = atoi(buffer);
                retorno = 0;
                break;
            }
        }
    return retorno;
}*/
