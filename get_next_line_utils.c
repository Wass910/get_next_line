/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 18:17:30 by idhiba            #+#    #+#             */
/*   Updated: 2020/09/24 13:57:20 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*str;

	if (!s || !*s || start > ft_strlen(s))
		return (ft_strdup(""));
	i = 0;
	if (!(str = malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	*ft_calloc(int count, int size)
{
	void			*result;
	unsigned char	*tmp;
	int				i;
	int				n;

	i = 0;
	if (count == 0)
		return (ft_strdup(""));
	if (!(result = malloc(count * size)))
		return (NULL);
	tmp = result;
	n = count * size;
	while (n > 0)
	{
		*tmp = (unsigned char)i;
		tmp[i] = '\0';
		tmp++;
		n--;
	}
	return (result);
}

char	*ft_strchr(char *s, int c)
{
	int		i;
	int		a;

	a = 0;
	i = 0;
	while (s[a] != '\0')
		a++;
	if (c == '\0')
		return (s + a);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}
	return (NULL);
}

int		ft_count(char *s1, char *s2)
{
	int i;
	int e;

	i = 0;
	e = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[e] != '\0')
	{
		e++;
		i++;
	}
	i = i + 2;
	return (i);
}

char	*ft_strjoin_free(char *s1, char *s2, int f)
{
	int		e;
	int		i;
	char	*str;

	f = 0;
	e = 0;
	i = ft_count(s1, s2);
	if (!(str = malloc(sizeof(*str) * i)))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[e] != '\0')
	{
		str[i] = s2[e];
		i++;
		e++;
	}
	free(s1);
	str[i] = '\0';
	return (str);
}
