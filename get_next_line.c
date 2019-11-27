/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 18:17:13 by idhiba            #+#    #+#             */
/*   Updated: 2019/11/17 18:17:15 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>

int		ft_count_suivant(char *s1, char *s2, int ret)
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
	}
    e = e - ret;
	i = i + e + 2;
	return (i);
}

char			*ft_strjoin_suivant(char *s1, char *s2, int ret)
{
	int		i;
	char	*str;

	i = ft_count_suivant(s1, s2, ret);
	if (!(str = malloc(sizeof(*str) * i)))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[ret] != '\0')
	{
		str[i] = s2[ret];
		i++;
		ret++;
	}
	str[i] = '\0';
	return (str);
}

int check_line(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '\n')
            return (i);
        i++;
    }
    return (0);
}

int read_line(int fd, char **line, char *dest)
{
    int             ret;
    char            str[BUFFER_SIZE +1];
    int             i;

    /*if (!(str = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
        return (-1);*/
    if (!(*line = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
        return (-1);
    i = 0;
    if (dest[i] != '\0')
    {
        while (dest[i] != '\0')
        {
            (*line)[i] = dest[i];
            i++;
        }
    }

    while ((ret = read(fd, str, BUFFER_SIZE)))
    {

        if (ret == BUFFER_SIZE)
        {
            str[ret] = '\0';
            if ((check_line(str)) == 0)
            {
                dest = ft_strjoin(dest, str);
            }
            if ((i = check_line(str)) > 0)
            {
                *line = ft_strjoin_fin(dest, str, i);
                ft_dest(dest, str);
                return (1);
            }  
            /*if (ret < BUFFER_SIZE)
            {
                str[ret] = '\0';
                //printf("%s\n", str);  
                //free(str); 
                return (0);
            }*/
        }
    }
    return (-1);
}

int get_next_line(int fd, char **line)
{
    static char *dest;

    if (!dest)
        if (!(dest = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
            return (-1);
    if (fd == -1 || !line || BUFFER_SIZE <= 0)
		return (-1);
    if (read_line(fd, line, dest) == 1)
        return (1);
    else if ((read_line(fd, line, dest) == 0))
        return (0);
    return (-1);
}
int main()
{
    char  *line;
    int   fd;
    int ret= 0;

    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
        return (1);
    //while ((get_next_line(fd, &line)) == 1)
    while ((ret = get_next_line(fd, &line)) == 1)
    {
        printf("ret = %d, %s\n", ret, line);
    }
    return (0);
}