/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spiral.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:03:21 by arbutnar          #+#    #+#             */
/*   Updated: 2023/06/09 15:37:48 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	thick_spiral(t_data *data, float p_x, float p_y, int color)
{
	my_mlx_pixel_put(&data->img, p_x, p_y, color);
	my_mlx_pixel_put(&data->img, p_x + 1, p_y, color);
	my_mlx_pixel_put(&data->img, p_x, p_y + 1, color);
	my_mlx_pixel_put(&data->img, p_x - 1, p_y, color);
	my_mlx_pixel_put(&data->img, p_x, p_y - 1, color);
	my_mlx_pixel_put(&data->img, p_x - 1, p_y - 1, color);
	my_mlx_pixel_put(&data->img, p_x + 1, p_y + 1, color);
	my_mlx_pixel_put(&data->img, p_x - 1, p_y + 1, color);
	my_mlx_pixel_put(&data->img, p_x + 1, p_y - 1, color);
}

void	print_spiral(t_data *data)
{
	float		p_y;
	float		p_x;
	float		angle;
	float		radius;

	radius = 1;
	angle = data->s_angle * 20;
	while (radius < GAME_WIDTH / 10)
	{
		p_y = SCR_HEIGHT / 2 + sin(angle * RAD) * radius;
		p_x = SCR_WIDTH / 2 + cos(angle * RAD) * radius;
		thick_spiral(data, p_x, p_y, GREEN);
		angle += 0.5;
		radius += 0.035;
	}
	angle = 0;
	while (angle < 360)
	{
		p_y = SCR_HEIGHT / 2 + sin(angle * RAD) * radius;
		p_x = SCR_WIDTH / 2 + cos(angle * RAD) * radius;
		thick_spiral(data, p_x, p_y, GREEN);
		angle += 0.5;
	}
	data->s_angle--;
}
