/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:52:42 by mel-hajj          #+#    #+#             */
/*   Updated: 2024/12/02 15:20:49 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}

char	*ft_strdup(const char *s)
{
	char	*x;
	size_t	l;
	int		i;

	l = ft_strlen(s);
	x = malloc(l + 1);
	if (!x)
		return (NULL);
	while (s[i])
	{
		x[i] = s[i];
		i++;
	}
	x[i] = 0;
	return (x);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	l;

	l = ft_strlen(src);
	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (l);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		j;
	int		i;
	char	*x;

	i = -1;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	x = malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!x)
		return (NULL);
	while (s1[++i])
		x[i] = s1[i];
	j = -1;
	while (s2[++j])
		x[i + j] = s2[j];
	x[i + j] = '\0';
	return (x);
}
