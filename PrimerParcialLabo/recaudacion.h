#ifndef RECAUDACION_H_
#define RECAUDACION_H_

#include "contribuyente.h"

typedef struct
{

	int idRecaudacion;
    int mes;
    int importe;
	char tipo[50];
	int idContribuyente;
	char estado[50];
	int isEmpty;

}eRecaudacion;


int initRecaudacion(eRecaudacion arrayRecaudacion[], int tamArrayRecaudacion);

int agregarRecaudacion(eRecaudacion arrayRecaudacion[], int tamArrayRecaudacion,eContribuyente arrayContribuyente[], int tamArray, int contadorRec);

int mostrarRecaudaciones(eRecaudacion arrayRecaudacion[] ,int tamArrayRecaudacion);

int mostrarRecaudacion(eRecaudacion arrayRecaudacion[] ,int i);

int mostrarRecaudacionPorId(eRecaudacion arrayRecaudacion[], int tamArray,int id);

int modificacionRecaudacion(eRecaudacion arrayRecaudacion[], int tamArrayRecaudacion);

#endif
