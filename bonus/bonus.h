/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:39:18 by aflorea           #+#    #+#             */
/*   Updated: 2026/02/01 19:13:21 by aflorea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../dio.h"

// typedef struct s_mossa
// {
// 	char	*nome_mossa;
// 	void	(*f)(t_pila);
// 	void	(*g)(t_pila, t_pila);
// }	t_mossa;

void	s(t_pila *a, t_pila *b, char *mossa);
void	p(t_pila *a, t_pila *b, char *mossa);
void	q(t_pila *a, t_pila *b, char *mossa);
void	r(t_pila *a, t_pila *b, char *mossa);
void	rotate(t_pila *s);
void	reverse_rotate(t_pila *s);
void	push(t_pila *s1, t_pila *s2);
void	swap(t_pila *s);

#endif