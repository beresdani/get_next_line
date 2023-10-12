/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberes <dberes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:36:35 by dberes            #+#    #+#             */
/*   Updated: 2023/10/10 15:07:22 by dberes           ###   ########.fr       */
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
		int				i;
		static	char	*res;

		i = 0;
		cnt = 10;
		line = ft_calloc(1, 1);
		buf = (void *)malloc(cnt);
		while (i < 3)
		{
			read(fd, buf, cnt);
			if (add_resid((char *)buf)[0] != 0)
			{
				res = (char *)malloc((cnt - ft_strlen(add_resid((char *)buf))) * sizeof(char));
				if (res == NULL)
					return NULL;
				res = add_resid((char *)buf);
			}
			if (line[0] == 0 && res[0] != 0)
			{
				line = (char *)malloc(ft_strlen(res));
				if (line == NULL)
					return NULL;
				line = ft_strcpy(res, 0);
			}
        	line = strjoin(line, buf);
			i++;
		}
		return (line);
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd = open("try.txt", O_RDONLY); 
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	/*printf("%s", get_next_line(fd));*/
	int close(int fd);
}
