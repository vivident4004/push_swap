/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:18:27 by aflorea           #+#    #+#             */
/*   Updated: 2026/01/22 15:18:31 by aflorea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dio.h"

void	push(t_pila *s1, t_pila *s2)
{
	if ((s2->tail - s2->head + s2->size) % s2->size > 0)
	{
		s1->head = (s1->head - 1 + s1->size) % s1->size;
		s1->v[s1->head] = s2->v[s2->head];
		s2->head = (s2->head + 1) % s2->size;
	}
}

void	pa(t_pila *a, t_pila *b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_pila *a, t_pila *b)
{
	push(b, a);
	write(1, "pb\n", 3);
}
