/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberes <dberes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:36:35 by dberes            #+#    #+#             */
/*   Updated: 2023/10/13 18:59:33 by dberes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	spaces;
	int		*array;
    int     i;

    i = 0;
	spaces = nmemb * size;
	if (spaces > INT_MAX)
		return (NULL);
	array = malloc(spaces);
	if (array == NULL)
		return (NULL);
    while (i < spaces)
    {
        array[i] = 0;
        i++;
    }
	return (array);
}

char	*get_next_line(int fd)
{
		char			*line;
		int				cnt;
		void			*buf;
		int				newline;
		static	char	*res;
		char			*temp;
		int				read_value;

		newline = 0;
		cnt = 10;
        if (!res)
            res = ft_calloc(1,1);
		if (!res)
			return (NULL);
		buf = (void *)malloc(cnt);
		if (!buf)
			return (NULL);
        if (res[0] != 0)
		{
			line = (char *)malloc(ft_strlen(res));
			if (line == NULL)
				return NULL;
			line = ft_strcpy(res, 0);
		}
		else
			line = ft_calloc(1,1);
		if (!line)
			return (NULL);
		while (newline == 0)
		{
			read_value = read(fd, buf, cnt);
			if (read_value == -1)
			{
				free (line);
				free (add_resid((char *)buf));
				free (buf);
				return (NULL);
			}
			if (check_end((char *)buf) < cnt)
			{
				newline = 1;
				temp = res;
				res = add_resid((char *)buf);
				free(temp);
			}
			temp = line;
        	line = strjoin(line, buf);
			free(temp);
			if (!line)
				return (NULL);
			
		}
		line[ft_strlen(line) + 1] = 0;
		free (buf);
		return (line);
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd = open("try.txt", O_RDONLY); 
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	int close(int fd);
}
