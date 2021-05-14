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
   printf("\nID RECAUDACION:%d---IMPORTE:%d---TIPO:%s---MES:%d\n", arrayRecaudacion[i].idRecaudacion  ,
                                                                   arrayRecaudacion[i].importe,
                                                                   arrayRecaudacion[i].tipo,
                                                                   arrayRecaudacion[i].mes);




    return 1;
}

/*int imprimirRecaudacionesSaldadas(eRecaudacion arrayRecaudacion[] ,int tamArray)
{

    int i;
    int resultado=-1;
    if(arrayRecaudacion != NULL && tamArray>=0)
    {
        for(i=0;i<tamArray;i++)
        {
            if(arrayRecaudacion[i].isEmpty==0 && arrayRecaudacion[i].estado==2)
            {
            	mostrarRecaudacion(arrayRecaudacion,i);
            }

       }
       resultado=1;
    }

    return resultado;





}*/
