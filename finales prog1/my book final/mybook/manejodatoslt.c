#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "manejodatoslt.h"
#include "luistoncic.h"
#include "validar.h"


char* dm_lt_getDynamicString(char* cadena_a_mostrar)
{
    char* pData;
    char* aux;
    int len;

    printf(cadena_a_mostrar);

    pData = (char*) malloc(sizeof(char)*1024);

    if(pData!=NULL)
    {
        scanf("%1023s",pData); //cant max 1023 dejamos un byte para terminador.
        len = strlen(pData);

        aux = (char*)realloc(pData,sizeof(char)*(len+1)); // realloc de cant letras +1 byte de caracter terminador.

        if (aux!=NULL)
        {
             pData=aux;
             free(aux);
        }
    }
    return pData;
}

void dm_lt_loadData (S_struct1* p)
{
    //lt_getstring("ingrese un nombre: \n",p->field1);
    //lt_get
    //p->field3= lt_getint
}

int dm_lt_saveBinFile(S_struct1* p, char* nombre_archivo)
{
    int ans;
    FILE* fp;
    fp=fopen(nombre_archivo,"ab+"); //append binario (lo crea si no existe)
    if (fp==NULL)
    {
        printf("error abriendo archivo\n");
        ans=0;
    }
    if (p!=NULL)
        fwrite(p,sizeof(S_struct1),1,fp); //escribo una struct al final

    fclose(fp);
    ans=1;
    return ans;
}

S_struct1* dm_lt_searchBinFile(char* cadena_a_buscar, char* nombre_archivo)
{
    int flagFound=0;
    S_struct1* pRet;
    FILE* fp;
    fp=fopen(nombre_archivo,"rb");
    if (fp==NULL)
    {
        printf("Error abriendo archivo.\n");
        return NULL;
    }

    pRet = (S_struct1*)malloc(sizeof(S_struct1));
    if (pRet!=NULL)
    {
        while (fread(pRet,sizeof(S_struct1),1,fp)!=0)
        {
            //printf("\nleyendo %s %s %d\r\n", pRet->field1, pRet->field2, pRet->field3);
            if(strcmp(cadena_a_buscar,pRet->field2)==0)
            {
                flagFound=1;
                break;
            }
        }
    }
    fclose(fp);
    if(flagFound)
        return pRet;

    free(pRet);
    return NULL;
}


