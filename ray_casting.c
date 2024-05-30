/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:38:30 by arbutnar          #+#    #+#             */
/*   Updated: 2023/06/09 16:00:42 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	open_textures(t_data *data)
{
	data->tex[0].img = mlx_xpm_file_to_image(data->mlx, data->no,
			&data->tex[0].w, &data->tex[0].h);
	data->tex[0].addr = mlx_get_data_addr(data->tex[0].img,
			&data->tex[0].bpp, &data->tex[0].ll, &data->tex[0].endian);
	data->tex[1].img = mlx_xpm_file_to_image(data->mlx, data->so,
			&data->tex[1].w, &data->tex[1].h);
	data->tex[1].addr = mlx_get_data_addr(data->tex[1].img,
			&data->tex[1].bpp, &data->tex[1].ll, &data->tex[1].endian);
	data->tex[2].img = mlx_xpm_file_to_image(data->mlx, data->we,
			&data->tex[2].w, &data->tex[2].h);
	data->tex[2].addr = mlx_get_data_addr(data->tex[2].img,
			&data->tex[2].bpp, &data->tex[2].ll, &data->tex[2].endian);
	data->tex[3].img = mlx_xpm_file_to_image(data->mlx, data->ea,
			&data->tex[3].w, &data->tex[3].h);
	data->tex[3].addr = mlx_get_data_addr(data->tex[3].img,
			&data->tex[3].bpp, &data->tex[3].ll, &data->tex[3].endian);
	data->tex[4].img = mlx_xpm_file_to_image(data->mlx, data->door,
			&data->tex[4].w, &data->tex[4].h);
	data->tex[4].addr = mlx_get_data_addr(data->tex[4].img,
			&data->tex[4].bpp, &data->tex[4].ll, &data->tex[4].endian);
}

void	texture_x(t_data *data, int i, float p_x, float p_y)
{
	if (data->orien[i] == 0)
		data->wall_x[i] = floor((p_x - floor(p_x)) * data->tex[0].w);
	else if (data->orien[i] == 1)
		data->wall_x[i] = data->tex[1].w
			- floor((p_x - floor(p_x)) * data->tex[1].w);
	else if (data->orien[i] == 2)
		data->wall_x[i] = data->tex[2].w
			- floor((p_y - floor(p_y)) * data->tex[2].w);
	else if (data->orien[i] == 3)
		data->wall_x[i] = floor((p_y - floor(p_y)) * data->tex[3].w);
	else if (data->orien[i] == 4)
		data->wall_x[i] = floor((p_x - floor(p_x)) * data->tex[4].w);
	else if (data->orien[i] == 5)
		data->wall_x[i] = data->tex[4].w
			- floor((p_x - floor(p_x)) * data->tex[4].w);
	else if (data->orien[i] == 6)
		data->wall_x[i] = data->tex[4].w
			- floor((p_y - floor(p_y)) * data->tex[4].w);
	else
		data->wall_x[i] = floor((p_y - floor(p_y)) * data->tex[4].w);
}

void	texture_put(t_data *data, int x, int y, t_img tex)
{
	char	*src;
	char	*dst;
	int		color;
	float	tex_y;

	tex_y = y - (GAME_HEIGHT - data->wall_height[x]) / 2;
	dst = data->img.addr + ((y + SCR_HEIGHT / 4) * data->img.ll
			+ (x + SCR_WIDTH / 4) * (data->img.bpp / 8));
	src = tex.addr + ((int)(tex_y * tex.h / data->wall_height[x]) * tex.ll
			+ (int)data->wall_x[x] * (tex.bpp / 8));
	color = *(int *)src;
	*(int *)dst = color;
}

void	ray_casting(t_data *data, int x, t_img tex)
{
	int		y;
	float	ceiling;

	data->wall_height[x] = (GAME_HEIGHT / data->radius_lenght[x]);
	ceiling = (GAME_HEIGHT - data->wall_height[x]) / 2;
	y = 0;
	while (y < GAME_HEIGHT)
	{
		if (y < ceiling)
			my_mlx_pixel_put(&data->img, x + SCR_WIDTH / 4,
				y + SCR_HEIGHT / 4, data->c);
		else if (y < data->wall_height[x] + ceiling)
			texture_put(data, x, y, tex);
		else
			my_mlx_pixel_put(&data->img, x + SCR_WIDTH / 4,
				y + SCR_HEIGHT / 4, data->f);
		y++;
	}
}
