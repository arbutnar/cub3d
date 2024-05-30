/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:23:29 by arbutnar          #+#    #+#             */
/*   Updated: 2023/05/03 15:23:29 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "mlx/mlx.h"

// sizes
# define UNIT_SIZE 16
# define SCR_WIDTH 3840
# define SCR_HEIGHT 2160
# define GAME_WIDTH 1920.00
# define GAME_HEIGHT 1080.00
# define HAND_SIZE 500.0
// keypress
# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307
# define LEFT 65361
# define RIGHT 65363
# define SPACEBAR 32
// ulils for calculations
# define RAD 0.0174533
# define SPEED 0.2
# define SENSIBILITY 6
// colors
# define BLACK 0x000000
# define RED 0xff0000
# define GREEN 0x5d9560
# define WHITE 0xfdfbfb
# define PURPLE 0x9b329f

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
	int		w;
	int		h;
}	t_img;

typedef struct s_pc
{
	int		pov;
	float	x;
	float	y;
}	t_pc;

typedef struct s_data
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*door;
	int		f;
	int		c;
	char	**map;
	void	*mlx;
	void	*win;
	t_img	img;
	t_img	tex[5];
	int		wall_x[(int)GAME_WIDTH];
	t_pc	pc;
	int		w;
	int		a;
	int		s;
	int		d;
	int		lf;
	int		rg;
	float	radius_lenght[(int)GAME_WIDTH];
	float	wall_height[(int)GAME_WIDTH];
	float	orien[(int)GAME_WIDTH];
	t_img	hand;
	int		frames;
	float	s_angle;
}	t_data;

// parsing.c
char	*fill_paths(char *str, char *path);
int		fill_rgb(char *str, int *rgb);
int		r_fd(t_data *data, char *str, int fd, int i);
void	read_fd(char *filename, t_data *data);
void	open_textures(t_data *data);

// checks.c
int		check_format(char *texture);
void	player_orien(t_data *data, char c);
int		c_map(t_data *data, int player, int row);
void	check_surroundings(char **map, int row, int col, t_data *data);
void	check_map(t_data *data);

// loop_utility.c
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	print_minimap(t_data *data, int x, int y);
void	create_minimap(t_data *data);
void	player_pos(t_data *data);
void	fill_screen(t_data *data);

// movements.c
int		key_on(int keycode, t_data *data);
int		key_off(int keycode, t_data *data);
void	do_movement(t_data *data, float angle);
void	movements(t_data *data);

// find_orien.c
void	assign_orien(t_data *data);
void	north_star(t_data *data, float angle, float distance, int i);
void	calculate_radius(t_data *data, float angle, int i);
void	fan_radius(t_data *data);

// ray_casting.c
void	texture_x(t_data *data, int i, float Px, float Py);
void	texture_put(t_data *data, int x, int y, t_img texture);
void	ray_casting(t_data *data, int x, t_img texture);

// utility.c
void	data_init(t_data *data);
void	error_msg(char *str, t_data *data);
int		fd_len(char *filename);
void	print_matrix(char **mtx);
void	free_data(t_data *data);

// norm_utility.c
void	p_hand(t_data *data, float tes_y, float tes_x, int y);

// bonus.c
void	door_north_star(t_data *data, float angle, float distance, int i);
void	open_door(t_data *data);
void	open_hand(t_data *data);
void	print_spiral(t_data *data);
void	update_hand(t_data *data);

// spiral.c
void	thick_spiral(t_data *data, float p_x, float p_y, int color);
void	print_spiral(t_data *data);

// main.c
int		destroy(t_data *data);
int		loop_hook(t_data *data);

#endif
