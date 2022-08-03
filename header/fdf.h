/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymond <mraymond@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:51:35 by mraymond          #+#    #+#             */
/*   Updated: 2022/07/27 08:59:12 by mraymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"

# define SCREEN_W 1920
# define SCREEN_H 1080
# define AXY_INIT 1.76
# define AZX_INIT .25
# define PI 3.141592654

typedef struct s_pp
{
	int	x;
	int	y;
	int	color_r;
	int	color_g;
	int	color_b;
	int	color_t;
	int	color_lock;
}				t_pp;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		map_nbx;
	int		map_nby;
	int		map_fd;
	char	*map_name;
	double	z_stretch;
	double	scale;
	int		x_offset;
	int		y_offset;
	int		z_offset;
	int		dpl;
	int		dpo;
	double	axy;
	double	azx;
	double	arot;
	int		*pm_z;
	int		pm_z_moy;
	int		pm_z_lower;
	int		pm_z_higher;
	t_pp	*pp;
	int		diag1;
	int		diag2;
	int		hub;
}				t_vars;

typedef struct s_vector
{
	double		p;
	double		axy;
	double		azx;
	double		x;
	double		y;
	double		z;
}				t_vector;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}				t_point;

typedef struct s_direction
{
	int		x;
	int		y;
	int		z;
	double	d_x;
	double	d_y;
	double	d_z;
}				t_direction;

typedef struct s_draw_data
{
	int		side;
	int		line_x;
	int		line_y;
	int		adr_0;
	int		adr_1;
	int		ps0_x;
	int		ps0_y;
	int		ps1_x;
	int		ps1_y;
	double	m;
}			t_draw_data;

typedef struct s_ni_data
{
	t_point		*pl;
	t_point		*pm;
	t_point		*ppm;
	t_point		*po;
	t_vector	*vlppm;
	t_vector	*vlo;
	t_vector	*vmo;
	t_vector	*vli;
	t_vector	*vli_pole;
	t_vector	*vplane2d;
	t_point		*pi;
	int			x;
	int			y;
	double		d;
	double		t;
	int			cadran;
}				t_ni_data;

//0000_fdf.c
void	vars_mlx_init(t_vars *vars);

//0100_map_check.c
int		map_check(t_vars *vars, char *map_name);

//0200_map_extract.c
void	map_extract(t_vars *vars);
void	line_by_line_extract(t_vars *vars);
void	z_extract(t_vars *vars, char **split_line, int y);
void	pm_z_moy_high_low(t_vars *vars, int x, int y);
void	color_extract(t_vars *vars, char *color_info, int y, int x);

//0210_vars_map_init.c
void	vars_map_init(t_vars *vars);
void	set_dpl_dpo(t_vars *vars);

//0300_new_image.c
void	new_image(t_vars *vars);
void	calloc_ni_data(t_ni_data *ni);
void	free_ni_data(t_ni_data *ni);
void	pl_ppm_po_xyz(t_vars *vars, t_ni_data *ni);
void	cal_plane_equation_d(t_ni_data *ni);

//0310_pp_fill.c
void	fill_all_pp(t_vars *vars, t_ni_data *ni);
void	cal_fill_pp(t_vars *vars, t_ni_data *ni);
void	fill_pp(t_vars *vars, t_ni_data *ni);
void	pp_center_plane(t_vars *vars, t_ni_data *ni);
void	pp_color_apply(t_vars *vars, t_ni_data *ni);

//0311_vector_point_cal.c
void	cal_vmo(t_vars *vars, t_ni_data *ni);
void	cal_vlo(t_ni_data *ni);
void	cal_vli(t_ni_data *ni);
void	cal_pi(t_ni_data *ni);
int		cal_t_equ_plane(t_ni_data *ni);

//0312_vplane2d.c
void	cal_vplane2d(t_vars *vars, t_ni_data *ni);
double	vplane2d_angle_axy(double vars, double vli);
void	pole_angle(t_vars *vars, t_ni_data *ni);

//0320_draw_new_image.c
void	draw_new_image(t_vars *vars);
void	draw_lines(t_vars *vars, int x, int y);
void	draw_line(t_vars *vars, t_draw_data *ddraw);
void	set_xy(t_vars *vars, t_draw_data *ddraw);
int		line_too_long(t_draw_data *ddraw);

//0321_draw_line_type.c
void	draw_line_xtox(t_vars *vars, t_draw_data *ddraw);
void	draw_line_ytoy(t_vars *vars, t_draw_data *ddraw);
void	draw_line_vertical(t_vars *vars, t_draw_data *ddraw);

//0322_draw_line_utils.c
int		side_setter(int val0, int val1);
void	put_on_image2(t_vars *vars, t_draw_data *ddraw, int i);
int		color_shift(t_vars *vars, t_draw_data *ddraw, int i);
void	my_mlx_pixel_put(t_vars *data, int x, int y, int color);

//0400_keypress_handler.c
int		keypress_handler(int keycode, t_vars *vars);
int		exit_win(t_vars *vars);
int		render_next_frame(t_vars *vars);

//0410_key_action.c
void	key_translation(int keycode, t_vars *vars);
void	key_zoom(int keycode, t_vars *vars);
void	key_rotate(int keycode, t_vars *vars);
void	key_z_stretch(int keycode, t_vars *vars);
void	key_rotate_pl(int keycode, t_vars *vars);

//0411_key_action_utils.c
void	axy_azx_ajust(double *axy, double *azx);
void	cal_rpl_offset(t_vars *vars, double *axy_mod, double *azx_mod);

//0420_hub.c
void	hub_show(t_vars *vars);
void	hub_list1(t_vars *vars);
void	hub_list2(t_vars *vars);
void	hub_list3(t_vars *vars);
void	mlx_str_itoa(t_vars *vars, int x, int y, int val);

#endif