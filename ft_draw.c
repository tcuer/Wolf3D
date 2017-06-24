/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <tcuer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:58:49 by tcuer             #+#    #+#             */
/*   Updated: 2016/11/21 11:16:52 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	raycast(t_draw *d)
{
	if (d->raydirx < 0)
	{
		d->stepx = -1;
		d->sidedistx = (d->rayposx - d->mapx) * d->deltadistx;
	}
	else
	{
		d->stepx = 1;
		d->sidedistx = (d->mapx + 1.0 - d->rayposx) * d->deltadistx;
	}
	if (d->raydiry < 0)
	{
		d->stepy = -1;
		d->sidedisty = (d->rayposy - d->mapy) * d->deltadisty;
	}
	else
	{
		d->stepy = 1;
		d->sidedisty = (d->mapy + 1.0 - d->rayposy) * d->deltadisty;
	}
}

void	rayhit(t_env *e, t_draw *d)
{
	while (d->hit == 0)
	{
		if (d->sidedistx < d->sidedisty)
		{
			d->sidedistx += d->deltadistx;
			d->mapx += d->stepx;
			d->side = 0;
		}
		else
		{
			d->sidedisty += d->deltadisty;
			d->mapy += d->stepy;
			d->side = 1;
		}
		if (e->map[d->mapx][d->mapy] > 48)
			d->hit = 1;
	}
}

void	draw_walls(t_env *e, t_draw *d)
{
	while (d->y < d->drawend)
	{
		if (d->side == 1)
		{
			if (d->stepy > 0)
				mlx_pixel_img(e->img, d->x, d->y,
						mlx_get_color_value(e->mlx, ft_color_conv(F, F, 0)));
			else
				mlx_pixel_img(e->img, d->x, d->y,
						mlx_get_color_value(e->mlx, ft_color_conv(0, F, 0)));
		}
		else
		{
			if (d->stepx > 0)
				mlx_pixel_img(e->img, d->x, d->y,
						mlx_get_color_value(e->mlx, ft_color_conv(F, 0, 0)));
			else
				mlx_pixel_img(e->img, d->x, d->y,
						mlx_get_color_value(e->mlx, ft_color_conv(0, 0, F)));
		}
		d->y++;
	}
}

void	draw_ceil_floor(t_env *e, t_draw *d)
{
	if (d->drawend < 0)
		d->drawend = HEIGHT;
	d->y = d->drawend;
	while (d->y < HEIGHT)
	{
		mlx_pixel_img(e->img, d->x, d->y,
				mlx_get_color_value(e->mlx, ft_color_conv(195, 145, 98)));
		mlx_pixel_img(e->img, d->x, HEIGHT - d->y - 1,
				mlx_get_color_value(e->mlx, ft_color_conv(7, 242, 255)));
		d->y++;
	}
}

void	ft_draw(t_env *e)
{
	t_draw *d;

	d = (t_draw *)ft_memalloc(sizeof(t_draw));
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	d->x = 0;
	d->y = 0;
	while (d->x < WIDTH)
	{
		init_draw(e, d);
		raycast(d);
		rayhit(e, d);
		fisheye(d);
		draw_walls(e, d);
		draw_ceil_floor(e, d);
		d->x++;
	}
	ft_teleport(e, d);
	free(d);
}
