/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img_assign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenegau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 17:59:58 by rmenegau          #+#    #+#             */
/*   Updated: 2016/11/01 01:50:44 by rmenegau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_img	mlx_img_assign(t_env *e, int x, int y)
{
	t_img	img;

	img.img = mlx_new_image(e->mlx, x, y);
	img.data = mlx_get_data_addr(img.img, &img.bpp, &img.sl, &img.endian);
	img.x = x;
	img.y = y;
	img.opp = img.bpp >> 3;
	img.half_sl = img.sl >> 2;
	return (img);
}
