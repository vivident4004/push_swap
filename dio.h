/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dio.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:39:18 by aflorea           #+#    #+#             */
/*   Updated: 2026/01/13 16:39:21 by aflorea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIO_H
# define DIO_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "./libft/libft.h"

// # define MAX(x, y) ((x) > (y) ? (x) : (y))

typedef struct s_pila
{
	int		*v;
	int		head;
	int		tail;
	int		size;
	int		max;
	int		max_idx;
	int		min;
	int		min_idx;
}	t_pila;

// struttura per calcolare il costo di spostamento di un singolo nodo
typedef struct s_cost
{
	int	idx_a;
	int	idx_b;
	int	cost_a;
	int	cost_b;
	int	dir_a;
	int	dir_b;
	int	total;
}	t_cost;

t_list	*token(int ac, char **av);
t_cost	find_cheapest(t_pila *a, t_pila *b);
void	sa(t_pila *a);
void	sb(t_pila *b);
void	ss(t_pila *a, t_pila *b);
void	pa(t_pila *a, t_pila *b);
void	pb(t_pila *a, t_pila *b);
void	ra(t_pila *a);
void	rb(t_pila *b);
void	rr(t_pila *a, t_pila *b);
void	rra(t_pila *a);
void	rrb(t_pila *b);
void	rrr(t_pila *a, t_pila *b);
void	double_rot(t_pila *a, t_pila *b, t_cost *c);
void	move(t_pila *a, t_pila *b, t_cost *c);
void	update_min_max(t_pila *s);
void	tom_sort(t_pila *a, t_pila *b);
void	reverse_move(t_pila *a, t_pila *b, t_cost *c);
void	error_free_exit(t_pila *a, t_pila *b);
void	error_exit(void);
void	parse_input(t_list *lst, t_pila *b, t_pila *a);
void	init_stack(t_pila *a, t_pila *b, int *v, int n);
void	index_numbers(t_pila *s);
// void	stampa_v(t_pila *p);
// void	greedy_sort(t_pila *a, t_pila *b);
long	ft_atol(const char *nptr);
int		get_reverse_target(t_pila *b, int a);
int		numel(t_pila *p);
int		dist_up(t_pila *s, int idx);
int		dist_down(t_pila *s, int idx);
int		is_empty(t_pila *s);
int		check_sorted(t_pila *a);
int		max(int x, int y);
int		check_input(t_list *lst);
int		check_dup(int *v, int num_el, int n);
// int		get_target(t_pila *b, int a);

#endif