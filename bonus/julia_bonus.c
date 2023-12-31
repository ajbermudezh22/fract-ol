/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:18:00 by albermud          #+#    #+#             */
/*   Updated: 2023/06/16 15:44:29 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol_bonus.h"

int	change_julia(t_vars *vars)
{
	if (vars->fract.colorsch == 'p')
		vars->fract.color += vars->aux.color;
	vars->fract.maxit = 300;
	vars->fract.y = -1;
	vars->fract.offx = vars->aux.offx;
	vars->fract.offy = vars->aux.offy;
	vars->fract.max_x += vars->fract.offx + vars->aux.left + vars->aux.rigth;
	vars->fract.min_x += vars->fract.offx + vars->aux.left + vars->aux.rigth;
	vars->fract.max_y += vars->fract.offy + vars->aux.up + vars->aux.down;
	vars->fract.min_y += vars->fract.offy + vars->aux.up + vars->aux.down;
	vars->aux.left = 0;
	vars->aux.rigth = 0;
	vars->aux.up = 0;
	vars->aux.down = 0;
	vars->aux.offx = 0;
	vars->aux.offy = 0;
	return (0);
}

void	getting_color(t_fract j, t_data img)
{
	if (j.colorsch == 'r' && j.n != j.maxit)
		my_mlx_pixel_put(&img, j.x, j.y, get_r(j.n));
	else if (j.colorsch == 'b' && j.n != j.maxit)
		my_mlx_pixel_put(&img, j.x, j.y, get_b(j.n));
	else if (j.colorsch == 'g' && j.n != j.maxit)
		my_mlx_pixel_put(&img, j.x, j.y, get_g(j.n));
	else if (j.colorsch == 'p' && j.n != j.maxit)
		get_color_julia(j, img);
	else if (j.n == j.maxit)
		my_mlx_pixel_put(&img, j.x, j.y, 0x000000);
}

int	do_julia(t_fract j, t_vars *vars, t_data img)
{
	while (++j.y < j.heigth)
	{
		j.x = -1;
		while (++j.x < j.width)
		{
			j.z_x = screentocomplex(vars, j.x, j.y, 0);
			j.z_y = screentocomplex(vars, j.x, j.y, 1);
			j.n = -1;
			while (++j.n < j.maxit)
			{
				j.prev_z_x = j.z_x;
				j.prev_z_y = j.z_y;
				j.z_x = (j.prev_z_x * j.prev_z_x) - \
						(j.prev_z_y * j.prev_z_y) + j.c_x;
				j.z_y = 2 * j.prev_z_y * j.prev_z_x + j.c_y;
				if ((j.z_y * j.z_y + j.z_x * j.z_x) > 4)
					break ;
			}
			getting_color(j, img);
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
	return (0);
}

double	checkinputc(char *argv[], char a)
{
	int		i;
	double	c;

	i = 2;
	c = -100000;
	while (argv[i])
	{
		if (argv[i][0] == 'c' && argv[i][1] == 'x' && a == 'x')
			c = ft_atod(argv[i] + 2);
		else if (argv[i][0] == 'c' && argv[i][1] == 'y' && a == 'y')
			c = ft_atod(argv[i] + 2);
		if (c != -100000)
			break ;
		i++;
	}
	if (c != -100000 && (c > 1 || c < -2))
	{
		ft_printf("\nThe values won't show much. ");
		ft_printf("cy and cx should be between (-2, 1)\n");
	}
	if (argv[2] && c != -100000)
		return (c);
	return (-100000);
}
