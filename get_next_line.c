/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouloube <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 18:06:29 by aouloube          #+#    #+#             */
/*   Updated: 2015/12/28 12:35:25 by aouloube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

char	*ft_removestrstr(int size, char *s1)
{
	char	*str;
	int		i;

	str = ft_strnew(ft_strlen(s1) - size);
	str = ft_strsub(s1, size + 1, ft_strlen(s1));
	return (str);
}

char	*ft_get_line(char *s1)
{
	char	*str;
	int		i;

	while (s1[i] != '\n' && s1[i])
		i++;
	str = ft_strnew(i);
	i = 0;
	while (s1[i] != '\n' && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	return (str);
}

int		get_next_line(int fd, char **line)
{
	int			buff = -1;
	static char		*storage = NULL;
	char	*tmp;

	*line = NULL;
	tmp = ft_strnew(buff);
	if (!storage)
		storage = ft_strnew(buff);
	while (read(fd, tmp, buff) && !ft_strstr(tmp, "\n"))
	{
		storage = ft_strjoin(storage, tmp);
	}
	storage = ft_strjoin(storage, tmp);
	*line = ft_get_line(storage);
	storage =  ft_removestrstr(ft_strlen(*line), storage);
	return (0);
}



int main(int argc, char **argv)
{
	char *line;
	int fd;

	fd = open(argv[1], O_RDONLY);
	/*while (get_next_line(fd, &line) > 0)
	{
		printf("[%s]\n", line);
	}*/
	get_next_line(fd, &line);
	printf("[%s]\n", line);
	get_next_line(fd, &line);
	printf("[%s]\n", line);
	get_next_line(fd, &line);
	printf("[%s]\n", line);
	get_next_line(fd, &line);
	printf("[%s]\n", line);
	printf("****%d****", get_next_line(fd, &line));
	printf("[%s]\n", line);
	close(fd);
}
