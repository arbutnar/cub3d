/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:23:19 by arbutnar          #+#    #+#             */
/*   Updated: 2023/05/03 15:23:19 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_msg(char *str, t_data *data)
{
	printf("%s Error\n", str);
	free_data(data);
	exit(1);
}

void	data_init(t_data *data)
{
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	data->door = NULL;
	data->f = 0;
	data->c = 0;
	data->w = 0;
	data->a = 0;
	data->s = 0;
	data->d = 0;
	data->lf = 0;
	data->rg = 0;
	data->frames = 0;
	data->pc.pov = 0;
}

int	fd_len(char *filename)
{
	int		len;
	char	*str;
	int		fd;

	fd = open(filename, O_RDONLY);
	str = get_next_line(fd);
	len = 0;
	while (str != NULL)
	{
		if (str[0] != '\n')
			len++;
		free(str);
		str = get_next_line(fd);
	}
	close (fd);
	return (len);
}

void	print_matrix(char **mtx)
{
	int	i;

	i = 0;
	while (mtx[i] != NULL)
	{
		printf("%s", mtx[i]);
		i++;
	}
}

void	free_data(t_data *data)
{
	if (data->no != NULL)
		free(data->no);
	if (data->so != NULL)
		free(data->so);
	if (data->we != NULL)
		free(data->we);
	if (data->ea != NULL)
		free(data->ea);
	if (data->door != NULL)
		free(data->door);
	ft_free_matrix(data->map);
}
