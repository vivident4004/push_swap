/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:31:22 by aflorea           #+#    #+#             */
/*   Updated: 2026/02/16 23:37:15 by aflorea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dio.h"

int	main(int ac, char **av)
{
	t_pila	a;
	t_pila	b;
	t_list	*lst;

	if (ac < 2)
		return (42);
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
	index_numbers(&a);
	tom_sort(&a, &b);
	free(a.v);
	free(b.v);
	return (0);
}
