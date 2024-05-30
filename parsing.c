/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:23:06 by arbutnar          #+#    #+#             */
/*   Updated: 2023/06/09 18:34:56 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_returns(t_data *data)
{
	if (data->no == NULL || data->so == NULL || data->we == NULL
		|| data->ea == NULL || data->door == NULL)
		error_msg("Path", data);
	if (data->f == -1 || data->c == -1)
		error_msg("Path", data);
}

char	*fill_paths(char *str, char *path)
{
	char	**mtx;

	if (path != NULL)
		return (NULL);
	mtx = ft_split(str, ' ');
	if (mtx[1] == NULL || mtx[2])
	{
		ft_free_matrix(mtx);
		return (NULL);
	}
	path = ft_strdup(mtx[1]);
	path[ft_strlen(path) - 1] = '\0';
	ft_free_matrix(mtx);
	if (open(path, O_RDONLY) == -1 || !check_format(path))
	{
		free(path);
		return (NULL);
	}
	return (path);
}

int	fill_rgb(char *str, int *rgb)
{
	char	**space;
	char	**comma;
	int		color;

	if (*rgb != 0)
		return (-1);
	space = ft_split(str, ' ');
	if (space[1] == NULL || space[2])
	{
		ft_free_matrix(space);
		return (-1);
	}
	comma = ft_split(space[1], ',');
	ft_free_matrix(space);
	if (!comma[0] || !comma[1] || !comma[2] || comma[2][0] == '\n' || comma[3])
	{
		ft_free_matrix(comma);
		return (-1);
	}
	color = 65536 * ft_atoi(comma[0]) + 256 * ft_atoi(comma[1])
		+ ft_atoi(comma[2]);
	ft_free_matrix(comma);
	return (color);
}

int	r_fd(t_data *data, char *str, int fd, int i)
{
	while (str != NULL)
	{
		if (!ft_strncmp(str, "NO", 2))
			data->no = fill_paths(str, data->no);
		else if (!ft_strncmp(str, "SO", 2))
			data->so = fill_paths(str, data->so);
		else if (!ft_strncmp(str, "WE", 2))
			data->we = fill_paths(str, data->we);
		else if (!ft_strncmp(str, "EA", 2))
			data->ea = fill_paths(str, data->ea);
		else if (!ft_strncmp(str, "DO", 2))
			data->door = fill_paths(str, data->door);
		else if (!ft_strncmp(str, "F", 1))
			data->f = fill_rgb(str, &data->f);
		else if (!ft_strncmp(str, "C", 1))
			data->c = fill_rgb(str, &data->c);
		else if (str[0] != '\n')
		{
			data->map[i] = ft_strdup(str);
			i++;
		}
		free(str);
		str = get_next_line(fd);
	}
	return (i);
}

void	read_fd(char *filename, t_data *data)
{
	char	*str;
	int		fd;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("File Error\n");
		exit(1);
	}
	str = get_next_line(fd);
	i = fd_len(filename);
	data->map = ft_calloc(i + 1, sizeof(char *));
	i = r_fd(data, str, fd, 0);
	data->map[i] = NULL;
	close(fd);
	check_returns(data);
	check_map(data);
}
