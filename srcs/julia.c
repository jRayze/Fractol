/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 11:57:55 by jamerlin          #+#    #+#             */
/*   Updated: 2017/10/31 12:11:46 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		calc_julia(t_fract *frac)
{
	double	x;
	double	y;

	x = frac->new_re;
	y = frac->new_img;
	frac->new_re = x * x - y * y + frac->c_re;
	frac->new_img = 2 * x * y + frac->c_img;
}

void		do_julia(t_fract *frac)
{
	frac->y = -1;
	if (!frac->stay)
	{
		frac->c_re = 0.285;
		frac->c_img = 0.01;
	}
	while (++frac->y < frac->height)
	{
		frac->x = -1;
		while (++frac->x < frac->width && (frac->iter = -1))
		{
			frac->new_re = (frac->x - frac->pos_x - ((frac->width + frac->w)
						/ 2)) * (4.0 / frac->width) / frac->zoom;
			frac->new_img = (frac->y - frac->pos_y - ((frac->height + frac->h)
						/ 2)) * (4.0 / frac->width) / frac->zoom;
			while ((((frac->new_re * frac->new_re) + (frac->new_img *
				frac->new_img)) < 4) && ++frac->iter < frac->imax)
				calc_julia(frac);
			write_data_pixel(frac);
		}
	}
}
