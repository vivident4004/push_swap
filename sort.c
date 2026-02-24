/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:04:10 by aflorea           #+#    #+#             */
/*   Updated: 2026/01/16 13:04:11 by aflorea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dio.h"

// static void	push_cond(t_pila *a, t_pila *b)
// {
// 	int	n;

// 	while (!is_empty(b))
// 	{
// 		n = a->v[(a->tail - 1 + a->size) % a->size];
// 		while (n < a->v[a->head] && n > b->v[b->head])
// 		{
// 			rra(a);
// 			n = a->v[(a->tail - 1 + a->size) % a->size];
// 		}
// 		pa(a, b);
// 	}
// }

// static void	finish(t_pila *a, t_pila *b)
// {
// 	int	dh;
// 	int	dt;

// 	if (is_empty(b))
// 		return ;
// 	update_min_max(b);
// 	dh = dist_up(b, b->max_idx);
// 	dt = dist_down(b, b->max_idx);
// 	if (dh == 0)
// 		dt = 0;
// 	if (dh < dt)
// 	{
// 		while (b->head != b->max_idx)
// 			rb(b);
// 	}
// 	else
// 	{
// 		while (b->head != b->max_idx)
// 			rrb(b);
// 	}
// 	push_cond(a, b);
// 	update_min_max(a);
// 	while (a->v[a->tail] < a->max)
// 		rra(a);
// }

static int	is_sorted(t_pila *s)
{
	int	i;

	if (numel(s) == 1)
		return (1);
	i = s->head;
	while ((i + 1) % s->size != s->tail)
	{
		if (s->v[i] > s->v[(i + 1) % s->size])
			return (0);
		i = (i + 1) % s->size;
	}
	return (1);
}

static void	three_sort(t_pila *a)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = a->v[a->head];
	n2 = a->v[(a->head + 1) % a->size];
	n3 = a->v[(a->head + 2) % a->size];
	if (n1 > n2 && n1 > n3)
		ra(a);
	else if (n2 > n1 && n2 > n3)
		rra(a);
	n1 = a->v[a->head];
	n2 = a->v[(a->head + 1) % a->size];
	if (n1 > n2)
		sa(a);
}

static void	small_sort(t_pila *a)
{
	if (numel(a) == 0 <= 1)
		return ;
	else if (numel(a) == 3)
		three_sort(a);
	else if (a->v[a->head] > a->v[(a->head + 1) % a->size])
		sa(a);
	return ;
}

/**
 * @brief Algoritmo goloso che cerca le mosse ottimali a ogni iterazione
 * @details ciclo che svuota A, spostando in B, usando la logica del costo minimo
 * @param a pila A
 * @param b pila B
 */
// void	greedy_sort(t_pila *a, t_pila *b)
// {
// 	t_cost	best_move;

// 	pb(a, b);
// 	pb(a, b);
// 	while (numel(a) > 3)
// 	{
// 		update_min_max(a);
// 		update_min_max(b);
// 		best_move = find_cheapest(a, b);
// 		move(a, b, &best_move);
// 		pb(a, b);
// 	}
// 	three_sort(a);
// 	finish(a, b);
// }

void	push_back(t_pila *a, t_pila *b)
{
	t_cost	best_move;

	while (!is_empty(b))
	{
		update_min_max(a);
		update_min_max(b);
		best_move = find_cheapest(b, a);
		reverse_move(b, a, &best_move);
		pa(a, b);
	}
}

void	tom_sort(t_pila *a, t_pila *b)
{
	if (numel(a) == 0 || numel(a) == 1 || numel(a) == 2 || numel(a) == 3)
		return (small_sort(a));
	if (is_sorted(a))
		return ;
	while (numel(a) > 3)
	{
		update_min_max(a);
		update_min_max(b);
		pb(a, b);
		if (b->v[b->head] < (b->size - 1) / 2)
			rb(b);
	}
	three_sort(a);
	push_back(a, b);
	update_min_max(a);
	if (dist_up(a, a->min_idx) < dist_down(a, a->min_idx))
	{
		while (a->head != a->min_idx)
			ra(a);
	}
	else
	{
		while (a->v[a->head] != a->min)
			rra(a);
	}
}
