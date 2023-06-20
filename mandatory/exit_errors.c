/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:35:22 by albermud          #+#    #+#             */
/*   Updated: 2023/06/14 23:47:23 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

int	esc_window(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	if (vars->add != 0)
		mlx_destroy_image(vars->mlx, vars->aux.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

void	ft_comments(int a)
{
	if (a == 0)
		ft_printf("These are the possible fractals:\n1) Mandelbrot\n2) Julia\n\n");
	ft_printf("Options for executing the program:\n\n");
	ft_printf("\t1) If you want to change window size execute the program:");
	ft_printf(" ./fractol FRACTAL iwSIZE ihSIZE\n");
	if (a == 1 || a == 0)
	{
		ft_printf("\n\t2) For Julia set you can also change the");
		ft_printf(" initial parameters this way:\n\n");
		ft_printf("\t  2.1) Changing the real and complex part");
		ft_printf(" of the constant: ./fractol FRACTAL cxDOUBLE cyDOUBLE\n\n");
		ft_printf("\t  NOTE: you can still change the window");
		ft_printf(" size with iw and ih\n\n");
	}
	ft_printf("NOTE: you can put the arguments (except fractal) in what");
	ft_printf(" order you would like, just make sure you have the prefixes");
	ft_printf(" rigth (i.e. ih, iw).\n\n");
	ft_printf("LIMITS: iw > 0 and iw < 1080, ih > 0 and ih < 1980\n\n");
	if (a == 1 || a == 2)
	{
		ft_printf("\nOptions while executing:\n\n");
		ft_printf("\t1) Mouse wheel zoomin and zoomout in the center\n\n");
		ft_printf("\t2) ESC and cross closes window.\n");
	}
}
