/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <jamerlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 13:35:40 by jamerlin          #+#    #+#             */
/*   Updated: 2017/10/31 12:11:21 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		parsing(char *argv)
{
	if (ft_strcmp(argv, "Julia") != 0 &&
		ft_strcmp(argv, "Mandelbrot") != 0
		&& ft_strcmp(argv, "Sierpinski") != 0)
	{
		ft_putendl("usage : fdf [-Julia] / [-Mandelbrot] / [Sierpinski]");
		return (1);
	}
	else
		return (0);
}

void	ft_new_screen(t_fract *frac)
{
	mlx_destroy_image(frac->mlx, frac->img);
	frac->img = mlx_new_image(frac->mlx, frac->width, frac->height);
	frac->data = mlx_get_data_addr(frac->img, &frac->bpp,
		&frac->sl, &frac->endian);
}

int		do_fractole(t_fract *frac)
{
	if (ft_strcmp(frac->name, "Julia") == 0)
		do_julia(frac);
	else if (ft_strcmp(frac->name, "Mandelbrot") == 0)
		do_mandelbrot(frac);
	else if (ft_strcmp(frac->name, "Sierpinski") == 0)
		do_sierpinski(frac);
	mlx_hook(frac->win, 17, 0, close_hook, frac);
	mlx_put_image_to_window(frac->mlx, frac->win, frac->img, 0, 0);
	ft_new_screen(frac);
	return (1);
}

int		main(int argc, char **argv)
{
	t_fract	*frac;

	if (argc != 2)
	{
		ft_putendl("usage : fdf [Julia] / [Mandelbrot] / [Sierpinski]");
		return (1);
	}
	else if (parsing(argv[1]) == 1)
		return (1);
	frac = ft_init(argv[1]);
	do_fractole(frac);
	mlx_loop_hook(frac->mlx, do_fractole, frac);
	mlx_hook(frac->win, 2, 666, key_hook, frac);
	mlx_hook(frac->win, ButtonPress, ButtonPressMask, mouse_func, frac);
	mlx_hook(frac->win, MotionNotify, ButtonMotionMask, mouse_motion, frac);
	mlx_loop(frac->mlx);
	return (0);
}
