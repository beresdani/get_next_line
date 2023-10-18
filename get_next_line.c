/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberes <dberes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:36:35 by dberes            #+#    #+#             */
/*   Updated: 2023/10/18 14:28:47 by dberes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void 	free_str(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}
/*void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	spaces;
	char	*array;
    size_t	i;

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
}*/

char	*res_handler(char **res, char *line, int te)
{
	if (!*res || te == 1)
		return (NULL);
	if ((*res)[0] != 0)
	{
		line = (char *)malloc(ft_strlen(*res) + 1);
		if (line == NULL)
			return (NULL);
		line = ft_strcpy(*res, 0);
		free_str (res);
		return (line);
	}
	free_str (res);
	return (line);
}

char	*buf_handler(char *line, int *te, int fd)
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
		*te = 1;
		buf = NULL;
	}
	buf[read_value] = '\0';
	return (buf);
}

char	*l_ha(char *line, char **res, int *te, char *buf)
{
	char	*temp;

	if (check_end(buf) < BUFFER_SIZE)
	{
		if (buf[check_end(buf)] == 0)
		{
			if (*te == 1)
			{
				free(line);
				free(buf);
				return (NULL);
			}
			*te = 1;
			return (strjoin(line, buf));
		}
		temp = *res;
		free(temp);
		temp = add_resid(buf);
		if (temp != NULL)
			*res = temp;
	}
	return (strjoin(line, buf));
}

char	*get_next_line(int fd)
{
	char			*line;
	char			*buf;
	static char		*res;
	static int		te;
	int				nl;

	nl = 0;
	line = (res_handler(&res, line, te));
	while (nl == 0)
	{
		buf = buf_handler(line, &te, fd);
		if (check_end(buf) < BUFFER_SIZE)
			nl = 1;
		line = l_ha(line, &res, &te, buf);
		if (te == 1)
			return (line);
		if (!line || !buf)
			return (NULL);
	}
	return (line);
}


#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	
	int	fd = open("try.txt", O_RDONLY); 
	char *temp;
	temp = get_next_line(fd);
	printf("%s", temp);
	if (temp)
		free(temp);
	temp = get_next_line(fd);
	printf("%s", temp);
	if (temp)
		free(temp);
	temp = get_next_line(fd);
	printf("%s", temp);
	if (temp)
		free(temp);
	int close(int fd);
}

