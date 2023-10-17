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

char	*res_handler(char *res, char *line, int text_end)
{
    if (!res)
		res = ft_calloc(1,1);
	if (!res || text_end == 1)
		return (NULL);
    if (res[0] != 0)
	{
		line = (char *)malloc(ft_strlen(res) + 1);
		if (line == NULL)
			return NULL;
		line = ft_strcpy(res, 0);
	}
	else
		line = ft_calloc(1,1);
	if (!line)
		return (NULL);
	else
		line = ft_calloc(1,1);
	if (!line)
		return (NULL);
	return (line);
}

char	*buf_handler(char *line, int *text_end, int fd)
{
	char	*buf;
	int		read_value;

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
		if (read_value == 0)
		{
			free(buf);
			*text_end = 1;
			buf = ft_calloc(1, 1);
		}
		buf[read_value] = '\0';
		return (buf);
}

char	*get_next_line(int fd)
{
	char			*line;
	char			*buf;
	static	char	*res;
	char			*temp;
	static int		text_end;
	int				newline;

	newline = 0;
	if (res_handler(res, line, text_end) == NULL)
		return (NULL);
	line = (res_handler(res, line, text_end));
	while (newline == 0)
	{
		buf = buf_handler(line, &text_end, fd);
		if (check_end(buf) < BUFFER_SIZE)
		{
			if (buf[check_end(buf)] == 0)
			{
				if (text_end == 1)
				{
					free(line);
					free(buf);
					return (NULL);
				}
				text_end = 1;
				return(strjoin(line, buf));
			}
			newline = 1;
			temp = res;
			res = add_resid(buf);
			free(temp);
		}
       	line = strjoin(line, buf);
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

