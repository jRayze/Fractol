/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <jamerlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 14:01:38 by jamerlin          #+#    #+#             */
/*   Updated: 2017/10/31 12:11:54 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		do_sierpinski(t_fract *frac)
{
	frac->iter = 50;
	frac->y = -1;
	while (++frac->y < frac->height)
	{
		frac->x = -1;
		while (++frac->x < frac->width && (frac->iter = -1))
		{
			frac->c_img = fabsl((frac->x - frac->pos_x -
				(((frac->height + (frac->w * 1000)) / 2)) *
				(4.0 / frac->width)));
			frac->c_re = fabsl((frac->y - frac->pos_y -
				(((frac->height + (frac->h * 1000)) / 2)) *
				(4.0 / frac->width)));
			while (((int)frac->c_img % 3 != 1 ||
				((int)frac->c_re % 3) != 1) && ++frac->iter < frac->imax)
			{
				frac->c_img /= 3;
				frac->c_re /= 3;
			}
			if (frac->iter != frac->imax)
				frac->iter = 1;
			write_data_pixel(frac);
		}
	}
}
