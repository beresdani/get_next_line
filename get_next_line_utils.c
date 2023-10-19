/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberes <dberes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:09:50 by dberes            #+#    #+#             */
/*   Updated: 2023/10/19 17:23:40 by dberes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_len(char *str)
{
	unsigned long	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != 0)
		i++;
	return (i);
}

char	*trim_buf(char **str)
{
	char	*resid;
	int		i;
	int		j;

	i = check_end(str);
	j = 0;
	
	resid = (char *)malloc(BUFFER_SIZE - i + 1);
	if (resid == NULL)
		return (NULL);
	while (i < BUFFER_SIZE && (*str)[i])
	{
		resid[j] = (*str)[i];
		i++;
		j++;
	}
	resid[j] = 0;
    return (resid);
}

int	check_end(char **str)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE && *str)
	{
		if ((*str)[i] == 0)
			return (i);
		else if ((*str)[i] == '\n')
			return (i + 1);
		i++;
	}
	return (BUFFER_SIZE);
}

char	*strjoin(char *existing, char **extra)
{
	int				i;
	int				j;
	char			*line;

	if (!existing && !*extra)
		return (NULL);
	line = (char *)malloc(check_len(existing) + check_end(extra) + 1);
	if (line == NULL)
		return (NULL);
	i = 0;
	while (existing && existing[i] != 0)
	{
		line[i] = existing[i];
		i++;
	}
	j = 0;
	while (*extra && j < check_end(extra))
	{
		line[i] = (*extra)[j];
		i++;
		j++;
	}
	line[i] = 0;
	free_str(&existing);
	return (line);
}
