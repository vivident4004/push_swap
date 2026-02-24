/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 17:07:23 by aflorea           #+#    #+#             */
/*   Updated: 2025/11/26 18:18:13 by aflorea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dio.h"

static char	*ft_estrai(int start, int end, const char *s)
{
	char	*t;
	size_t	len;
	size_t	i;

	len = end - start;
	t = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		t[i] = s[start + i];
		i++;
	}
	t[len] = '\0';
	return (t);
}

static int	ft_conta_parole(char const *s, char c)
{
	char	*tmp;
	int		i;
	int		count;

	tmp = (char *)s;
	i = 0;
	count = 0;
	while (tmp[i])
	{
		while (tmp[i] && tmp[i] == c)
			i++;
		if (tmp[i] && tmp[i] != c)
		{
			count++;
			while (tmp[i] && tmp[i] != c)
				i++;
		}
	}
	return (count);
}

static char	**ft_bomba_libera_tutti(char **mat, size_t righe)
{
	size_t	i;

	i = 0;
	while (i < righe)
	{
		free(mat[i]);
		i++;
	}
	free(mat);
	return (NULL);
}

static int	ft_gastani_frinzi(char const *s, char c, size_t *start, size_t *j)
{
	while (s[*j] == c && s[*j])
		(*j)++;
	if (!s[*j])
		return (42);
	*start = *j;
	while (s[*j] && s[*j] != c)
		(*j)++;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**mat;
	size_t	count;
	size_t	start;
	size_t	j;
	size_t	m;

	count = ft_conta_parole(s, c);
	mat = (char **)malloc(sizeof(char *) * (count + 1));
	if (!mat)
		return (NULL);
	start = 0;
	j = 0;
	m = 0;
	while (count > 0)
	{
		if (ft_gastani_frinzi(s, c, &start, &j) == 42)
			break ;
		mat[m] = ft_estrai(start, j, s);
		if (!mat[m])
			return (ft_bomba_libera_tutti(mat, m));
		m++;
		count--;
	}
	mat[m] = NULL;
	return (mat);
}
