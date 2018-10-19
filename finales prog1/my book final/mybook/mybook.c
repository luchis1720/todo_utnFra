#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include <conio.h>
#include "ArrayList.h"
#include "mybook.h"

int mb_loadMensajes(ArrayList* lista)
{
    int ans = -1;

    if(lista!=NULL)
    {
        S_message* mensaje;
        char mensajeaux[3040];
        char idmensaux[4];
        char idusuaaux[4];
        char populaux[10];
        int idmaux,iduaux;
        long int popaux;

        FILE* archivo;
        archivo = fopen("mensajes.csv","r");
        if(archivo == NULL)
        {
            fclose(archivo);
            printf("ERROR, No se pudo abrir el archivo...\n");
        }
        else
        {
            ans = 0;
            while(!feof(archivo))
            {
                fscanf(archivo,"%[^,],%[^,],%[^,],%[^\n]\n",idmensaux,idusuaaux,populaux,mensajeaux);

                idmaux= atoi(idmensaux);
                iduaux= atoi(idusuaaux);
                popaux= atol(populaux);

                mensaje = mb_mensajeNew();

                strcpy(mensaje->mensaje,mensajeaux);
                mensaje->id_mensaje = idmaux;
                mensaje->id_usuario = iduaux;
                mensaje->popularidadm = popaux;

                //printf("struct loaded\n");

                if(mensaje!=NULL)
                {
                    lista->add(lista,mensaje);
                }
                else
                {
                    printf("Error de memoria...\n");
                }
                //printf("M: %d , %d , %ld , %s \n", mensaje->id_mensaje, mensaje->id_usuario, mensaje->popularidadm, mensaje->mensaje);
                free(mensaje);
            }
            fclose(archivo);
        }
    }
    return ans;
}

int mb_loadUsuarios(ArrayList* lista)
{
    int ans = -1;

    if(lista!=NULL)
    {
        S_user* usuario;
        //char auxiliar[2048];
        char nick[56];
        char idusuaaux[4];
        char populaux[10];
        int iduaux;
        // int i, cont=0;
        long int popaux;

        FILE* archivo;
        archivo = fopen("usuarios.csv","r");
        if(archivo == NULL)
        {
            fclose(archivo);
            printf("ERROR, No se pudo abrir el archivo...\n");
        }
        else
        {
            ans = 0;
            while(!feof(archivo))
            {

                fscanf(archivo,"%[^,],%[^,],%[^\n]\n",idusuaaux,nick,populaux);

                iduaux= atoi(idusuaaux);
                popaux= atol(populaux);

                usuario = mb_usuarioNew();

                strcpy(usuario->nick,nick);
                usuario->id_usuario= iduaux;
                usuario->popularidadu = popaux;

                //printf("estruct loaded\n");

                if (usuario!=NULL)
                {
                    lista->add(lista,usuario); //printf("ok\n");
                }
                else
                {
                    printf("Error de memoria...\n");
                }
                //printf("U: %d , %ld , %s \n", usuario->id_usuario, usuario->popularidadu, usuario->nick);
                free(usuario);
            }
            fclose(archivo);
        }
    }
    return ans;
}

int mb_loadFeed(ArrayList* lista1,ArrayList* lista2, ArrayList* lista3)
{
    int ans=-1;
    S_feed* feed;
    S_feed* feedAux;
    S_message* mensaje;
    S_user* usuario;
    char msjAux[3048]= {0};
    char nickAux[62]= {0};
    //char id_msj[4]= {0};
    //char pop_msj[10]= {0};
    //char id_usu[4]= {0};
    //char pop_usu[10]= {0};
    int aux_idUsu=0, aux_idMsj=0;
    int i,j,k,h;
    long int aux_popUsu=0, aux_popMsj=0;

    if(lista1!=NULL && lista2!=NULL && lista3!=NULL)
    {
        ans=0;
        for(i=0; i<al_len(lista2); i++) //cargo todos los usuarios en la lista 3
        {
            if((usuario=mb_usuarioNew())!=NULL)
            {
                usuario=al_get(lista2,i);

                if((feed=mb_feedNew())!=NULL)
                {
                    aux_idUsu=usuario->id_usuario;
                    aux_popUsu=usuario->popularidadu;
                    strcpy(nickAux,usuario->nick);

                    strcpy(feed->mensaje,msjAux);
                    feed->id_usuario=aux_idUsu;
                    feed->id_mensaje=aux_idMsj;
                    strcpy(feed->nick,nickAux);
                    feed->popularidadm=aux_popMsj;
                    feed->popularidadu=aux_popUsu;
                    feed->estado=0;

                    lista3->add(lista3,feed);
                }
            }
            free(usuario);
            free(feed);
        }
        for(j=0; j<al_len(lista3); j++) //busco en lista 3 coincidencias con usuarios y lo agrego si es necesario el msj.
        {
            if((feedAux=mb_feedNew())!=NULL && (feed=mb_feedNew())!=NULL)
            {
                feed= al_get(lista3,j);
                if(feed->estado==0) // si es el primer msj le agrego los datos.
                {
                    for(k=0; k<al_len(lista1); k++)
                    {
                        if((mensaje=mb_mensajeNew())!=NULL)
                        {
                            mensaje= al_get(lista1,k);
                            if(feed->id_usuario==mensaje->id_usuario)
                            {
                                aux_idMsj= mensaje->id_mensaje;
                                strcpy(msjAux,mensaje->mensaje);
                                aux_popMsj= mensaje->popularidadm;

                                feed->id_mensaje= aux_idMsj;
                                strcpy(feed->mensaje,msjAux);
                                feed->popularidadm=aux_popMsj;
                                feed->estado=1;


                                al_push(lista3,j,feed);

                                free(feed);
                                free(mensaje);
                            }
                        }
                    }
                }
                else if(feed->estado==1) //si al menos ya escribio un msj. lo copio,
                {
                    //  le agrego los datos del msj ,y lo agrego a la lista
                    for (h=0; h<al_len(lista1); h++)
                    {
                        if((mensaje=mb_mensajeNew())!=NULL)
                        {
                            mensaje= al_get(lista1,k);
                            if(feed->id_usuario==mensaje->id_usuario && feed->id_mensaje!=mensaje->id_mensaje)
                            {
                                feedAux=feed;

                                aux_popMsj= mensaje->popularidadm;
                                strcpy(msjAux,mensaje->mensaje);
                                aux_idMsj=mensaje->id_mensaje;

                                feedAux->popularidadm=aux_popMsj;
                                strcpy(feedAux->mensaje,msjAux);
                                feedAux->id_mensaje=aux_idMsj;

                                lista3->add(lista3,feedAux);

                                free(feed);
                                free(feedAux);
                                free(mensaje);
                            }
                        }
                    }
                }
            }
        }
    }
    // ALGO ESTA MAL...
    for(i=0;i<al_len(lista3);i++)
    {
        if((feed=mb_feedNew())!=NULL)
        {
            feed=al_get(lista3,i);
            printf("F: %d , %s , %ld , %d , %ld , %s \n", feed->id_usuario, feed->nick, feed->popularidadu, feed->id_mensaje, feed->popularidadm, feed->mensaje);
        }
        free(feed);
    }

    return ans;
}

void mb_saveFeed(ArrayList* lista,char* nombre_archivo)
{
    FILE* archivo;

    archivo= fopen(nombre_archivo,"w+");
    if(archivo == NULL)
    {
        fclose(archivo);
        printf("ERROR, No se pudo abrir el archivo...\n");
    }
    else
    {

    }


}

S_message* mb_mensajeNew()
{
    S_message* newStruct;

    newStruct= (S_message*)malloc(sizeof(S_message));
    if(newStruct!=NULL)
        return newStruct;

    return NULL;
}

S_user* mb_usuarioNew()
{
    S_user* newStruct;

    newStruct= (S_user*)malloc(sizeof(S_user));
    if(newStruct!=NULL)
        return newStruct;

    return NULL;
}

S_feed* mb_feedNew()
{
    S_feed* newStruct;

    newStruct= (S_feed*)malloc(sizeof(S_feed));
    if(newStruct!=NULL)
        return newStruct;

    return NULL;
}
