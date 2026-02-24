/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:24:51 by aflorea           #+#    #+#             */
/*   Updated: 2026/01/22 15:24:52 by aflorea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dio.h"

/**
 * @brief Divide l'ingresso in una lista di stringhe
 * @details Divide ogni argomento in unità 
 * lessicali usando lo spazio come delimitatore
 * @param ac numero di argomenti
 * @param av array di argomenti
 * @return lista di unità lessicali
 */
t_list	*token(int ac, char **av)
{
	int		i;
	int		j;
	char	**mat;
	t_list	*lst;

	i = 1;
	lst = NULL;
	while (i < ac)
	{
		mat = ft_split(av[i], ' ');
		j = 0;
		while (mat[j])
		{
			ft_lstadd_back(&lst, ft_lstnew(mat[j]));
			j++;
		}
		free(mat);
		i++;
	}
	return (lst);
}

/**
 * @brief Controlla la validità dell'ingresso
 * @details Verifica che ogni stringa sia un numero valido
 * e non sia vuota o composta solo da un segno
 * @param lst lista di stringhe da controllare
 * @return 1 se l'ingresso è valido, 0 altrimenti
 */
int	check_input(t_list *lst)
{
	int	i;

	while (lst)
	{
		i = 0;
		if (lst->content[0] == '+' || lst->content[0] == '-')
			i++;
		if (!(lst->content[i]))
			return (0);
		while (lst->content[i])
		{
			if (lst->content[i] < '0' || lst->content[i] > '9')
				return (0);
			i++;
		}
		lst = lst->next;
	}
	return (1);
}

/**
 * @brief Controlla la presenza di numeri duplicati
 * @param v vettore dei numeri già inseriti
 * @param num_el numero di elementi già inseriti
 * @param n nuovo numero da controllare
 * @return 1 se il numero è duplicato, 0 altrimenti
 */
int	check_dup(int *v, int num_el, int n)
{
	int	i;

	i = 0;
	while (i < num_el)
	{
		if (v[i] == n)
			return (1);
		i++;
	}
	return (0);
}

void	init_stack(t_pila *a, t_pila *b, int *v, int n)
{
	a->v = v;
	a->size = n + 1;
	a->head = 0;
	a->tail = n;
	b->v = ft_calloc(n + 1, sizeof(int));
	b->size = n + 1;
	b->head = 0;
	b->tail = 0;
}

/**
 * @brief Inizializza le pile A e B con i numeri dell'ingresso
 * @details Converte le stringhe in numeri, controlla la validità
 * e li inserisce nella pila A. La pila B viene inizializzata vuota.
 * @param lst lista di stringhe da convertire e inserire
 * @param a pila A da inizializzare
 * @param b pila B da inizializzare
 */
void	parse_input(t_list *lst, t_pila *a, t_pila *b)
{
	long	l;
	int		*v;
	int		n;
	int		i;

	n = ft_lstsize(lst);
	v = ft_calloc(n + 1, sizeof(int));
	if (!v)
		return ;
	i = 0;
	while (lst)
	{
		l = ft_atol(lst->content);
		if (l > INT_MAX || l < INT_MIN || check_dup(v, i, (int)l))
		{
			free(v);
			return ;
		}
		v[i] = (int)l;
		i++;
		lst = lst->next;
	}
	init_stack(a, b, v, n);
}
