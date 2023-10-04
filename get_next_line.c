/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:36:35 by dberes            #+#    #+#             */
/*   Updated: 2023/10/04 15:06:37 by dberes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
		char		*line;
		int			cnt;
		void		*buf;
		int			i;

		i = 0;
		cnt = 10;
		buf = (void *)malloc(cnt);
		read(fd, buf, cnt);
		line = (char *)buf;
		read(fd, buf, cnt);
		line = line + (char *)buf;
		return (line);
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd = open("try.txt", O_RDONLY); 
	printf("%s", get_next_line(fd));
	int close(int fd);
}
