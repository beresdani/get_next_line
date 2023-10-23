/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:24:42 by dberes            #+#    #+#             */
/*   Updated: 2023/10/23 16:24:49 by dberes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_len(char **str)
{
	int	i;

	i = 0;
	if (!*str)
		return (0);
	while ((*str)[i] != 0)
		i++;
	return (i);
}

char	*trim_buf(char **str)
{
	char	*resid;
	int		i;
	int		j;

	if (!*str)
		return (NULL);
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
	int	len;

	i = 0;
	len = check_len(str);
	while (i < len && *str)
	{
		if ((*str)[i] == 0)
			return (i);
		else if (i < len && (*str)[i] == '\n')
			return (i + 1);
		i++;
	}
	return (len);
}

char	*strjoin(char *existing, char **extra)
{
	int				i;
	int				j;
	char			*line;

	if (!existing && !*extra)
		return (NULL);
	line = (char *)malloc(check_len(&existing) + check_end(extra) + 1);
	if (line == NULL)
		return (free_str(&existing), NULL);
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
