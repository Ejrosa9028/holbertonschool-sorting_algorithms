#include "sort.h"
/**
 * insertion_sort_list - Ordena una lista doblemente enlazada de enteros
 *                       usando el algoritmo de Insertion Sort.
 * @list: Un puntero al puntero de la cabeza de la lista.
 *
 * Descripción: La función recorre lista y va insert cada nodo en su
 * posición correcta, realizando intercambios de nodos cuando es necesario.
 * Después de cada intercambio, la lista se imprime.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		while (current->prev != NULL && current->n < current->prev->n)
		{
			temp = current->prev;
			/* Realizar el intercambio de nodos */
			if (temp->prev != NULL)
				temp->prev->next = current;

			current->prev = temp->prev;
			temp->next = current->next;
			if (current->next != NULL)
				current->next->prev = temp;

			current->next = temp;
			temp->prev = current;

			/* Actualizar el puntero de cabeza si es necesario */
			if (current->prev == NULL)
				*list = current;

			print_list(*list);
		}
		current = current->next;
	}
}
