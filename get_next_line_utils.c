/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 18:10:03 by bjacob            #+#    #+#             */
/*   Updated: 2020/11/22 14:11:19 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(const char *str)
{
	int	nb;

	nb = 0;
	while (*(str + nb) != '\0')
	{
		nb = nb + 1;
	}
	return (nb);
}

char	*ft_calloc(size_t nmemb)
{
	char	*res;
	size_t	i;

	if (!(res = malloc(sizeof(char) * nmemb)))
		return (NULL);
	i = 0;
	while (i < nmemb)
		res[i++] = '\0';
	return (res);
}

void	ft_bzero(char *s, int n)
{
	int	i;

	i = 0;
	while (i < n)
		s[i++] = '\0';
}

int		ft_freeline(char **line)
{
	free(*line);
	*line = NULL;
	return (0);
}
