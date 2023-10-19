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

unsigned long	check_len(char *str)
{
	unsigned long	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != 0)
		i++;
	return (i);
}

char	*res_cpy(char *str2, int i)
{
	int		j;
	int		k;
	char	*str1;

	j = 0;
	k = i;
	while (str2 && str2[k] != '\n')
		k++;
	str1 = malloc((k + 1 - i) * sizeof(char) + 1);
	if (str1 == NULL)
		return (NULL);
	while (j < k - i + 2)
	{
		str1[j] = str2[i];
		i++;
		j++;
	}
	str1[j] = 0;
	return (str1);
}

char	*trim_buf(char **str)
{
	char	*resid;
	int		i;
	int		j;

	i = check_end(str);
	j = 0;
	if (i != BUFFER_SIZE && *str)
	{
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
	}
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
