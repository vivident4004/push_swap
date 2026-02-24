/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:02:09 by aflorea           #+#    #+#             */
/*   Updated: 2026/01/16 13:02:13 by aflorea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dio.h"

/**
 * @brief Calcola il costo per muovere entrambe le pile verso l'alto (RA, RB)
 * @details Riempie la struttura solo se questo costo è minore del precedente
 */
static void	cost_concord_up(t_cost *c, t_pila *a, t_pila *b)
{
	int	dist_a;
	int	dist_b;
	int	total;

	dist_a = dist_up(a, c->idx_a);
	dist_b = dist_up(b, c->idx_b);
	if (dist_a > dist_b)
		total = dist_a;
	else
		total = dist_b;
	if (total < c->total)
	{
		c->cost_a = dist_a;
		c->cost_b = dist_b;
		c->dir_a = 1;
		c->dir_b = 1;
		c->total = total;
	}
}

/**
 * @brief Calcola il costo per muovere entrambe le pile verso il basso (RRA, RRB)
 * @details Riempie la struttura solo se questo costo è minore del precedente
 */
static void	cost_concord_down(t_cost *c, t_pila *a, t_pila *b)
{
	int	dist_a;
	int	dist_b;
	int	total;

	dist_a = dist_down(a, c->idx_a);
	dist_b = dist_down(b, c->idx_b);
	if (dist_a > dist_b)
		total = dist_a;
	else
		total = dist_b;
	if (total < c->total)
	{
		c->cost_a = dist_a;
		c->cost_b = dist_b;
		c->dir_a = -1;
		c->dir_b = -1;
		c->total = total;
	}
}

/**
 * @brief calcola i costi misti (RA/RRB e RRA/RB)
 * @details controlla le combinazioni incrociate e salva in c se sono migliori
 */
static void	cost_mixed(t_cost *c, t_pila *a, t_pila *b)
{
	int	dist_up_a;
	int	dist_up_b;
	int	dist_down_a;
	int	dist_down_b;

	dist_up_a = dist_up(a, c->idx_a);
	dist_up_b = dist_up(b, c->idx_b);
	dist_down_a = dist_down(a, c->idx_a);
	dist_down_b = dist_down(b, c->idx_b);
	if (dist_up_a + dist_down_b < c->total)
	{
		c->cost_a = dist_up_a;
		c->cost_b = dist_down_b;
		c->dir_a = 1;
		c->dir_b = -1;
		c->total = dist_up_a + dist_down_b;
	}
	else if (dist_down_a + dist_up_b < c->total)
	{
		c->cost_a = dist_down_a;
		c->cost_b = dist_up_b;
		c->dir_a = -1;
		c->dir_b = 1;
		c->total = dist_down_a + dist_up_b;
	}
}

/**
 * @brief Funzione d'incarto che chiama le tre funzioni di costo 
 * per trovare la mossa ottima
 * @details popola t_cost con la strategia migliore per il nodo corrente
 * @param src pila sorgente
 * @param dst pila destinazione
 * @param idx_a indice dell'elemento in src attualmente considerato
 * @return una struttura t_cost con la strategia vincente
 */
static t_cost	best_cost(t_pila *src, t_pila *dst, int src_idx)
{
	t_cost	best;

	best.total = INT_MAX;
	best.idx_a = src_idx;
	best.idx_b = get_reverse_target(dst, src->v[src_idx]);
	cost_concord_up(&best, src, dst);
	cost_concord_down(&best, src, dst);
	cost_mixed(&best, src, dst);
	return (best);
}

/**
 * @brief Scorre tutta la pila sorgente e trova la mossa piú economica
 * @details Chiama best_cost per ogni elemento di src e tiene il migliore
 * @param src pila sorgente
 * @param dst pila destinazione
 * @return La struttura t_cost a costo minore
 */
t_cost	find_cheapest(t_pila *src, t_pila *dst)
{
	int		i;
	t_cost	curr;
	t_cost	best;

	best.total = INT_MAX;
	i = src->head;
	while (i != src->tail)
	{
		curr = best_cost(src, dst, i);
		if (curr.total < best.total)
			best = curr;
		if (best.total == 0)
			return (best);
		i = (i + 1) % src->size;
	}
	return (best);
}
