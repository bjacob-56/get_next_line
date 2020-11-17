/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 10:21:48 by bjacob            #+#    #+#             */
/*   Updated: 2020/11/17 10:21:48 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

int main()
{
    int     fd;
    char    *path;
    char    *line;
    int     i;
    int     res;

    printf("\n------ Début ------\n\n");

    printf("Buffer_size = %d\n", BUFFER_SIZE);

    path = "test3";
    fd = open(path, 'r');
    if (fd == -1)
        return (-1);

    printf("fd = %d\n\n", fd);
    i = 0;
 //   line = NULL;
 //   fd = 0;   // standard input
    while (i < 10)
    {
        res = get_next_line(fd, &line);
        printf("res = %d\n", res);
        if (res > 0)
            printf("line --> %s\n\n", line);
        else if (res == 0)
            printf("fin de fichier\n\n");
        else
            printf("erreur\n");
        i++;
    }

/*
    while (1)
    {

    }
*/
    close(fd);

    printf("\n\n------ Terminé ------\n");

}