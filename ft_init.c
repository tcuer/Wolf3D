/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <tcuer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 16:40:13 by tcuer             #+#    #+#             */
/*   Updated: 2016/11/21 11:45:12 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_color_conv(int r, int g, int b)
{
	return ((r * 65536) + (g * 256) + b);
}

void	init_draw(t_env *e, t_draw *d)
{
	d->camerax = (2 * d->x / (double)WIDTH) - 1;
	d->rayposx = e->posx;
	d->rayposy = e->posy;
	d->raydirx = e->dirx + e->planex * d->camerax;
	d->raydiry = e->diry + e->planey * d->camerax;
	d->mapx = d->rayposx;
	d->mapy = d->rayposy;
	d->deltadistx = sqrt(1 + (d->raydiry * d->raydiry) /
			(d->raydirx * d->raydirx));
	d->deltadisty = sqrt(1 + (d->raydirx * d->raydirx) /
			(d->raydiry * d->raydiry));
	d->hit = 0;
}

void	fisheye(t_draw *d)
{
	if (d->side == 0)
		d->perpwalldist = fabs((d->mapx - d->rayposx +
					(1 - d->stepx) / 2) / d->raydirx);
	else
		d->perpwalldist = fabs((d->mapy - d->rayposy +
					(1 - d->stepy) / 2) / d->raydiry);
	d->lineheight = fabs(HEIGHT / d->perpwalldist);
	d->drawstart = -1 * d->lineheight / 2 + HEIGHT / 2;
	d->drawend = d->lineheight / 2 + HEIGHT / 2;
	if (d->drawstart < 0)
		d->drawstart = 0;
	if (d->drawend >= HEIGHT)
		d->drawend = HEIGHT - 1;
	d->y = d->drawstart;
}

void	init_main(t_env *e)
{
	ft_map(e);
	e->speed = 0.6;
	e->posx = 22;
	e->posy = 2.5;
	e->dirx = -1;
	e->diry = 0;
	e->planex = 0;
	e->planey = 1;
	e->b = 400;
}

void	ft_teleport(t_env *e, t_draw *d)
{
	if (e->map[d->mapx][d->mapy] == '2')
	{
		e->posx = 22;
		e->posy = 22;
		ft_fill_map2(e);
	}
	if (e->map[d->mapx][d->mapy] == '4')
	{
		e->posx = 22;
		e->posy = 2.5;
		ft_fill_map(e);
	}
}
