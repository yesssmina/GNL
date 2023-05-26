/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:56:50 by sanaggar          #+#    #+#             */
/*   Updated: 2023/05/26 14:35:40 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_stash(int fd, char *stash)
{
	char		*buff;
	int			rdb;
	char		*tmp;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	rdb = 1;
	while (!(ft_strchr(stash, '\n')) && rdb != 0)
	{
		rdb = read(fd, buff, BUFFER_SIZE);
		if (rdb == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rdb] = '\0';
		tmp = ft_strjoin(stash, buff);
		free(stash);
		stash = tmp;
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
	if (stash[i] == '\n')
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
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!stash)
	{
		stash = malloc(sizeof(char));
		stash[0] = '\0';
	}
	stash = read_and_stash(fd, stash);
	if (!stash)
	{
		free(stash);
		return (NULL);
	}
	line = ft_line(stash);
	stash = new_stash(stash);
	return (line);
}

//int main()
//{
//    int     fd;
//    int     i;
//    char    *line;

//    i = 1;
//    fd = open("./test.txt", O_RDONLY);
//    line = get_next_line(fd);
//    while (line)
//    {
//        //printf("%d%s\n", i, line);
//		printf("%s", line);
//        free(line);
//        line = get_next_line(fd);
//        i++;
//    }
//    free(line);
//    close(fd);
//    //system("leaks a.out");
//}