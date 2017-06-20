#include <math.h>

int PMT(int *, int*, int *);

int PMT(tasa, n_periodos, prestamo)
	int *tasa;
	int *n_periodos;
	int *prestamo;
{
    return ((*prestamo) * (*tasa)) / (1 - pow((1 + (*tasa)), (-(*n_periodos))));
}

