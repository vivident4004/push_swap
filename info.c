/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:02:19 by aflorea           #+#    #+#             */
/*   Updated: 2026/01/16 13:02:21 by aflorea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dio.h"

int	is_empty(t_pila *p)
{
	return (p->head == p->tail);
}

/**
 * @brief Calcola e ritorna il numero di elementi in una pila
 */
int	numel(t_pila *p)
{
	if (p->tail >= p->head)
		return (p->tail - p->head);
	return (p->size - p->head + p->tail);
}

/**
 * @brief Calcola e ritorna la distanza di un indice dalla testa (head)
 */
int	dist_up(t_pila *p, int idx)
{
	return ((idx - p->head + p->size) % p->size);
}

/**
 * @brief Calcola e ritorna la distanza di un indice dalla coda (tail)
 */
int	dist_down(t_pila *p, int idx)
{
	int	c;

	c = dist_up(p, idx);
	if (c == 0)
		return (0);
	return (numel(p) - c);
}
