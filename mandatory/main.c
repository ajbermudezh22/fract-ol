/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 09:48:50 by albermud          #+#    #+#             */
/*   Updated: 2023/06/14 23:48:35 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

int	ft_fractal(int a, char *argv[])
{
	t_vars	vars;

	if (a == 1)
		vars.ismandel = 1;
	else
		vars.ismandel = 0;
	initialize_mlx(&vars, argv);
	initialize_img(&vars.img, &vars);
	if (a == 1)
	{
		vars.mandb = initialize_mandelbrot(argv);
		do_mandelbrot(vars.mandb, &vars, vars.img);
	}
	else
	{
		vars.julia = initialize_julia(argv);
		do_julia(vars.julia, &vars, vars.img);
	}
	doing_events(&vars);
	mlx_loop(vars.mlx);
	return (0);
}

void	check_arguments(char *argv[])
{
	char	*str;

	str = create_string(argv[1]);
	if (!ft_strncmp(str, "mandelbrot", 10) || !ft_strncmp(str, "1", 1))
	{
		free(str);
		ft_comments(2);
		ft_fractal(1, argv);
	}
	else if (!ft_strncmp(str, "julia", 5) || !ft_strncmp(str, "2", 1))
	{
		free(str);
		ft_comments(1);
		ft_fractal(2, argv);
	}
	else
	{
		ft_printf("Fractal not found.\n");
		ft_comments(0);
	}
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
		ft_comments(0);
	else
		check_arguments(argv);
	return (0);
}
