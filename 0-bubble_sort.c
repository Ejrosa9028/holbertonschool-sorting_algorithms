#include "sort.h"

/**
 * bubble_sort - Ordena arreglo de enteros usando algoritmo Bubble Sort
 * @array: El arreglo de enteros
 * @size: El tamaño del arreglo
 *
 * Descripción: La función ordena el arreglo en orden, realizando
 * intercambios de elementos. de cada intercambio, el arreglo es impreso.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	int temp;

	int swapped;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				/* Intercambiar los elementos */
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				/* Imprimir el arreglo después del intercambio */
				print_array(array, size);

				swapped = 1;
			}
		}

		/* Si no hubo intercambios, el arreglo ya está ordenado */
		if (!swapped)
			break;
	}
}
