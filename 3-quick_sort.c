#include "sort.h"
#include <stdio.h>

/**
 * lomuto_partition - Esquema de partición Lomuto para Quick Sort.
 * @array: Arreglo de enteros a ordenar.
 * @low: Índice inicial de la partición.
 * @high: Índice final de la partición.
 * @size: Tamaño del arreglo (se usa para imprimir).
 *
 * Return: Índice del pivote.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, temp;

	pivot = array[high];  /* El pivote es el último elemento */
	i = low - 1;          /* Índice para el elemento más pequeño */

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			/* Intercambio de elementos */
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);  /* Imprimir después de cada intercambio */
		}
	}

	/* Intercambio el pivote con el elemento en la posición i + 1 */
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	print_array(array, size);  /* Imprimir después de pivote en su posición */

	return (i + 1);  /* Devolver la posición del pivote */
}

/**
 * quick_sort_rec - Función recursiva ordenar arreglo usando Quick Sort.
 * @array: Arreglo de enteros a ordenar.
 * @low: Índice inicial de la partición.
 * @high: Índice final de la partición.
 * @size: Tamaño del arreglo (se usa para imprimir).
 */
void quick_sort_rec(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = lomuto_partition(array, low, high, size); /* Índice del pivote */

		quick_sort_rec(array, low, pi - 1, size); /*Ordenar la parte izqui*/
		quick_sort_rec(array, pi + 1, high, size); /* Ordenar la parte derecha */
	}
}

/**
 * quick_sort - Ordena un arreglo usando el algoritmo Quick Sort.
 * @array: Arreglo de enteros a ordenar.
 * @size: Tamaño del arreglo.
 *
 * Descripción: Ordena arreglo en orden ascendente en  partición de Lomuto.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_rec(array, 0, size - 1, size); /*Llamada a la función recursiva*/
}
