/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberes <dberes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:24:59 by dberes            #+#    #+#             */
/*   Updated: 2023/10/23 16:26:36 by dberes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char				*get_next_line(int fd);
int					check_len(char **str);
char				*strjoin(char *exisiting, char **extra);
int					check_end(char **str);
char				*trim_buf(char **str);
void				free_str(char **str);
char				*res_cpy(char *str2, int i);
char				*buf_handler(int *te, int fd, char **line);
char				*res_handler(char **res, int t_end);
char				*l_ha(char *line, char **buf, int *nl);
#endif
