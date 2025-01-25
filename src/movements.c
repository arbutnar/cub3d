/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:32:51 by arbutnar          #+#    #+#             */
/*   Updated: 2023/06/09 14:41:38 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_on(int keycode, t_data *data)
{
	if (keycode == ESC)
		destroy(data);
	if (keycode == W)
		data->w = 1;
	if (keycode == A)
		data->a = 1;
	if (keycode == S)
		data->s = 1;
	if (keycode == D)
		data->d = 1;
	if (keycode == LEFT)
		data->lf = 1;
	if (keycode == RIGHT)
		data->rg = 1;
	if (keycode == SPACEBAR)
		open_door(data);
	return (0);
}

int	key_off(int keycode, t_data *data)
{
	if (keycode == ESC)
		destroy(data);
	if (keycode == W)
		data->w = 0;
	if (keycode == A)
		data->a = 0;
	if (keycode == S)
		data->s = 0;
	if (keycode == D)
		data->d = 0;
	if (keycode == LEFT)
		data->lf = 0;
	if (keycode == RIGHT)
		data->rg = 0;
	return (0);
}

void	do_movement(t_data *data, float angle)
{
	float	new_x;
	float	new_y;

	new_x = data->pc.x + cos(angle) * SPEED;
	if (data->map[(int)data->pc.y][(int)new_x] != '1'
		&& data->map[(int)data->pc.y][(int)new_x] != 'D')
		data->pc.x = data->pc.x + cos(angle) * SPEED;
	new_y = data->pc.y + sin(angle) * SPEED;
	if (data->map[(int)new_y][(int)data->pc.x] != '1'
		&& data->map[(int)new_y][(int)data->pc.x] != 'D')
		data->pc.y = data->pc.y + sin(angle) * SPEED;
}

void	movements(t_data *data)
{
	int	mouse_x;
	int	mouse_y;

	mlx_mouse_get_pos(data->mlx, data->win, &mouse_x, &mouse_y);
	if (data->w == 1)
		do_movement(data, data->pc.pov * RAD);
	if (data->a == 1)
		do_movement(data, (data->pc.pov - 90) * RAD);
	if (data->s == 1)
		do_movement(data, (data->pc.pov - 180) * RAD);
	if (data->d == 1)
		do_movement(data, (data->pc.pov + 90) * RAD);
	if (data->lf == 1 || mouse_x < SCR_WIDTH / 2)
		data->pc.pov -= SENSIBILITY;
	if (data->rg == 1 || mouse_x > SCR_WIDTH / 2)
		data->pc.pov += SENSIBILITY;
	mlx_mouse_move(data->mlx, data->win, SCR_WIDTH / 2, SCR_HEIGHT / 2);
}
