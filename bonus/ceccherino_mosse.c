/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceccherino_mosse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 18:18:17 by aflorea           #+#    #+#             */
/*   Updated: 2026/02/16 23:37:43 by aflorea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	s(t_pila *a, t_pila *b, char *mossa)
{
	if (mossa[1] == 'a')
		swap(a);
	else if (mossa[1] == 'b')
		swap(b);
	else if (mossa[1] == 's')
	{
		swap(a);
		swap(b);
	}
	else
		error_free_exit(a, b);
}

void	p(t_pila *a, t_pila *b, char *mossa)
{
	if (mossa[1] == 'a')
		push(a, b);
	else if (mossa[1] == 'b')
		push(b, a);
	else
		error_free_exit(a, b);
}

void	q(t_pila *a, t_pila *b, char *mossa)
{
	(void)a;
	(void)b;
	(void)mossa;
	error_free_exit(a, b);
}

void	r(t_pila *a, t_pila *b, char *mossa)
{
	if (mossa[1] == 'a')
		rotate(a);
	else if (mossa[1] == 'b')
		rotate(b);
	else if (mossa[1] == 'r')
	{
		if (mossa[2] == '\n')
		{
			rotate(a);
			rotate(b);
		}
		else if (mossa[2] == 'a')
			reverse_rotate(a);
		else if (mossa[2] == 'b')
			reverse_rotate(b);
		else if (mossa[2] == 'r')
		{
			reverse_rotate(a);
			reverse_rotate(b);
		}
		else
			error_free_exit(a, b);
	}
	else
		error_free_exit(a, b);
}
