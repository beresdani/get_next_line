/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberes <dberes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:42:23 by dberes            #+#    #+#             */
/*   Updated: 2023/10/10 15:03:55 by dberes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

char				*get_next_line(int fd);
unsigned long		ft_strlen(char *str);
char				*strjoin(char *exisiting, char *extra);
int					check_end(char *str);
char				*add_resid(char *str);
void                *ft_calloc(size_t nmemb, size_t size);
char	            *ft_strcpy(char *str2, int i);
#endif