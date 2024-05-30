/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:39:43 by arbutnar          #+#    #+#             */
/*   Updated: 2023/06/09 18:38:44 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_orien(t_data *data, char c)
{
	if (c == 'N')
		data->pc.pov = 270;
	else if (c == 'S')
		data->pc.pov = 90;
	else if (c == 'E')
		data->pc.pov = 0;
	else if (c == 'W')
		data->pc.pov = 180;
}

void	check_surroundings(char **map, int row, int col, t_data *data)
{
	if (row - 1 < 0 || col - 1 < 0
		|| map[row + 1] == NULL || map[row][col + 1] == '\n')
		error_msg("Invalid map", data);
	if (map[row - 1][col] == ' ' || map[row - 1][col] == '\0')
		error_msg("Invalid map", data);
	if (map[row + 1][col] == ' ' || map[row + 1][col] == '\0')
		error_msg("Invalid map", data);
	if (map[row][col - 1] == ' ' || map[row][col - 1] == '\0')
		error_msg("Invalid map", data);
	if (map[row][col + 1] == ' ' || map[row][col + 1] == '\0')
		error_msg("Invalid map", data);
	if (map[row - 1][col - 1] == ' ' || map[row - 1][col - 1] == '\0')
		error_msg("Invalid map", data);
	if (map[row + 1][col + 1] == ' ' || map[row + 1][col + 1] == '\0')
		error_msg("Invalid map", data);
	if (map[row - 1][col + 1] == ' ' || map[row - 1][col + 1] == '\0')
		error_msg("Invalid map", data);
	if (map[row + 1][col - 1] == ' ' || map[row + 1][col - 1] == '\0')
		error_msg("Invalid map", data);
}

int	c_map(t_data *data, int player, int row)
{
	int		col;
	char	c;

	col = 0;
	while (data->map[row][col] != '\n')
	{
		c = data->map[row][col];
		if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		{
			player_orien(data, c);
			data->pc.y = row + 0.5;
			data->pc.x = col + 0.5;
			player++;
		}
		if (c == '0' || c == 'N' || c == 'S'
			|| c == 'E' || c == 'W' || c == 'D')
			check_surroundings(data->map, row, col, data);
		else if (c != '1' && c != ' ')
			error_msg("Invalid map", data);
		col++;
	}
	return (player);
}

void	check_map(t_data *data)
{
	int		row;
	int		player;

	player = 0;
	row = 0;
	while (data->map[row] != NULL)
	{
		player = c_map(data, player, row);
		row++;
	}
	if (player != 1)
		error_msg("Invalid map", data);
}

int	check_format(char *texture)
{
	int		i;
	int		len;
	char	*xpm;

	i = 0;
	if (!texture)
		return (0);
	len = ft_strlen(texture) - 4;
	if (len < 0)
		return (0);
	xpm = (char *)malloc(sizeof(char) * len);
	while (texture[len])
	{
		xpm[i] = texture[len];
		i++;
		len++;
	}
	if (ft_strncmp(xpm, ".xpm", 4))
	{
		free(xpm);
		return (0);
	}
	free(xpm);
	return (1);
}
