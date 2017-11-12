/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 11:55:58 by jamerlin          #+#    #+#             */
/*   Updated: 2017/10/31 12:12:11 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_func(int button, int x, int y, t_fract *frac)
{
	if (frac->zoom * 1.1 < 19280246.755011)
	{
		if ((button == 4 || button == 2) && frac->zoom / 1.1 > 0)
		{
			if (frac->imax > 100)
				frac->imax -= 5;
			frac->zoom /= 1.1;
			frac->pos_x -= (frac->width / 2) - x + 25 + frac->pos_x / 1.1;
			frac->pos_y -= (frac->height / 2) - y + frac->pos_y / 1.1;
		}
		if ((button == 5 || button == 1) && frac->zoom * 1.1 <= 1234648375)
		{
			frac->imax += 5;
			frac->zoom *= 1.1;
			frac->pos_x = (frac->width / 2) - x + 25 + frac->pos_x * 1.1;
			frac->pos_y = (frac->height / 2) - y + frac->pos_y * 1.1;
		}
	}
	return (1);
}

int		mouse_motion(int x, int y, t_fract *frac)
{
	if (frac->x_moove)
	{
		frac->stay = 1;
		frac->c_re = (float)(x + 550 - frac->width) / 400;
		frac->c_img = (float)(y + 450 - frac->height) / 600;
	}
	return (1);
}

int		key_hook(int keycode, t_fract *frac)
{
	if (keycode == 12)
		ft_init_pos(frac);
	if (keycode == 7)
		frac->x_moove == 1 ? frac->x_moove-- : frac->x_moove++;
	if (keycode == 16)
		frac->y_moove == 1 ? frac->y_moove-- : frac->y_moove++;
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (1);
}
