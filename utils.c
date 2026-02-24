/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:42:16 by aflorea           #+#    #+#             */
/*   Updated: 2026/01/16 15:42:17 by aflorea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dio.h"

/**
 * @brief Aggiorna gli indici min_idx e max_idx della pila
 * @param s puntatore alla pila da analizzare
 */
void	update_min_max(t_pila *s)
{
	int	i;
	int	current_val;

	if (is_empty(s))
		return ;
	i = s->head;
	s->min = s->v[i];
	s->max = s->v[i];
	s->min_idx = i;
	s->max_idx = i;
	while (i != s->tail)
	{
		current_val = s->v[i];
		if (current_val < s->min)
		{
			s->min = current_val;
			s->min_idx = i;
		}
		if (current_val > s->max)
		{
			s->max = current_val;
			s->max_idx = i;
		}
		i = (i + 1) % s->size;
	}
}

int	check_sorted(t_pila *a)
{
	int	i;

	i = 1;
	while ((a->head + i) % a->size != a->tail)
	{
		if (a->v[(a->head + i - 1 + a->size) % a->size]
			< a->v[(a->head + i) % a->size])
			return (0);
		i++;
	}
	return (1);
}

// void	stampa_v(t_pila *p)
// {
// 	int	i;

// 	i = p->head;
// 	printf("[");
// 	while (i != p->tail)
// 	{
// 		printf("%d", p->v[i]);
// 		i = (i + 1) % p->size;
// 		if (i != p->tail)
// 			printf(", ");
// 	}
// 	printf("]\n");
// }

int	max(int x, int y)
{
	if (x >= y)
		return (x);
	return (y);
}
