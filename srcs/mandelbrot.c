/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 11:58:41 by jamerlin          #+#    #+#             */
/*   Updated: 2017/10/31 12:12:03 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		calcul_re_im(t_fract *frac)
{
	frac->c_re = ((frac->y - frac->pos_y - ((frac->width + frac->h) / 2.0))
			* (4.0 / frac->width) / frac->zoom);
	frac->c_img = ((frac->x - frac->pos_x - ((frac->height + frac->w) / 2.0))
			* (4.0 / frac->width) / frac->zoom);
}

void			do_mandelbrot(t_fract *frac)
{
	double x;
	double y;
	double x_new;

	frac->x = -1;
	while (++frac->x < frac->height)
	{
		frac->y = -1;
		while (++frac->y < frac->width && (frac->iter = -1))
		{
			calcul_re_im(frac);
			y = 0;
			x = 0;
			while (x * x + y * y <= 4 && ++frac->iter < frac->imax)
			{
				x_new = x * x - y * y + frac->c_re;
				y = 2 * x * y + frac->c_img;
				x = x_new;
			}
			write_data_pixel(frac);
		}
	}
}
