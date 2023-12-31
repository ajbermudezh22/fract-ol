/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgpixel_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:11:20 by albermud          #+#    #+#             */
/*   Updated: 2023/06/16 15:44:09 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol_bonus.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	get_color(t_fract mandelbrot, t_data img)
{
	int	color;
	int	i;

	i = mandelbrot.maxit;
	color = 0x00000000;
	while (i)
	{
		if (i == mandelbrot.n)
		{
			my_mlx_pixel_put(&img, mandelbrot.x, mandelbrot.y, color);
			break ;
		}
		color += 222 * (i * 2) + mandelbrot.color;
		i--;
	}
	my_mlx_pixel_put(&img, mandelbrot.x, mandelbrot.y, color);
}

void	get_color_julia(t_fract julia, t_data img)
{
	int	color;
	int	i;

	i = julia.maxit;
	color = 0x00000000;
	while (i)
	{
		if (i == julia.n)
		{
			my_mlx_pixel_put(&img, julia.x, julia.y, color);
			break ;
		}
		else if (julia.n > 200)
			color += 100 + (i) + julia.color;
		else if (julia.n > 100 && julia.n <= 200)
			color += (600 + 1) + (i) + julia.color;
		else if (julia.n > 50 && julia.n <= 100)
			color += (8000 + 5) + (i - 49) + julia.color;
		else if (julia.n <= 50)
			color += (8060 + 10) + (i) + julia.color;
		i--;
	}
	my_mlx_pixel_put(&img, julia.x, julia.y, color);
}

double	screentocomplex(t_vars *vars, int x, int y, int i)
{
	double	number;

	if (i == 0)
		number = (((double)x / vars->imgw) * (vars->fract.max_x - \
		vars->fract.min_x)) * vars->fract.zoom + vars->fract.min_x + \
		vars->fract.offx;
	else
		number = (((double)y / vars->imgh) * (vars->fract.max_y - \
		vars->fract.min_y)) * vars->fract.zoom + vars->fract.min_y + \
		vars->fract.offy;
	return (number);
}
