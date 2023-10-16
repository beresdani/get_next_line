/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberes <dberes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:36:35 by dberes            #+#    #+#             */
/*   Updated: 2023/10/16 11:06:48 by dberes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	spaces;
	char		*array;
    size_t	     i;

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
	char			*buf;
	int				newline;
	static	char	*res;
	char			*temp;
	int				read_value;

	newline = 0;
    if (!res)
		res = ft_calloc(1,1);
	if (!res)
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
		buf = (void *)malloc(BUFFER_SIZE * sizeof(char) + 1);
		if (!buf)
			return (NULL);
		read_value = read(fd, buf, BUFFER_SIZE);
		if (read_value == -1 || fd < 0)
		{
			free (line);
			free (buf);
			return (NULL);
		}
		if (check_end(buf) < BUFFER_SIZE)
		{
			if (buf[check_end(buf)] == 0)
				return(strjoin(line, buf));
			newline = 1;
			temp = res;
			res = add_resid(buf);
			free(temp);
		}
		buf[read_value] = '\0';
       	line = strjoin(line, buf);
		free (buf);
		if (!line)
			return (NULL);		
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
	printf("%s", get_next_line(fd));
	int close(int fd);
}
