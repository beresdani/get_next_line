/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberes <dberes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:42:23 by dberes            #+#    #+#             */
/*   Updated: 2023/10/18 13:30:33 by dberes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char				*get_next_line(int fd);
unsigned long		ft_strlen(char *str);
char				*strjoin(char *exisiting, char *extra);
int					check_end(char *str);
char				*add_resid(char *str);
void				free_str(char **str);
char				*res_cpy(char *str2, int i);
char				*buf_handler(char *line, int *t_end, int fd);
char				*res_handler(char **res, int t_end);
char				*l_ha(char *line, char **res, int *te, char *buf);
#endif
