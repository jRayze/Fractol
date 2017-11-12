/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <jamerlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 13:40:27 by jamerlin          #+#    #+#             */
/*   Updated: 2017/10/31 12:16:13 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FRACTOL_H
# define _FRACTOL_H

# include "../libft/libft.h"
# include <math.h>
# include "mlx.h"
# include </System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/X.h>

typedef struct	s_fract
{
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	int			x;
	int			y;
	int			x_max;
	int			y_max;
	int			color;
	long double	zoom;
	int			iter;
	int			colore;
	int			width;
	int			height;
	char		*data;
	char		*name;
	int			sl;
	int			bpp;
	void		*win;
	void		*mlx;
	void		*img;
	int			endian;
	int			x_moove;
	int			y_moove;
	int			l;
	int			imax;
	int			pos_x;
	int			pos_y;
	int			h;
	int			w;
	double		new_img;
	double		new_re;
	double		c_re;
	double		c_img;
	int			h_pic;
	int			w_pic;
	int			stay;
}				t_fract;

void			do_julia(t_fract *frac);
void			do_mandelbrot(t_fract *frac);
void			do_sierpinski(t_fract *frac);
t_fract			*ft_init(char *argv);
void			ft_init_pos(t_fract *frac);
int				close_hook(int button, t_fract *frac);
void			write_data_pixel(t_fract *frac);
int				key_hook(int keycode, t_fract *frac);
int				mouse_motion(int x, int y, t_fract *frac);
int				mouse_func(int button, int x, int y, t_fract *frac);

#endif
