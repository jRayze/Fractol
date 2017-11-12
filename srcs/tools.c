/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <jamerlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 14:03:57 by jamerlin          #+#    #+#             */
/*   Updated: 2017/10/31 12:11:33 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			close_hook(int button, t_fract *frac)
{
	(void)button;
	(void)frac;
	exit(0);
	return (0);
}

void		write_data_pixel(t_fract *frac)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	if (frac->iter == 0)
		frac->color = frac->colore / 1;
	else
		frac->color = frac->colore / frac->iter * 10;
	b = (frac->color & 0xFF0000) >> 16;
	g = (frac->color & 0xFF00) >> 8;
	r = (frac->color & 0xFF);
	if (frac->x >= 0 && frac->y >= 0 && frac->x <
		frac->width && frac->y < frac->height)
	{
		frac->data[frac->y * frac->sl + frac->x * (frac->bpp / 8)] = r;
		frac->data[frac->y * frac->sl + frac->x * (frac->bpp / 8) + 1] = g;
		frac->data[frac->y * frac->sl + frac->x * (frac->bpp / 8) + 2] = b;
	}
}

t_fract		*ft_init(char *argv)
{
	t_fract	*frac;

	if (!(frac = (t_fract *)malloc(sizeof(t_fract))))
		exit(EXIT_FAILURE);
	ft_init_pos(frac);
	frac->name = ft_strdup(argv);
	frac->bpp = 24;
	frac->endian = 1;
	frac->width = 600;
	frac->height = frac->width;
	frac->sl = frac->width * (frac->bpp / 8);
	frac->mlx = mlx_init();
	frac->win = mlx_new_window(frac->mlx, frac->width, frac->height, "fractol");
	frac->img = mlx_new_image(frac->mlx, frac->width, frac->height);
	frac->data = mlx_get_data_addr(frac->img, &frac->bpp,
		&frac->sl, &frac->endian);
	return (frac);
}

void		ft_init_pos(t_fract *frac)
{
	frac->zoom = 1;
	frac->colore = 0xFF0000;
	frac->h = 0;
	frac->w = 0;
	frac->pos_x = 0;
	frac->pos_y = 0;
	frac->imax = 50;
	frac->l = 0;
	frac->x_moove = 0;
	frac->y_moove = 0;
}
