/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 20:07:43 by aflorea           #+#    #+#             */
/*   Updated: 2026/01/23 20:07:44 by aflorea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dio.h"

/**
 * @brief Trova l'elemento immediatamente precedente a quello scelto 
 * dalla pila A nella pila B
 * @details Ritorna l'indice della posizione dell'elemento
 */
// int	get_target(t_pila *b, int a)
// {
// 	int	i;
// 	int	ret_idx;

// 	if (a < b->min || a > b->max)
// 		return (b->max_idx);
// 	i = b->head;
// 	ret_idx = b->min_idx;
// 	while (i != b->tail)
// 	{
// 		if (b->v[i] > b->v[ret_idx] && b->v[i] < a)
// 		{
// 			ret_idx = i;
// 		}
// 		i = (i + 1) % b->size;
// 	}
// 	return (ret_idx);
// }

/**
 * @brief Trova l'elemento immediatamente precedente a quello scelto 
 * dalla pila B nella pila A
 * @details Ritorna l'indice della posizione dell'elemento
 */
int	get_reverse_target(t_pila *dst, int src_val)
{
	int	i;
	int	ret_idx;

	if (src_val < dst->min || src_val > dst->max)
		return (dst->min_idx);
	i = dst->head;
	ret_idx = dst->max_idx;
	while (i != dst->tail)
	{
		if (dst->v[i] > src_val && dst->v[i] < dst->v[ret_idx])
		{
			ret_idx = i;
		}
		i = (i + 1) % dst->size;
	}
	return (ret_idx);
}
