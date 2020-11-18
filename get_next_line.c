/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 10:22:30 by bjacob            #+#    #+#             */
/*   Updated: 2020/11/17 10:22:30 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int init_gnl(int fd, char **line)
{
    if (!line || fd < 0 || !BUFFER_SIZE)
    {
        *line = NULL;
        return (-1);
    }
    if (!(*line = ft_calloc(BUFFER_SIZE + 1)))
        return (-1);
    return (1);
}

///// ---------- /////

int ft_buffer_to_line(char **line, char *buffer)
{
	int		i;
    int     end_line;

	i = 0;
    end_line = 2;
	while (buffer[i] != '\n' && buffer[i])
	{
		(*line)[i] = buffer[i];
		i++;
	}
	(*line)[i] = '\0';
    if (buffer[i] == '\n')
        end_line = 1;
    ft_crop_buffer(buffer, i + 1);
    return (end_line);
}

///// ---------- /////

void    ft_crop_buffer(char *buffer, int i_b)
{
    int i;

    i = 0;
    if (i_b < BUFFER_SIZE + 1)
    {
        while (buffer[i_b + i])
        {
            buffer[i] = buffer[i_b + i];
            i++;
        }
    }
    while (i < BUFFER_SIZE + 1)
        buffer[i++] = '\0';
}

///// ---------- /////

int ft_add_line(char **line, char *buffer)
{
    int end_line;
    int i_l;
    int i_b;
    char    *str_temp;

    i_l = -1;
    i_b = 0;
    end_line = 2;
    str_temp = *line;
    if (!(*line = ft_calloc(ft_strlen(*line) + BUFFER_SIZE + 1)))
        return (-1);
    while ((str_temp)[++i_l])
        (*line)[i_l] = str_temp[i_l];
    while (buffer[i_b] != '\n' && buffer[i_b])
    {
        (*line)[i_l + i_b] = buffer[i_b];
        i_b++;
    }
    if (buffer[i_b] == '\n')
        end_line = 1;
    ft_crop_buffer(buffer, i_b + 1);
    free(str_temp);
    return (end_line);
}

///// ---------- /////

int get_next_line(int fd, char **line)
{
    static char buffer[BUFFER_SIZE + 1];
    int         size;

    if (init_gnl(fd, line) == -1)
        return (-1);
    if (buffer[0])
        if (ft_buffer_to_line(line, buffer) == 1)
            return (1);
    size = 1;
    while (size > 0)
    {
        size = read(fd, buffer, BUFFER_SIZE);
        if (size == -1)
        {
            ft_freeline(line);
            return(-1);
        }
        if (ft_add_line(line, buffer) == 1)
            return (1);
    }
//    if (!**line) // a voir si on return 0 sur la derniere ligne a lire ou juste apres   
        return (0);
    return (1);
}