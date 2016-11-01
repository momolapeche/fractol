/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenegau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 17:33:43 by rmenegau          #+#    #+#             */
/*   Updated: 2016/11/01 10:17:36 by rmenegau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include "libft.h"

# define WINX 1000
# define WINY 1000

# define KEY_ESC 53
# define KEY_UP 125
# define KEY_DOWN 126
# define KEY_LEFT 124
# define KEY_RIGHT 123
# define KEY_PLUS 69
# define KEY_MINUS 78

typedef struct	s_cmplx
{
	double	r;
	double	i;
}				t_cmplx;

typedef struct	s_img
{
	void	*img;
	int		x;
	int		y;
	int		bpp;
	int		opp;
	int		sl;
	int		half_sl;
	int		endian;
	char	*data;
}				t_img;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	t_img	img;
	void	*f;
	int		id;
	int		it_max;
	int		x;
	int		y;
}				t_env;

int				test_args(int ac, char **av);
t_img			mlx_img_assign(t_env *e, int x, int y);
int				key_hook(int key, t_env *e);
int				expose_hook(t_env *e);
void			mlx_img_pxl(t_img img, int x, int y, unsigned c);
t_cmplx			add_cmplx(t_cmplx n1, t_cmplx n2);
t_cmplx			sub_cmplx(t_cmplx n1, t_cmplx n2);
t_cmplx			mlt_cmplx(t_cmplx n1, t_cmplx n2);
t_cmplx			mandel_cmplx(t_cmplx z, t_cmplx c);
int				mandelbrot(t_cmplx c, int it_max);
int				burning_ship(t_cmplx c, int it_max);
int				mandelbrot_cube(t_cmplx c, int it_max);
int				julia(t_cmplx n, t_cmplx c, int it_max);
int				julia_burning_ship(t_cmplx n, t_cmplx c, int it_max);
int				julia_cube(t_cmplx n, t_cmplx c, int it_max);
int				tricorne(t_cmplx c, int it_max);
int				tricorne_julia(t_cmplx n, t_cmplx c, int it_max);
int				burning_ship_other(t_cmplx c, int it_max);
int				julia_burning_ship_other(t_cmplx n, t_cmplx c, int it_max);

#endif
