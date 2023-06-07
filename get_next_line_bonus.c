/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:52:35 by sanaggar          #+#    #+#             */
/*   Updated: 2023/06/07 17:41:29 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_and_stash(int fd, char *stash)
{
	char		*buff;
	int			rdb;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	rdb = 1;
	while (!(ft_strchr(stash, '\n')) && rdb != 0)
	{
		rdb = read(fd, buff, BUFFER_SIZE);
		if (rdb == -1)
		{
			free(stash);
			free(buff);
			return (NULL);
		}
		buff[rdb] = '\0';
		stash = ft_strjoin(stash, buff);
	}
	free(buff);
	return (stash);
}

char	*ft_line(char *stash)
{
	char		*str;
	int			i;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		str[i] = stash[i];
		i++;
	}
	if (stash[i] && stash[i] == '\n')
	{
		str[i] = stash[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*new_stash(char *stash)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (stash[i])
		str[j++] = stash[i++];
	str[j] = '\0';
	free(stash);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!stash[fd])
	{
		stash[fd] = malloc(sizeof(char));
		if (!stash)
			return (NULL);
		(stash[fd])[0] = '\0';
	}
	stash[fd] = read_and_stash(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = ft_line(stash[fd]);
	stash[fd] = new_stash(stash[fd]);
	return (line);
}

/*
int main()
{
    int     fd;
	int		fd1;
    int     i;
    char    *line;
	char    *line1;

    i = 1;
    fd = open("./test.txt", O_RDONLY);
	fd1 = open("./test2.txt", O_RDONLY);
    line = get_next_line(fd);
	line1 = get_next_line(fd1);
    while (line)
    {
        printf("%d%s%s\n", i, line, line1);
		free(line1);
        free(line);
        line = get_next_line(fd);
		line1 = get_next_line(fd1);
        i++;
    }
	free(line1);
    free(line);
    close(fd);
}*/