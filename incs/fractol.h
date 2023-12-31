/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 09:48:46 by albermud          #+#    #+#             */
/*   Updated: 2023/06/16 16:48:43 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include ".././mlx/mlx.h"
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include "../ft_printf/incs/ft_printf.h"
# include "../ft_printf/incs/get_next_line.h"

# define ESC 65307
# define SCROLL_UP 5
# define SCROLL_DOWN 4
# define ARR_UP 65364
# define ARR_DOWN 65362
# define ARR_RIGHT 65363
# define ARR_LEFT 65361

# ifndef IMG_H
#  define IMG_H 400
# endif

# ifndef IMG_W
#  define IMG_W 400
# endif

# ifndef CX_JULIA
#  define CX_JULIA -0.7
# endif

# ifndef CY_JULIA
#  define CY_JULIA  0.27015
# endif

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_julia
{
	int		width;
	int		heigth;
	double	c_y;
	double	c_x;
	double	z_y;
	double	z_x;
	double	prev_z_y;
	double	prev_z_x;
	double	z_y2;
	double	z_x2;
	double	zoom;
	int		n;
	int		maxit;
	int		x;
	int		y;
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
}	t_julia;

typedef struct s_mandelbrot
{
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
	double	y_factor;
	double	x_factor;
	double	c_y;
	double	c_x;
	double	z_y;
	double	z_x;
	double	z_y2;
	double	z_x2;
	double	zoom;
	int		n;
	int		maxit;
	int		x;
	int		y;
	int		width;
	int		heigth;
}	t_mdb;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		imgw;
	int		imgh;
	t_data	img;
	t_mdb	mandb;
	t_julia	julia;
	t_data	aux;
	int		add;
	int		ismandel;
}	t_vars;

/*pixel in an image*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	get_color(t_mdb mandelbrot, t_data img);
void	get_color_julia(t_julia julia, t_data img);

/*Hook functions*/
int		key_hook(int keycode, t_vars *vars);
int		mouse_hook(int mousecode, int x, int y, t_vars *vars);
int		doing_events(t_vars *vars);

/*Initialize functions*/
int		initialize_mlx(t_vars *vars, char *argv[]);
int		initialize_img(t_data *img, t_vars *vars);

/*Main*/
int		ft_fractal(int a, char *argv[]);

/*Mandelbrot*/
t_mdb	initialize_mandelbrot(char *argv[]);
int		do_mandelbrot(t_mdb mandelbrot, t_vars *vars, t_data img);
int		change_mandelbrot(t_vars *vars, double zoom);

/*Julia*/
int		change_julia(t_vars *vars, double zoom);
int		do_julia(t_julia julia, t_vars *vars, t_data img);
t_julia	initialize_julia(char *argv[]);
double	checkinputc(char *argv[], char a);

/*Exit functions*/
int		esc_window(t_vars *vars);
void	ft_comments(int a);

/*fractol_utils*/
double	ft_atod(char *str);
char	*create_string(char *arg);
int		check_windowinput(char *argv[], char a, int j);
#endif
