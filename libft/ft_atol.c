/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 12:17:31 by aflorea           #+#    #+#             */
/*   Updated: 2026/01/24 12:17:32 by aflorea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dio.h"

long	ft_atol(const char *nptr)
{
	int		segno;
	long	n;

	segno = 1;
	n = 0;
	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			segno = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		n = n * 10 + (*nptr++ - '0');
		if ((n * segno > INT_MAX) || (n * segno < INT_MIN))
			return (n);
	}
	return (n * segno);
}
