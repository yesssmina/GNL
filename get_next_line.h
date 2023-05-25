/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:47:45 by sanaggar          #+#    #+#             */
/*   Updated: 2023/05/25 19:08:32 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h> //REMOVE FOR PUSH
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strchr(char	*s, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char	*s);
void	*ft_memset(void *b, int c, size_t len);
char	*read_and_stash(int fd, char *stash);

#endif