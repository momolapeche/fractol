/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_julia.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenegau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 08:06:26 by rmenegau          #+#    #+#             */
/*   Updated: 2016/11/01 10:21:10 by rmenegau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		tricorne_julia(t_cmplx n, t_cmplx c, int it_max)
{
	int		it;

	it = 0;
	while (it < it_max && n.r * n.r + n.i * n.i < 4)
	{
		n.i = fabs(n.i);
		n = mlt_cmplx(n, n);
		n = mandel_cmplx(n, c);
//		n.r = -n.r;
		it++;
	}
	return (it);
}

int		julia_burning_ship(t_cmplx n, t_cmplx c, int it_max)
{
	int		it;

	it = 0;
	while (it < it_max && n.r * n.r + n.i * n.i < 4)
	{
		n.r = fabs(n.r);
		n.i = fabs(n.i);
		n = mandel_cmplx(n, c);
		it++;
	}
	return (it);
}

int		julia_burning_ship_other(t_cmplx n, t_cmplx c, int it_max)
{
	int		it;

	it = 0;
	while (it < it_max && n.r * n.r + n.i * n.i < 4)
	{
//		n.r = fabs(n.r);
		n.i = fabs(n.i);
		n = mandel_cmplx(n, c);
		it++;
	}
	return (it);
}

int		julia_cube(t_cmplx n, t_cmplx c, int it_max)
{
	int		it;

	it = 0;
	while (it < it_max && n.r * n.r + n.i * n.i < 4)
	{
		n = mlt_cmplx(n, n);
		n = mandel_cmplx(n, c);
		it++;
	}
	return (it);
}

int		julia(t_cmplx n, t_cmplx c, int it_max)
{
	int		it;

	it = 0;
	while (it < it_max && n.r * n.r + n.i * n.i < 4)
	{
		n = mandel_cmplx(n, c);
		it++;
	}
	return (it);
}
