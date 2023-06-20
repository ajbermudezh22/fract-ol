/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:06:52 by albermud          #+#    #+#             */
/*   Updated: 2023/06/16 16:47:31 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol_bonus.h"

int	get_r(int m)
{
	int	color;

	color = (int)(0x00FF0000 - 0x00FF0000 * 20 * m);
	return (color);
}

int	get_g(int m)
{
	int	color;

	color = (int)(0x0000FF00 + 0x0000FF00 * 20 * m);
	return (color);
}

int	get_b(int m)
{
	int	color;

	color = (int)(0x000000FF + 0x000000FF * 20 * m);
	return (color);
}
