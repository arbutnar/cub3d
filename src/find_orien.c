/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orien.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:15:28 by arbutnar          #+#    #+#             */
/*   Updated: 2023/06/08 20:37:45 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	assign_orien(t_data *data)
{
	int	x;

	x = 0;
	while (x < GAME_WIDTH)
	{
		if (data->orien[x] == 0)
			ray_casting(data, x, data->tex[0]);
		else if (data->orien[x] == 1)
			ray_casting(data, x, data->tex[1]);
		else if (data->orien[x] == 2)
			ray_casting(data, x, data->tex[2]);
		else if (data->orien[x] == 3)
			ray_casting(data, x, data->tex[3]);
		else
			ray_casting(data, x, data->tex[4]);
		x++;
	}
}

void	north_star(t_data *data, float angle, float distance, int i)
{
	float	c;
	float	s;
	float	p_x;
	float	p_y;

	distance -= 0.01;
	c = cos(angle * RAD);
	s = sin(angle * RAD);
	p_y = data->pc.y + s * distance;
	p_x = data->pc.x + c * distance;
	if (data->map[(int)(p_y - 0.01)][(int)p_x] == '1')
		data->orien[i] = 0;
	else if (data->map[(int)(p_y + 0.01)][(int)p_x] == '1')
		data->orien[i] = 1;
	else if (data->map[(int)p_y][(int)(p_x - 0.01)] == '1')
		data->orien[i] = 2;
	else
		data->orien[i] = 3;
}

// to many variables
void	calculate_radius(t_data *data, float angle, int i)
{
	float	p_x;
	float	p_y;
	float	s;
	float	c;
	float	distance;

	distance = 0.01;
	s = sin(angle * RAD);
	c = cos(angle * RAD);
	while (1)
	{
		p_y = data->pc.y + s * distance;
		p_x = data->pc.x + c * distance;
		if (data->map[(int)p_y][(int)p_x] == '1'
			|| data->map[(int)p_y][(int)p_x] == 'D')
			break ;
		distance += 0.01;
	}
	data->radius_lenght[i] = distance;
	if (data->map[(int)p_y][(int)p_x] == '1')
		north_star(data, angle, distance, i);
	else
		door_north_star(data, angle, distance, i);
	texture_x(data, i, p_x, p_y);
}

void	fan_radius(t_data *data)
{
	float	l_angle;
	float	r_angle;
	int		j;

	l_angle = data->pc.pov - 30.0;
	r_angle = data->pc.pov + 30.0;
	j = 0;
	while (l_angle < r_angle)
	{
		calculate_radius(data, l_angle, j);
		l_angle += (60.0 / GAME_WIDTH);
		j++;
	}
}
