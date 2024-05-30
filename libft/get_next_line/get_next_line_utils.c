/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:35:46 by arbutnar          #+#    #+#             */
/*   Updated: 2023/05/01 14:39:26 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*g_strchr(char *save)
{
	size_t	i;

	if (!save)
		return (NULL);
	i = 0;
	while (save[i])
	{
		if (save[i] == '\n')
			return (save + i);
		i++;
	}
	return (NULL);
}

char	*g_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 && (!s2 || !*s2))
		return (NULL);
	i = 0;
	if (s1)
		while (s1[i])
			i++;
	j = 0;
	while (s2[j])
		j++;
	str = (char *)malloc(sizeof(char) * i + j + 1);
	if (!str)
		return (NULL);
	str[i + j] = '\0';
	while (--j >= 0)
		str[i + j] = s2[j];
	while (--i >= 0)
		str[i] = s1[i];
	free(s1);
	return (str);
}

size_t	g_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}
