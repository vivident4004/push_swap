/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 17:26:49 by aflorea           #+#    #+#             */
/*   Updated: 2026/02/01 17:26:50 by aflorea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dio.h"

/**
 * @brief Scambia i valori di due elementi in un vettore d'interi.
 */
void	quick_swap(int *v, int i, int j)
{
	int	temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

/**
 * @brief Organizza gli elementi del vettore attorno a un pivot.
 * Sposta gli elementi minori o uguali al pivot a sinistra 
 * e quelli maggiori a destra.
 * Implementazione basata sull'algoritmo di partizionamento del Cormen.
 * 
 * @param v Puntatore al vettore da partizionare.
 * @param p Indice inferiore (inizio del sottovettore).
 * @param r Indice superiore (fine del sottovettore, agisce da pivot).
 * @return int La posizione finale corretta del pivot.
 */
int	partition(int *v, int p, int r)
{
	int	x;
	int	i;
	int	j;

	x = v[r];
	i = p - 1;
	j = p;
	while (j < r)
	{
		if (v[j] <= x)
		{
			i++;
			quick_swap(v, i, j);
		}
		j++;
	}
	quick_swap(v, i + 1, r);
	return (i + 1);
}

/**
 * @brief Ordina un vettore d'interi utilizzando l'algoritmo quicksort.
 * Chiama la funzione partition() e poi chiama sé stessa ricorsivamente.
 * 
 * Seguendo l'implementazione del Cormen, la funzione opera in tre fasi:
 * 1. Dívide: partiziona il vettore in due sottovettori attorno a un pivot 
 * tramite partition().
 * 
 * 2. Ímpera: risolve ricorsivamente i sottoproblemi 
 * ordinando i due sottovettori.
 * 
 * 3. Combina: poiché l'ordinamento avviene sul posto, 
 * l'intero vettore risulta ordinato per effetto delle partizioni.
 * 
 * La ricorsione prosegue fino al caso base, ovvero quando un sottovettore ha
 * dimensione 1 (p = r) o 0 (p > r), risultando quindi banalmente ordinato.
 * Risalendo l'albero della ricorsione, il vettore originale sarà 
 * completamente ordinato.
 * 
 */
void	quicksort(int *v, int p, int r)
{
	int	q;

	if (p < r)
	{
		q = partition(v, p, r);
		quicksort(v, p, q - 1);
		quicksort(v, q + 1, r);
	}
}

/**
 * @brief Esegue una ricerca binaria in un vettore ordinato 
 * per trovare l'indice di un valore.
 * 
 * @param sorted_v puntatore al vettore precedentemente ordinato.
 * @param n numero totale di elementi nel vettore.
 * @param val il valore di cui trovare la posizione (rango).
 * @return int l'indice del valore nel vettore ordinato, o -1 se non trovato.
 */
static int	get_rank(int *sorted_v, int n, int val)
{
	int	low;
	int	high;
	int	mid;

	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (sorted_v[mid] == val)
			return (mid);
		if (sorted_v[mid] < val)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return (-1);
}

/**
 * @brief Normalizza i valori della pila sostituendoli con il loro rango.
 * Crea una copia temporanea dei dati, la ordina e usa get_rank() per aggiornare
 * i valori originali.
 */
void	index_numbers(t_pila *s)
{
	int	i;
	int	*tmp;

	tmp = malloc(sizeof(int) * s->size);
	if (!tmp)
		return ;
	i = 0;
	while (i < s->size)
	{
		tmp[i] = s->v[i];
		i++;
	}
	quicksort(tmp, 0, s->size - 1);
	i = 0;
	while (i < s->size)
	{
		s->v[i] = get_rank(tmp, s->size, s->v[i]);
		i++;
	}
	free(tmp);
}
