/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <tcuer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 16:43:22 by tcuer             #+#    #+#             */
/*   Updated: 2016/11/19 16:49:45 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		loop_hook(t_env *e)
{
	ft_draw(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

int		mousemove(int x, int y, t_env *e)
{
	if (x != e->b && x < WIDTH && y < HEIGHT && x > 0 && y > 0)
	{
		if (x > e->b)
			e->a = 1;
		if (x < e->b)
			e->a = 2;
		if (e->a && x != e->b)
		{
			if (e->a == 2)
				e->camspeed = -0.1;
			else if (e->a == 1)
				e->camspeed = 0.1;
			e->tmpdir = e->dirx;
			e->dirx = e->dirx * cos(-e->camspeed) - e->diry * sin(-e->camspeed);
			e->diry = e->tmpdir * sin(-e->camspeed) + e->diry *
				cos(-e->camspeed);
			e->tmpplane = e->planex;
			e->planex = e->planex * cos(-e->camspeed) - e->planey *
				sin(-e->camspeed);
			e->planey = e->tmpplane * sin(-e->camspeed) + e->planey *
				cos(-e->camspeed);
		}
	}
	e->b = x;
	return (0);
}

int		ft_exit(t_env *e)
{
	(void)e;
	exit(0);
	return (0);
}

int		expose_hook(t_env *e)
{
	mlx_do_sync(e->mlx);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}
