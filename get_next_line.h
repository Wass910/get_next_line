/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 18:17:19 by idhiba            #+#    #+#             */
/*   Updated: 2019/11/17 18:17:21 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE 
# define BUFFER_SIZE 5
#endif

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/uio.h>


int get_next_line(int fd, char **line);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strjoin_fin(char *s1, char *s2, int ret);			
void	ft_dest(char *dest, char *src);

#endif