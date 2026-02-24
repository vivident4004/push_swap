/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:03:23 by aflorea           #+#    #+#             */
/*   Updated: 2026/01/16 13:03:24 by aflorea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dio.h"

/**
 * @brief Esegue le rotazioni simultanee (rr o rrr)
 * @details Decrementa i contatori in t_cost e esegue le mosse doppie
 */
void	double_rot(t_pila *a, t_pila *b, t_cost *c)
{
	while (c->cost_a > 0 && c->cost_b > 0 && c->dir_a == c->dir_b)
	{
		if (c->dir_a == 1)
			rr(a, b);
		else
			rrr(a, b);
		c->cost_a--;
		c->cost_b--;
	}
}

// /**
//  * @brief Esegue le rotazioni rimanenti su A
//  */
// void	rot_a(t_pila *a, t_cost *c)
// {
// 	while (c->idx_a != a->head && c->total)
// 	{
// 		if (c->dir_a == 1)
// 			ra(a);
// 		else
// 			rra(a);
// 		c->total--;
// 	}
// }

// /**
//  * @brief esegue le rotazioni rimanenti su B
//  * @param b pila B
//  * @param c info sulla mossa
//  */
// void	rot_b(t_pila *b, t_cost *c)
// {
// 	while (c->idx_b != b->head && c->total)
// 	{
// 		if (c->dir_b == 1)
// 			rb(b);
// 		else
// 			rrb(b);
// 		c->total--;
// 	}
// }

/**
 * @brief Vecchia funzione principale di esecuzione delle mosse
 * @details Orchestra le rotazioni
 */
void	move(t_pila *a, t_pila *b, t_cost *c)
{
	if (c->dir_a == c->dir_b)
		double_rot(a, b, c);
	while (c->cost_a > 0)
	{
		if (c->dir_a == 1)
			ra(a);
		else
			rra(a);
		c->cost_a--;
	}
	while (c->cost_b > 0)
	{
		if (c->dir_b == 1)
			rb(b);
		else
			rrb(b);
		c->cost_b--;
	}
}

/**
 * @brief Funzione principale di esecuzione delle mosse
 * @details Orchestra le rotazioni nel tom_sort
 * @param s pila da ruotare
 * @param d pila di destinazione
 * @param c costo della mossa
 */
void	reverse_move(t_pila *s, t_pila *d, t_cost *c)
{
	if (c->dir_a == c->dir_b)
		double_rot(s, d, c);
	while (c->cost_b > 0)
	{
		if (c->dir_b == 1)
			ra(d);
		else
			rra(d);
		c->cost_b--;
	}
	while (c->cost_a > 0)
	{
		if (c->dir_a == 1)
			rb(s);
		else
			rrb(s);
		c->cost_a--;
	}
}
