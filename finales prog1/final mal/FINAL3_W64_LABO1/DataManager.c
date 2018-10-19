#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Cliente.h"
#include "Venta.h"
#include "DataManager.h"

int dm_saveAllClientes(ArrayList* pArrayClientes)
{
    int i;
    int retorno=-1;
    FILE* pArchivoSocios=fopen(ARCHIVO_CLIENTES,"wb");
    void* pSocio=NULL;
    if(pArchivoSocios!=NULL)
    {
        for(i=0;i<al_len(pArrayClientes);i++)
        {
            pSocio=al_get(pArrayClientes,i);
            fwrite(pSocio,sizeof(Cliente),1,pArchivoSocios);
            retorno=0;
        }

    }
    fclose(pArchivoSocios);
    return retorno;
}

int dm_readAllClientes(ArrayList* pArrayClientes)
{
    int retorno=-1;
    Cliente auxSocio;
    int maxId=0;
    Cliente* pSocio=NULL;
    FILE* pArchivoSocios=fopen(ARCHIVO_CLIENTES,"rb");

    if(pArchivoSocios!=NULL)
    {
        do{
            if(fread(&auxSocio,sizeof(Cliente),1,pArchivoSocios)==1)
            {
                pSocio=soc_new(auxSocio.nombre,auxSocio.apellido,auxSocio.dni,auxSocio.id,auxSocio.estado);
                al_add(pArrayClientes,pSocio);
                if(auxSocio.id>maxId)
                {
                    maxId=auxSocio.id;
                }
                retorno=maxId;
            }
        }while(!feof(pArchivoSocios));
        fclose(pArchivoSocios);
    }
    return retorno;
}


int dm_saveAllVentas(ArrayList* pArrayVentas)
{
    int i;
    int retorno=-1;
    FILE* pArchivoVentas=fopen(ARCHIVO_VENTAS,"wb");
    void* pVenta=NULL;
    if(pArchivoVentas!=NULL)
    {
        for(i=0;i<al_len(pArrayVentas);i++)
        {
            pVenta=al_get(pArrayVentas,i);
            fwrite(pVenta,sizeof(Venta),1,pArchivoVentas);
            retorno=0;
        }
    }
    fclose(pArchivoVentas);
    return retorno;
}


int dm_readAllVentas(ArrayList* pArrayVentas)
{
    int retorno=-1;
    Venta auxVenta;
    int maxId=0;
    Venta* pVenta=NULL;
    FILE* pF=fopen(ARCHIVO_VENTAS,"rb");

    if(pF!=NULL)
    {
        do{
            if(fread(&auxVenta,sizeof(Venta),1,pF)==1)
            {
                pVenta=ven_new(auxVenta.id);

                al_add(pArrayVentas,pVenta);
                if(auxVenta.id>maxId)
                {
                    maxId=auxVenta.id;
                }
                retorno=maxId;
            }
        }while(!feof(pF));
        fclose(pF);
    }
    return retorno;
}
