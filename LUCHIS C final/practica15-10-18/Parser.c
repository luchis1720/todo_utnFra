#include <stdio.h>
#include "Parser.h"


void par_loader(ArrayList* lista1, ArrayList* lista2, char* archivo1, char* archivo2) //carga los archivos en la lista
{
    int checkFile1=-1, checkFile2=-1;

    checkFile1= par_loadFile1(lista1,archivo1);
    checkFile2= par_loadFile2(lista2,archivo2);
    if(!checkFile1 && !checkFile2)
    {
        printf("Archivos cargados con exito\n");
    }
    lt_sleep(1720);
}

int par_saveFile1(ArrayList* lista, char* archivo)
{
    int i, ans =-1;
    FILE* pFile=fopen(archivo,"w");
    Ent1* aux=NULL;     // COLOCAR LA ENTIDAD NOMBRETIPO
    if(pFile!=NULL)
    {
        fprintf(pFile,"TitulodeParam_1,TitulodeParam_2,TitulodeParam_3,TitulodeParam_4,TitulodeParam_5\n");
        for(i=0; i<al_len(lista); i++)
        {
            aux=al_get(lista,i);
            fprintf(pFile, "%s,%s,%d,%s,%d\n",enty1_getApellido(aux),enty1_getNombre(aux),enty1_getId(aux),enty1_getDni(aux), enty1_getEstado(aux)); //get de cada item

            //employee_getId(pEmployees),employee_getName(pEmployees), employee_getLastName(pEmployees), employee_getAge(pEmployees), employee_getType(pEmployees));
        }
        ans=0;
    }
    fclose(pFile);
    return ans;
}

int par_saveFile2(ArrayList* lista, char* archivo)
{
    int i, ans =-1;
    FILE* pFile=fopen(archivo,"w");
    Ent2* aux=NULL;     // COLOCAR LA ENTIDAD NOMBRETIPO
    if(pFile!=NULL)
    {
        fprintf(pFile,"TitulodeParam_1,TitulodeParam_2,TitulodeParam_3,TitulodeParam_4,TitulodeParam_5\n");
        for(i=0; i<al_len(lista); i++)
        {
            aux=al_get(lista,i);
            fprintf(pFile, "%s,%s,%d,%s,%d\n",enty2_getApellido(aux),enty2_getNombre(aux),enty2_getId(aux),enty2_getDni(aux), enty2_getEstado(aux)); //get de cada item

            //employee_getId(pEmployees),employee_getName(pEmployees), employee_getLastName(pEmployees), employee_getAge(pEmployees), employee_getType(pEmployees));
        }
        ans=0;
    }
    fclose(pFile);
    return ans;
}

int par_loadFile1(ArrayList* lista, char* archivo)
{
    int ans = -1;
    char param_1[4096];
    char param_2[4096];
    char param_3[4096];
    char param_4[4096];
    char param_5[4096];
    FILE* pFile = fopen(archivo, "r");
    //Entidad* auxiliar;     // COLOCAR LA ENTIDAD NOMBRETIPO
    if(pFile != NULL)
    {
        ans = 1;
        if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",param_1,param_2,param_3,param_4,param_5)==5)
        {
            do
            {
                if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",param_1,param_2,param_3,param_4,param_5)==5)
                {
                    //if(/* validar parametros*/ )
                    {
                        //auxiliar = entidad_new();

                        //cargar parametros de entidad

                        //per_setId(pAux,atoi(var1));
                        //per_setNombre(pAux,var2);
                        //per_setApellido(pAux,var3);
                        //per_setEdad(pAux,atoi(var4));

                        //al_add(lista,auxiliar);
                    }
                }
            }
            while(!feof(pFile));
            ans=0;
        }
    }
    return ans;
}


int par_loadFile2(ArrayList* lista, char* archivo)
{
    int ans = -1;
    char param_1[4096];
    char param_2[4096];
    char param_3[4096];
    char param_4[4096];
    char param_5[4096];
    FILE* pFile = fopen(archivo, "r");
    //Entidad* auxiliar;     // COLOCAR LA ENTIDAD NOMBRETIPO
    if(pFile != NULL)
    {
        ans = 1;
        if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",param_1,param_2,param_3,param_4,param_5)==5)
        {
            do
            {
                if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",param_1,param_2,param_3,param_4,param_5)==5)
                {
                    //if(/* validar parametros*/ )
                    {
                        //auxiliar = entidad_new();

                         //cargar parametros de entidad

                        //al_add(lista,auxiliar);
                    }
                }
            }
            while(!feof(pFile));
            ans=0;
        }
    }
    return ans;
}
