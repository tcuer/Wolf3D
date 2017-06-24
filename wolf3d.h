/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcuer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 10:17:23 by tcuer             #+#    #+#             */
/*   Updated: 2017/06/24 18:47:25 by tcuer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# define WIDTH 800
# define HEIGHT 600
# define F 255

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	rayposx;
	double	rayposy;
	double	raydirx;
	double	raydiry;
	double	camera;
	double	speed;
	double	camspeed;
	double	tmpdir;
	double	tmpplane;
	char	**map;
	double	a;
	double	b;
}				t_env;

typedef struct	s_draw
{
	double	rayposx;
	double	rayposy;
	double	raydirx;
	double	raydiry;
	double	camerax;
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	stepx;
	double	stepy;
	double	side;
	double	perpwalldist;
	int		lineheight;
	int		hit;
	int		x;
	int		y;
	int		drawstart;
	int		drawend;
}				t_draw;

void			ft_map(t_env *e);
void			ft_fill_map(t_env *e);
void			ft_draw(t_env *e);
int				ft_color_conv(int r, int g, int b);
void			init_draw(t_env *e, t_draw *d);
void			init_main(t_env *e);
void			raycast(t_draw *d);
void			rayhit(t_env *e, t_draw *d);
void			fisheye(t_draw *e);
void			draw_walls(t_env *e, t_draw *d);
void			draw_ceil_floor(t_env *e, t_draw *d);
int				expose_hook(t_env *e);
int				ft_exit(t_env *e);
int				mousemove(int x, int y, t_env *e);
int				expose_hook(t_env *e);
int				loop_hook(t_env *e);
void			ft_move(t_env *e, char c);
int				r_hook(int keycode, t_env *e);
void			ft_fill_map2(t_env *e);
void			ft_teleport(t_env *e, t_draw *d);
#endif
