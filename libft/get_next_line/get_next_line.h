/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 02:46:13 by arbutnar          #+#    #+#             */
/*   Updated: 2023/04/26 19:21:15 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_get_line(char *save);
char	*ft_read_and_save(int fd, char *save);
char	*ft_save(char *save);
char	*g_strchr(char *save);
char	*g_strjoin(char *s1, char *s2);
size_t	g_strlen(const char *str);

#endif
