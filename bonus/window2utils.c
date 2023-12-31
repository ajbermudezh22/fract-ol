/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window2utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:32:49 by albermud          #+#    #+#             */
/*   Updated: 2023/06/16 15:45:18 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol_bonus.h"

void	doingfirstsquare(t_vars vars)
{
	int	x;
	int	y;

	x = 1;
	while (x < 140)
	{
		y = 40;
		while (y < 100)
		{
			mlx_pixel_put(vars.mlx, vars.win2, x, y, 0xFFFF0000);
			y++;
		}
		x++;
	}
	mlx_string_put(vars.mlx, vars.win2, 5, 60, 0xFFFFFFFF, "Press Here");
	mlx_string_put(vars.mlx, vars.win2, 5, 70, 0xFFFFFFFF, "or");
	mlx_string_put(vars.mlx, vars.win2, 5, 80, 0xFFFFFFFF, "Press 'r' button.");
}

void	doingsecondsquare(t_vars vars)
{
	int	x;
	int	y;

	x = 150;
	while (x < 298)
	{
		y = 40;
		while (y < 100)
		{
			mlx_pixel_put(vars.mlx, vars.win2, x, y, 0xFF00FF00);
			y++;
		}
		x++;
	}
	mlx_string_put(vars.mlx, vars.win2, 155, 60, 0x00000000, "Press Here");
	mlx_string_put(vars.mlx, vars.win2, 155, 70, 0x00000000, "or");
	mlx_string_put(vars.mlx, vars.win2, 155, 80, 0x00000000, \
	"Press 'g' button.");
}

void	doingthirdsquare(t_vars vars)
{
	int	x;
	int	y;

	x = 1;
	while (x < 140)
	{
		y = 105;
		while (y < 165)
		{
			mlx_pixel_put(vars.mlx, vars.win2, x, y, 0xFF0000FF);
			y++;
		}
		x++;
	}
	mlx_string_put(vars.mlx, vars.win2, 5, 125, 0xFFFFFFFF, "Press Here");
	mlx_string_put(vars.mlx, vars.win2, 5, 135, 0xFFFFFFFF, "or");
	mlx_string_put(vars.mlx, vars.win2, 5, 145, 0xFFFFFFFF, \
	"Press 'b' button.");
}

void	doingfourthsquare(t_vars vars)
{
	int	x;
	int	y;

	x = 150;
	while (x < 298)
	{
		y = 105;
		while (y < 165)
		{
			mlx_pixel_put(vars.mlx, vars.win2, x, y, \
			0x00000001 * ((x + y) * 8000));
			y++;
		}
		x++;
	}
	mlx_string_put(vars.mlx, vars.win2, 155, 125, 0xFFFFFFFF, "Press Here");
	mlx_string_put(vars.mlx, vars.win2, 155, 135, 0xFFFFFFFF, "or");
	mlx_string_put(vars.mlx, vars.win2, 155, 145, 0xFFFFFFFF, \
	"Press 'p' button.");
	mlx_string_put(vars.mlx, vars.win2, 155, 155, 0xFFFFFFFF, \
	"Also press SPACE.");
}

void	doingsquare_fract2(t_vars vars)
{
	int	x;
	int	y;

	x = 1;
	while (x < 140)
	{
		y = 360;
		while (y < 400)
		{
			mlx_pixel_put(vars.mlx, vars.win2, x, y, 0xFFFFFFFF);
			y++;
		}
		x++;
	}
	mlx_string_put(vars.mlx, vars.win2, 5, 370, 0x00000000, "For Burning Ship");
	mlx_string_put(vars.mlx, vars.win2, 5, 380, 0x00000000, "or");
	mlx_string_put(vars.mlx, vars.win2, 5, 390, 0x00000000, \
	"Press 's' button.");
}
