/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:50:39 by arbutnar          #+#    #+#             */
/*   Updated: 2023/06/08 17:04:51 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	door_north_star(t_data *data, float angle, float distance, int i)
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
	if (data->map[(int)(p_y - 0.01)][(int)p_x] == 'D')
		data->orien[i] = 4;
	else if (data->map[(int)(p_y + 0.01)][(int)p_x] == 'D')
		data->orien[i] = 5;
	else if (data->map[(int)p_y][(int)(p_x - 0.01)] == 'D')
		data->orien[i] = 6;
	else
		data->orien[i] = 7;
}

void	open_door(t_data *data)
{
	float	s;
	float	c;
	float	p_y;
	float	p_x;
	float	distance;

	s = sin(data->pc.pov * RAD);
	c = cos(data->pc.pov * RAD);
	distance = 0.1;
	while (distance < 2)
	{
		p_y = data->pc.y + s * distance;
		p_x = data->pc.x + c * distance;
		if (data->map[(int)p_y][(int)p_x] == 'D' ||
			data->map[(int)p_y][(int)p_x] == 'A')
			break ;
		distance += 0.1;
	}
	if (data->map[(int)p_y][(int)p_x] == 'D')
		data->map[(int)p_y][(int)p_x] = 'A';
	else if (data->map[(int)p_y][(int)p_x] == 'A')
		data->map[(int)p_y][(int)p_x] = 'D';
}

void	open_hand(t_data *data)
{
	data->hand.img = mlx_xpm_file_to_image(data->mlx, "sprites/hand.xpm",
			&data->hand.w, &data->hand.h);
	data->hand.addr = mlx_get_data_addr(data->hand.img,
			&data->hand.bpp, &data->hand.ll, &data->hand.endian);
}

void	print_hand(t_data *data, float tex_y)
{
	float	tex_x;
	int		y;

	y = HAND_SIZE;
	while (y > 0)
	{
		tex_x = 0;
		p_hand(data, tex_y, tex_x, y);
		tex_y += data->hand.h / HAND_SIZE / 4;
		y--;
	}
}

void	update_hand(t_data *data)
{
	data->frames++;
	if (data->frames <= 30)
		print_hand(data, 0);
	else if (data->frames <= 31)
		print_hand(data, data->hand.h / 4);
	else if (data->frames <= 32)
		print_hand(data, data->hand.h / 2);
	else
	{
		print_spiral(data);
		print_hand(data, data->hand.h - data->hand.h / 4);
	}
	if (data->frames == 100)
		data->frames = 0;
}
