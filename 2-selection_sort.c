#include "sort.h"

/**
 * selection_sort - Ordena un arreglo de enteros en orden ascendente
 *                  usando el algoritmo de Selection Sort.
 * @array: Un puntero al arreglo de enteros.
 * @size: El tamaño del arreglo.
 *
 * Descripción: El algoritmo selecciona el elemento más pequeño en cada
 * iteración y lo coloca en su lugar, imprimiendo el arreglo
 * después de cada intercambio.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
			}
		}

		/*Si el índice mínimo es diferente al actual, se realiza el intercambio*/
		if (min_idx != i)
		{
			temp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = temp;

			print_array(array, size);  /*Imprimir el arreglo después del intercambio*/
		}
	}
}
