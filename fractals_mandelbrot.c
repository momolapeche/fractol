/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_mandelbrot.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenegau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 06:31:14 by rmenegau          #+#    #+#             */
/*   Updated: 2016/11/01 10:21:42 by rmenegau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		tricorne(t_cmplx c, int it_max)
{
	int		it;
	t_cmplx	z;

	z.r = 0;
	z.i = 0;
	it = 0;
	while (z.r * z.r + z.i * z.i < 4 && it < it_max)
	{
		z.i = fabs(z.i);
		z = mlt_cmplx(z, z);
		z = mandel_cmplx(z, c);
//		z.r = -z.r;
		it++;
	}
	return (it);
}

int		burning_ship_other(t_cmplx c, int it_max)
{
	int		it;
	t_cmplx	z;

	z.r = 0;
	z.i = 0;
	it = 0;
	while (it < it_max && z.r * z.r + z.i * z.i < 4)
	{
//		z.r = fabs(z.r);
		z.i = fabs(z.i);
		z = mandel_cmplx(z, c);
		it++;
	}
	return (it);
}

int		burning_ship(t_cmplx c, int it_max)
{
	int		it;
	t_cmplx	z;

	z.r = 0;
	z.i = 0;
	it = 0;
	while (it < it_max && z.r * z.r + z.i * z.i < 4)
	{
		z.r = fabs(z.r);
		z.i = fabs(z.i);
		z = mandel_cmplx(z, c);
		it++;
	}
	return (it);
}

int		mandelbrot_cube(t_cmplx c, int it_max)
{
	int		it;
	t_cmplx	z;

	z.r = 0;
	z.i = 0;
	it = 0;
	while (z.r * z.r + z.i * z.i < 4 && it < it_max)
	{
		z = mlt_cmplx(z, z);
		z = mandel_cmplx(z, c);
		it++;
	}
	return (it);
}

int		mandelbrot(t_cmplx c, int it_max)
{
	int		it;
	t_cmplx	z;

	z.r = 0;
	z.i = 0;
	it = 0;
	while (z.r * z.r + z.i * z.i < 4 && it < it_max)
	{
		z = mandel_cmplx(z, c);
		it++;
	}
	return (it);
}
