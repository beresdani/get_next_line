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

char	*buf_handler(int *te, int fd)
{
	char	*buf;
	int		read_value;

	buf = (char *)malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!buf)
		return (NULL);
	read_value = read(fd, buf, BUFFER_SIZE);
	if (read_value == -1 || fd < 0)
	{
		free_str(&buf);
		return (NULL);
	}
	if (read_value == 0)
	{
		free_str(&buf);
		*te = 1;
	}
	if (buf)
		buf[read_value] = '\0';
	return (buf);
}

char	*l_ha(char *line, int *te, char **buf, int *nl)
{
	int	len;

	len = check_len(buf);
	if (*buf)
	{ 
		if(check_end(buf) < len || (*buf)[len - 1] == '\n' || len < BUFFER_SIZE)
		{
        	*nl = 1;
			if (buf && len < BUFFER_SIZE)
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
	    	*buf = trim_buf(buf);
			if (check_end(buf) < len || len < BUFFER_SIZE)
				free_str(buf);
	    	return (line);
		}
	}
	if (*buf)
		line = strjoin(line, buf);
	free_str(buf);
	return (line);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*buf;
	int				te;
	int				nl;

	nl = 0;
	te = 0;
    line = NULL;
	while (nl == 0)
	{
        if (check_end(&buf) == 0 || check_end(&buf) == check_len(&buf))
		    buf = buf_handler(&te, fd);
		line = l_ha(line, &te, &buf, &nl);
		if (te == 1)
 			return (line);
 		if (!line)
			return (NULL);
	}
	return (line);
}

/*
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
	

	int close(int fd);
}
*/