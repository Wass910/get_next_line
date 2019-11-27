/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 18:17:30 by idhiba            #+#    #+#             */
/*   Updated: 2019/11/17 18:17:37 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>

void	ft_dest(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (src[i] != '\0' && src[i] != '\n')
		i++;
	if (src[i])
		i++;
	while (src[i] != '\0')
		dest[j++] = src[i++];
	dest[i] = '\0';
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

char			*ft_strjoin(char *s1, char *s2)
{
	int		e;
	int		i;
	char	*str;

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
	str[i] = '\0';
	return (str);
}

int		ft_count_fin(char *s1, int ret)
{
	int i;
	int e;

	i = 0;
	e = 0;
	while (s1[i] != '\0')
		i++;
	while (e <= ret)
	{
		e++;
		i++;
	}
	i = i + 2;
	return (i);
}

char			*ft_strjoin_fin(char *s1, char *s2, int ret)
{
	int		e;
	int		i;
	char	*str;

	e = 0;
	i = ft_count_fin(s1, ret);
	if (!(str = malloc(sizeof(*str) * i)))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (e <= ret)
	{
		str[i] = s2[e];
		i++;
		e++;
	}
	str[i] = '\0';
	return (str);
}