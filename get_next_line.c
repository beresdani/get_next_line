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

char	*l_ha(char *line, char **buf, int *nl)
{
	int	len;
	char *temp;

	len = check_len(buf);
	if (len != 0)
	{ 
		if(check_end(buf) != len || (*buf)[len - 1] == 10 )
		{
        	*nl = 1;
        	line = strjoin(line, buf);
			temp = *buf;
	    	*buf = trim_buf(buf);
			free_str(&temp);
	    	return (line);
		}
	}
	else
	{
		free_str(buf);
		return (NULL);
	}
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
        if (!buf || check_end(&buf) == BUFFER_SIZE)
		{
			free_str(&buf);
		    buf = buf_handler(&te, fd);
			if (buf == NULL)
			{
				free_str(&buf);
				return (line);
			}
		}
		if (te == 0)
			line = l_ha(line, &buf, &nl);
		if (te == 1)
		{
			free_str(&buf);
 			return (line);
		}
	}
	return (line);
}

/*
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char *str;

	str = "kaki";
	
	int	fd = open(&str, O_RDONLY);
	
	char *temp;

	temp = get_next_line(fd);
	while (temp != NULL)
	{
		printf("%s", temp);
		temp = get_next_line(fd);
	}
	printf("%s", temp);
	free(temp);
	int close(int fd);
	return (0);
}
*/