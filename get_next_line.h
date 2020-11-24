/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 08:53:40 by bjacob            #+#    #+#             */
/*   Updated: 2020/11/24 08:56:35 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int		init_gnl(int fd, char **line);
int		ft_buffer_to_line(char **line, char *buffer);
void	ft_crop_buffer(char *buffer, int i_b);
int		ft_add_line(char **line, char *buffer);
int		get_next_line(int fd, char **line);

int		ft_strlen(const char *str);
char	*ft_calloc(size_t nmemb);
void	ft_bzero(char *s, int n);
int		ft_freeline(char **line);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32 // a garder ?? ////////
# endif

#endif
