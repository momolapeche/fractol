/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenegau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 15:31:00 by rmenegau          #+#    #+#             */
/*   Updated: 2016/11/02 11:43:31 by rmenegau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_img_pxl(t_img img, int x, int y, unsigned c)
{
	if (x < 0 || y < 0 || x >= img.x || y >= img.y)
		return ;
	((unsigned *)(img.data))[y * img.half_sl + x] = c;
}

double	scale(double i, double max, double scale)
{
	return (i * scale / max);
}

unsigned	calc_color(int it, int max, unsigned color1, unsigned color2)
{
	unsigned char	c[4];
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *)&color1;
	c2 = (unsigned char *)&color2;
	c[0] = c2[0] * (max - it) / max + c1[0] * it / max;
	c[1] = c2[1] * (max - it) / max + c1[1] * it / max;
	c[2] = c2[2] * (max - it) / max + c1[2] * it / max;
	c[3] = c2[3] * (max - it) / max + c1[3] * it / max;
	return (*((unsigned *)c));
}

t_cmplx	mk_cmplx(double r, double i)
{

	t_cmplx	ret;

	ret.r = r;
	ret.i = i;
	return (ret);
}

void	get_func(t_env *e, char *name)
{
	e->id = 0;
	if (ft_strequ(name, "mandelbrot"))
		e->f = mandelbrot;
	if (++e->id && ft_strequ(name, "julia"))
		e->f = julia;
	if (++e->id && ft_strequ(name, "burning_ship"))
		e->f = burning_ship;
	if (++e->id && ft_strequ(name, "julia_burning_ship"))
		e->f = julia_burning_ship;
	if (++e->id && ft_strequ(name, "mandelbrot_cube"))
		e->f = mandelbrot_cube;
	if (++e->id && ft_strequ(name, "julia_cube"))
		e->f = julia_cube;
	if (++e->id && ft_strequ(name, "burning_ship_other"))
		e->f = burning_ship_other;
	if (++e->id && ft_strequ(name, "julia_burning_ship_other"))
		e->f = julia_burning_ship_other;
	if (++e->id && ft_strequ(name, "tricorne"))
		e->f = tricorne;
	if (++e->id && ft_strequ(name, "tricorne_julia"))
		e->f = tricorne_julia;
}

void	put_mandelbrot(t_env *e, t_img img)
{
	static int	(*f)(t_cmplx, int) = NULL;
	int	x;
	int	y;
	int	it;

	f = e->f;
	y = 0;
	while (y < img.y)
	{
		x = 0;
		while (x < img.x)
		{
			it = (*f)(mk_cmplx(scale(x, img.x, 4) - 2, scale(y, img.y, 4) - 2), e->it_max);
			mlx_img_pxl(img, x, y, calc_color(it, e->it_max, 0xffffff, 0x0));
			x++;
		}
		y++;
	}
}

void	mlx_img_reset(t_img img)
{
	unsigned	*data;
	size_t		i;
	size_t		len;

	data = (unsigned *)img.data;
	len = img.x * img.y;
	while (i < len)
		data[i++] = 0;
}

void	put_julia(t_env *e, t_img img, double mx, double my)
{
	static int	(*f)(t_cmplx, t_cmplx, int) = NULL;
	int		x;
	int		y;
	int		it;
	t_cmplx	m;

	f = e->f;
	m = mk_cmplx(scale(mx, img.x, 4) - 2, scale(my, img.y, 4) - 2);
	y = 0;
	while (y < img.y)
	{
		x = 0;
		while (x < img.x)
		{
			it = (*f)(mk_cmplx(scale(x, img.x, 4) - 2, scale(y, img.y, 4) - 2), m, e->it_max);
			mlx_img_pxl(img, x, y, calc_color(it, e->it_max, 0x8000, 0x0000));
			x++;
		}
		y++;
	}
}

int	mouse_hook(int x, int y, t_env *e)
{
	e->x = x;
	e->y = y;
	mlx_img_reset(e->img);
	put_julia(e, e->img, e->x, e->y);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0);
	return (0);
}

int	key_hook(int key, t_env *e)
{
	if (key == KEY_ESC)
		exit(0);
	if (key == KEY_PLUS)
		e->it_max <<= 1;
	if (key == KEY_MINUS)
		e->it_max >>= 1;
	if (e->it_max == 0)
		e->it_max = 1;
	mlx_img_reset(e->img);
	if (e->id % 2)
		put_julia(e, e->img, e->x, e->y);
	else
		put_mandelbrot(e, e->img);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_env	e;

	if (test_args(ac, av))
		return (0);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WINX, WINY, "fractol");
	e.img = mlx_img_assign(&e, WINX, WINY);
	e.it_max = 50;
	e.x = 0;
	e.y = 0;
	get_func(&e, av[1]);
	if (e.id % 2)
		put_julia(&e, e.img, 0, 0);
	else
		put_mandelbrot(&e, e.img);
	mlx_put_image_to_window(e.mlx, e.win, e.img.img, 0, 0);
	mlx_hook(e.win, 2, (1L << 0), key_hook, &e);
	if (e.id % 2)
		mlx_hook(e.win, 6, (1L << 6), mouse_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
