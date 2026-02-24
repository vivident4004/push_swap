/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:18:42 by aflorea           #+#    #+#             */
/*   Updated: 2026/01/22 15:18:44 by aflorea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dio.h"

void	reverse_rotate(t_pila *s)
{
	s->head = (s->head - 1 + s->size) % s->size;
	s->tail = (s->tail - 1 + s->size) % s->size;
	s->v[s->head] = s->v[s->tail];
}

void	rra(t_pila *a)
{
	if (a->head == a->tail || ((a->head + 1) % a->size == a->tail))
		return ;
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_pila *b)
{
	if (b->head == b->tail || ((b->head + 1) % b->size == b->tail))
		return ;
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_pila *a, t_pila *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
