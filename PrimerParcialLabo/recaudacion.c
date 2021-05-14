#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "recaudacion.h"
#include "UTN.h"



int initRecaudacion(eRecaudacion arrayRecaudacion[], int tamArrayRecaudacion)
{
    int i;
    int resultado=-1;


       if (tamArrayRecaudacion !=0)
        {
            for (i=0;i<tamArrayRecaudacion;i++)
            {
            	arrayRecaudacion[i].isEmpty=1;
                resultado=0;
            }
        }

        return resultado;
}

int mostrarRecaudacionPorId(eRecaudacion arrayRecaudacion[], int tamArray,int id)
{
     int i;
    if(arrayRecaudacion != NULL && tamArray>=0)
    {
        for(i=0;i<tamArray;i++)
        {
            if(arrayRecaudacion[i].isEmpty==0 && arrayRecaudacion[i].idContribuyente==i)
            {
            	mostrarRecaudacion(arrayRecaudacion,i);
            	return i;
            }

       }

    }
    return -1;
}


int agregarRecaudacion(eRecaudacion arrayRecaudacion[], int tamArrayRecaudacion,eContribuyente arrayContribuyente[], int tamArray, int contadorRec)
{
    int resultado=0;
    int espacioLibre=-1;
    int i;
    int opc;
    int opc2;
    if (tamArrayRecaudacion >0)
    {
        for (i=0;i<tamArrayRecaudacion;i++)
        {
            if (arrayRecaudacion[i].isEmpty==1)
            {

                espacioLibre=i;

                break;
            }
        }
    }

    if(espacioLibre>=0)
    {

            mostrarContribuyentes( arrayContribuyente, tamArray);

            utn_getInt("\nIngrese el ID del contribuyente: ","\nIngresa un valor correcto 0-1999: ",&arrayRecaudacion[espacioLibre].idContribuyente,2,1999,0);

    	    utn_getInt("\nIngrese el mes: ","\nIngresa un valor correcto 0-99999: ",&arrayRecaudacion[espacioLibre].mes,2,12,0);

    	    utn_getInt("\nIngrese el importe: ","\nIngresa un valor correcto 0-99999: ",&arrayRecaudacion[espacioLibre].importe,2,99999,0);



            printf("Ingrese opcion: \n");
            printf("1.ARBA\n");
            printf("2.IIBB\n");
            printf("3.GANANCIAS\n");
            scanf("%d",&opc);

            switch(opc)
            {
            case 1:

            strcpy(arrayRecaudacion[espacioLibre].tipo,"ARBA");
            break;
            case 2:
            strcpy(arrayRecaudacion[espacioLibre].tipo,"IIBB");
            break;
            case 3:
            strcpy(arrayRecaudacion[espacioLibre].tipo,"GANANCIAS");
            break;
            }

            printf("Ingrese opcion: \n");
            printf("1.NORMAL\n");
            printf("2.REFINANCIAR\n");
            printf("3.SALDADO\n");
            scanf("%d",&opc2);

            switch(opc2)
            {
            case 1:

            strcpy(arrayRecaudacion[espacioLibre].estado,"NORMAL");
            break;
            case 2:
            strcpy(arrayRecaudacion[espacioLibre].estado,"REFINANCIAR");
            break;
            case 3:
            strcpy(arrayRecaudacion[espacioLibre].estado,"SALDADO");
            break;
            }


            arrayRecaudacion[espacioLibre].idRecaudacion=contadorRec+1;
            arrayRecaudacion[espacioLibre].isEmpty=0;


            resultado=1;
    }



    return resultado;
}
int mostrarRecaudaciones(eRecaudacion arrayRecaudacion[] ,int tamArray)
{

    int i;
    int resultado=-1;
    if(arrayRecaudacion != NULL && tamArray>=0)
    {
        for(i=0;i<tamArray;i++)
        {
            if(arrayRecaudacion[i].isEmpty==0)
            {
            	mostrarRecaudacion(arrayRecaudacion,i);
            }

       }
       resultado=1;
    }

    return resultado;
}
int mostrarRecaudacion(eRecaudacion arrayRecaudacion[] ,int i)
{
   printf("\nID CONTRIBUYENTE:%d---ID RECAUDACION:%d---IMPORTE:%d---TIPO:%s---MES:%d---ESTADO:%s\n", arrayRecaudacion[i].idContribuyente,
                                                                                                     arrayRecaudacion[i].idRecaudacion,
                                                                                                     arrayRecaudacion[i].importe,
                                                                                                     arrayRecaudacion[i].tipo,
                                                                                                     arrayRecaudacion[i].mes,
                                                                                                     arrayRecaudacion[i].estado);




    return 1;
}

int modificacionRecaudacion(eRecaudacion arrayRecaudacion[], int tamArrayRecaudacion)
{

    int retorno=-2;
    int opcionMod;
    int i;
    int aux;
    char auxChar;
    int opc2;

    mostrarRecaudaciones(arrayRecaudacion,tamArrayRecaudacion);

    utn_getInt("\nIngrese el ID  del usuario que quiera modificar: ","\nIngresa un valor correcto 0-199: ",&aux,2,1999,0);


    if(tamArrayRecaudacion > 0 && arrayRecaudacion != NULL)
    {
        for(i=0;i<tamArrayRecaudacion;i++)
        {
            if(aux==arrayRecaudacion[i].idRecaudacion && arrayRecaudacion[i].isEmpty==0)
            {
            	mostrarRecaudacion(arrayRecaudacion,i);
                utn_getChar("\nDesea modificar este usuario(s--O--n): ","\nIngrese la opcion correcta entre(s--O--n): ",&auxChar,2);

                if(auxChar=='s')
                {
                    opcionMod=modificar2();

                    switch(opcionMod)
                    {
                           printf("Ingrese opcion: \n");
                           printf("1.NORMAL\n");
                           printf("2.REFINANCIAR\n");
                           printf("3.SALDADO\n");
                           scanf("%d",&opc2);

                          switch(opc2)
                          {
                            case 1:

                            strcpy(arrayRecaudacion[i].estado,"NORMAL");
                            break;
                            case 2:
                            strcpy(arrayRecaudacion[i].estado,"REFINANCIAR");
                            break;
                            case 3:
                            strcpy(arrayRecaudacion[i].estado,"SALDADO");
                            break;
                          }

                    }
                    retorno=1;
                    break;
                }
            }
        }

    }


    return retorno;
}

