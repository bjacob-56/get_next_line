#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int nb;

	nb = 0;
	while (*(str + nb) != '\0')
	{
		nb = nb + 1;
	}
	return (nb);
}

char    *ft_calloc(size_t nmemb)
{
    char    *res;
    size_t  i;

    if (!(res = malloc(sizeof(char) * nmemb)))
        return (NULL);
    i = 0;
    while (i < nmemb)
        res[i++] = '\0';
    return (res);
}

int     ft_freeline(char **line)
{
    free(*line);
    *line = NULL;
    return (0);
}