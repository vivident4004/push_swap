/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceccherino.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 17:02:31 by aflorea           #+#    #+#             */
/*   Updated: 2026/02/16 23:37:36 by aflorea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	ft_trova_mossa(t_pila *a, t_pila *b, char *mossa)
{
	if (mossa[0] == 's')
		s(a, b, mossa);
	else if (mossa[0] == 'p')
		p(a, b, mossa);
	else if (mossa[0] == 'E')
		q(a, b, mossa);
	else if (mossa[0] == 'r')
		r(a, b, mossa);
	else
		error_free_exit(a, b);
}

static void	ft_verificatore(t_pila *a, t_pila *b)
{
	char	mossa[6];
	int		i;

	i = 0;
	while (read(0, &mossa[i], 1))
	{
		if (mossa[i] == '\n')
		{
			mossa[i + 1] = '\0';
			ft_trova_mossa(a, b, mossa);
			i = -1;
		}
		else if (i >= 4)
			error_free_exit(a, b);
		i++;
	}
}

static int	ft_controlla_ordinato(t_pila *a, t_pila *b)
{
	int	i;

	if (!is_empty(b))
		return (0);
	if (numel(a) == 1)
		return (1);
	i = a->head;
	while ((i + 1) % a->size != a->tail)
	{
		if (a->v[i] > a->v[(i + 1) % a->size])
			return (0);
		i = (i + 1) % a->size;
	}
	return (1);
}

static void	stampatore(int res)
{
	if (res)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_pila	a;
	t_pila	b;
	t_list	*lst;

	if (ac < 2)
		return (0);
	a.v = NULL;
	b.v = NULL;
	lst = token(ac, av);
	if (!lst)
		error_exit();
	if (!check_input(lst))
	{
		ft_lstclear(&lst, free);
		error_exit();
	}
	parse_input(lst, &a, &b);
	ft_lstclear(&lst, free);
	if (!a.v)
		error_exit();
	ft_verificatore(&a, &b);
	stampatore(ft_controlla_ordinato(&a, &b));
	free(a.v);
	free(b.v);
	return (0);
}
