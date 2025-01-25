/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_utility.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:52:29 by arbutnar          #+#    #+#             */
/*   Updated: 2023/06/09 18:37:17 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	p_hand(t_data *data, float tex_y, float tex_x, int y)
{
	int		x;
	int		color;
	char	*dst;
	char	*src;

	x = 0;
	while (x < HAND_SIZE)
	{
		dst = data->img.addr + (((SCR_HEIGHT - SCR_HEIGHT / 4) - y)
				* data->img.ll + (x + (SCR_WIDTH / 2)) * (data->img.bpp / 8));
		src = data->hand.addr + ((int)tex_y * data->hand.ll
				+ (int)tex_x * (data->hand.bpp / 8));
		color = *(int *)src;
		if (color >= 0)
			*(int *)dst = color;
		tex_x += data->hand.w / HAND_SIZE;
		x++;
	}
}
