/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenegau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 00:21:44 by rmenegau          #+#    #+#             */
/*   Updated: 2016/11/01 10:29:04 by rmenegau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_cmplx	add_cmplx(t_cmplx n1, t_cmplx n2)
{
	t_cmplx	ret;

	ret.r = n1.r + n2.r;
	ret.i = n1.i + n2.i;
	return (ret);
}

t_cmplx	sub_cmplx(t_cmplx n1, t_cmplx n2)
{
	t_cmplx	ret;

	ret.r = n1.r - n2.r;
	ret.i = n1.i - n2.i;
	return (ret);
}

t_cmplx	mlt_cmplx(t_cmplx n1, t_cmplx n2)
{
	t_cmplx	ret;

	ret.r = (n1.r * n2.r) - (n1.i * n2.i);
	ret.i = n1.r * n2.i + n1.i * n2.r;
	return (ret);
}

t_cmplx	mandel_cmplx(t_cmplx z, t_cmplx c)
{
	t_cmplx	ret;

	ret.r = z.r * z.r - z.i * z.i + c.r;
	ret.i = 2 * z.r * z.i + c.i;
	return (ret);
}
