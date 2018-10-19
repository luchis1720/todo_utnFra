#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "mybook.h"
#include "luistoncic.h"
#include "manejodatoslt.h"



int main()
{
    int usuarioslog, mensajeslog, feedlog;
    ArrayList* listaM;
    ArrayList* listaU;
    ArrayList* listaF;

    lt_begin();

    if ((listaM=al_newArrayList())!=NULL)
    {
        if((listaU=al_newArrayList())!=NULL)
        {
            if((listaF=al_newArrayList())!=NULL)
            {
                mensajeslog= mb_loadMensajes(listaM);
                usuarioslog= mb_loadUsuarios(listaU);
                feedlog= mb_loadFeed(listaM, listaU, listaF);
                if(usuarioslog==0 && mensajeslog==0 && feedlog==0)
                {
                    printf("Archivos cargados...\n\n");
                    al_deleteArrayList(listaM);
                    al_deleteArrayList(listaU);
                }

                //mb_followers(listaF);
                //mb_saveFeed(listaF,"feed.csv");
                //if(feedlog==0)
                    //printf("Archivo generado con exito!!!\n\n");

            }
        }
    }

    lt_end();

    return 0;
}
