/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:19:19 by albermud          #+#    #+#             */
/*   Updated: 2023/06/14 23:48:14 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

int	get_window(t_vars *vars, char *argv[])
{
	vars->imgh = check_windowinput(argv, 'h', 0);
	if (!vars->imgh)
		vars->imgh = IMG_H;
	vars->imgw = check_windowinput(argv, 'w', 0);
	if (!vars->imgw)
		vars->imgw = IMG_W;
	return (0);
}

int	initialize_mlx(t_vars *vars, char *argv[])
{
	get_window(vars, argv);
	vars->add = 0;
	vars->mlx = mlx_init();
	if (!vars->mlx)
	{
		ft_printf("Mlx initialization failure.");
		exit(EXIT_FAILURE);
	}
	if (vars->ismandel == 1)
		vars->win = mlx_new_window(vars->mlx, vars->imgw, vars->imgh, \
				"MandelBrot");
	else
		vars->win = mlx_new_window(vars->mlx, vars->imgw, vars->imgh, "Julia");
	if (!vars->win)
	{
		free(vars->win);
		free(vars->mlx);
		ft_printf("MLX window init failure.");
		exit(EXIT_FAILURE);
	}
	return (0);
}

int	initialize_img(t_data *img, t_vars *vars)
{
	img->img = mlx_new_image(vars->mlx, vars->imgw, vars->imgh);
	if (!img->img)
	{
		ft_printf("Image mlx creation failed");
		free(vars->mlx);
		free(vars->win);
		exit(EXIT_FAILURE);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
			&img->line_length, &img->endian);
	if (!img->addr)
	{
		ft_printf("Image mlx creation failed");
		free(img->img);
		free(img->addr);
		free(vars->mlx);
		free(vars->win);
		exit(EXIT_FAILURE);
	}
	return (0);
}
