/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberes <dberes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:36:35 by dberes            #+#    #+#             */
/*   Updated: 2023/10/19 17:25:39 by dberes           ###   ########.fr       */
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
/*
char	*res_handler(char **res, int te)
{
	char *line;

	line = NULL;
	if (!*res || te == 1)
		return (NULL);
	if (*res && (*res)[0] != 0)
	{
		line = (char *)malloc(check_len(*res) + 1);
		if (line == NULL)
			return (NULL);
		line = res_cpy(*res, 0);
		free_str (res);
		return (line);
	}
	free_str (res);
	return (line);
}
*/

char	*buf_handler(char *line, int *te, int fd)
{
	char	*buf;
	int		read_value;

	buf = (char *)malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!buf)
		return (NULL);
	read_value = read(fd, buf, BUFFER_SIZE);
	if (read_value == -1 || fd < 0)
	{
		free_str(&line);
		free_str(&buf);
		return (NULL);
	}
	if (read_value == 0)
	{
		free_str(&buf);
		*te = 1;
		buf = NULL;
	}
	if (buf)
		buf[read_value] = '\0';
	return (buf);
}

char	*l_ha(char *line, int *te, char **buf, int *nl)
{
	char	*temp;

	if (check_end(buf) < check_len(*buf))
	{
        *nl = 1;
		if (buf && buf[check_end(buf)] == 0)
		{
			if (*te == 1)
			{
				free_str(&line);
				free_str(buf);
				return (NULL);
			}
			*te = 1;
		}
        line = strjoin(line, buf);
	    temp = trim_buf(buf);
        *buf = temp;
	    return (line);
	}
    line = strjoin(line, buf);
    *buf = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*buf;
	static int		te;
	int				nl;

	nl = 0;
	/*line = (res_handler(&res, te));*/
    line = NULL;
	while (nl == 0)
	{
        if (check_end(&buf) == 0 || check_end(&buf) == BUFFER_SIZE)
		    buf = buf_handler(line, &te, fd);
		line = l_ha(line, &te, &buf, &nl);
		if (te == 1)
        {
            te = 0;
			return (line);
        }
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
