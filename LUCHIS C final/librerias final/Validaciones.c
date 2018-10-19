#include <strings.h>
#include "Validaciones.h"


int val_validarTexto(char cadena[])
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

int val_validarEnteros(char cadena[])
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

int val_validarFlotantes(char cadena[])
{
    int i, max, ans;
    int contpuntos,neg;

    contpuntos = val_contadorCadena(cadena);
    neg= val_allowNeg(cadena);
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

int val_contadorCadena(char cadena[])
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

int val_allowNeg(char cadena[])
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
