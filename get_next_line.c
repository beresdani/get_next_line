/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberes <dberes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:36:35 by dberes            #+#    #+#             */
/*   Updated: 2023/10/06 20:20:18 by dberes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
		char		*line;
		int			cnt;
		void		*buf;
		int			i;

		i = 0;
		cnt = 10;
		line = "";
		buf = (void *)malloc(cnt);
		while (i < 3)
		{
			read(fd, buf, cnt);
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
