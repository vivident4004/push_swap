/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:18:49 by aflorea           #+#    #+#             */
/*   Updated: 2026/01/22 15:18:50 by aflorea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dio.h"

void	rotate(t_pila *s)
{
	s->v[s->tail] = s->v[s->head];
	s->tail = (s->tail + 1) % s->size;
	s->head = (s->head + 1) % s->size;
}

void	ra(t_pila *a)
{
	if (a->head == a->tail || ((a->head + 1) % a->size == a->tail))
		return ;
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_pila *b)
{
	if (b->head == b->tail || ((b->head + 1) % b->size == b->tail))
		return ;
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_pila *a, t_pila *b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
