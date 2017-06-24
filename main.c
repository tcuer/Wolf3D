/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 10:16:00 by tcuer             #+#    #+#             */
/*   Updated: 2016/11/19 18:47:37 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_move(t_env *e, char c)
{
	if (c == 'w')
	{
		if (e->map[(int)(e->posx + e->dirx * e->speed)][(int)e->posy] == '0')
			e->posx += e->dirx * e->speed;
		if (e->map[(int)e->posx][(int)(e->posy + e->diry * e->speed)] == '0')
			e->posy += e->diry * e->speed;
	}
	if (c == 's')
	{
		if (e->map[(int)(e->posx - e->dirx * e->speed)][(int)e->posy] == '0')
			e->posx -= e->dirx * e->speed;
		if (e->map[(int)e->posx][(int)(e->posy - e->diry * e->speed)] == '0')
			e->posy -= e->diry * e->speed;
	}
	if (c == 'a')
	{
		if (e->map[(int)(e->posx - e->planex * e->speed)][(int)e->posy] == '0')
			e->posx -= e->planex * e->speed;
		if (e->map[(int)e->posx][(int)(e->posy - e->planey * e->speed)] == '0')
			e->posy -= e->planey * e->speed;
	}
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
	{
		free(e->map);
		exit(0);
	}
	if (keycode == 13)
	{
		ft_move(e, 'w');
	}
	if (keycode == 1)
		ft_move(e, 's');
	if (keycode == 0)
		ft_move(e, 'a');
	if (keycode == 2)
	{
		if (e->map[(int)(e->posx + e->planex * e->speed)][(int)e->posy] == '0')
			e->posx += e->planex * e->speed;
		if (e->map[(int)e->posx][(int)(e->posy + e->planey * e->speed)] == '0')
			e->posy += e->planey * e->speed;
	}
	ft_draw(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (keycode);
}

int		main(void)
{
	t_env *e;

	e = (t_env *)ft_memalloc(sizeof(t_env));
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "Wolf3d");
	init_main(e);
	mlx_hook(e->win, 2, (1L << 0), key_hook, e);
	mlx_hook(e->win, 17, (1L << 17), ft_exit, e);
	mlx_hook(e->win, 6, 5, mousemove, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop_hook(e->mlx, loop_hook, e);
	mlx_loop(e->mlx);
	ft_draw(e);
	return (0);
}
