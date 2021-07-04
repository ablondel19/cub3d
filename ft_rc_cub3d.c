/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rc_cub3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:48:55 by ablondel          #+#    #+#             */
/*   Updated: 2021/02/12 16:52:23 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_set_screen_size(t_var *ad, t_cub *admp)
{
	mlx_get_screen_size(ad->mlx, &ad->x_size_max, &ad->y_size_max);
	if (admp->x_render_size <= 0 || admp->y_render_size <= 0)
		ft_exit_all(4);
	if (admp->x_render_size >= ad->x_size_max)
	{
		admp->x_render_size = ad->x_size_max;
		ad->w = ad->x_size_max;
	}
	if (admp->y_render_size >= ad->y_size_max)
	{
		admp->y_render_size = ad->y_size_max;
		ad->h = ad->y_size_max;
	}
}

int		ft_raycasting(t_cub *admp)
{
	t_var *ad;

	ad = NULL;
	if (!(ad = ft_init(ad, admp)))
		return (ft_mlx_exit(1));
	ft_start_direction(ad);
	if (!(ad->mlx = mlx_init()))
		return (ft_mlx_exit(2));
	ft_set_screen_size(ad, admp);
	if (!(ad->mlx_win = mlx_new_window(ad->mlx, ad->w, ad->h, "cub3d")))
		return (ft_mlx_exit(3));
	if ((!(ad->img = mlx_new_image(ad->mlx, ad->w, ad->h))) ||
	(!(ad->addr = mlx_get_data_addr(ad->img, &ad->bits_per_pixel,
	&ad->line_length, &ad->endian))))
		return (ft_mlx_exit(4));
	if (!(ad = ft_load_xpm_files(ad, admp)))
		return (ft_mlx_exit(5));
	ad->admp = admp;
	ft_save_buffer(ad, admp);
	ft_raycast(ad, admp);
	mlx_hook(ad->mlx_win, 17, 1L << 17, &ft_close, NULL);
	mlx_hook(ad->mlx_win, 2, 1L << 1, &ft_keycode, ad);
	mlx_do_sync(ad->mlx);
	mlx_loop(ad->mlx);
	return (0);
}
