/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:19:05 by aflorea           #+#    #+#             */
/*   Updated: 2026/02/16 19:36:51 by aflorea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dio.h"

void	swap(t_pila *s)
{
	int	tmp;

	if (numel(s) > 1)
	{
		tmp = s->v[s->head];
		s->v[s->head] = s->v[(s->head + 1) % s->size];
		s->v[(s->head + 1) % s->size] = tmp;
	}
}

void	sa(t_pila *a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_pila *b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_pila *a, t_pila *b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
