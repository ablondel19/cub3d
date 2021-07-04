/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rc_raycast_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 15:24:02 by ablondel          #+#    #+#             */
/*   Updated: 2021/02/13 11:13:40 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_draw_ceiling(t_var *ad, t_cub *admp)
{
	int i;
	int x;

	i = 0;
	x = (ad->h / 2 - ad->lineheight / 2);
	while (i <= x)
	{
		ft_mlx_frame(ad, (int)ad->x, i,
		ft_create_trgb(1, admp->c_r, admp->c_g, admp->c_b));
		admp->saved[ad->x][i] =
		ft_create_trgb(1, admp->c_r, admp->c_g, admp->c_b);
		i++;
	}
}

void	ft_draw_floor(t_var *ad, t_cub *admp)
{
	int i;

	i = (ad->h / 2 + ad->lineheight / 2);
	while (i < ad->h)
	{
		ft_mlx_frame(ad, (int)ad->x, i,
		ft_create_trgb(1, admp->f_r, admp->f_g, admp->f_b));
		admp->saved[ad->x][i] = \
		ft_create_trgb(1, admp->f_r, admp->f_g, admp->f_b);
		i++;
	}
}

void	ft_draw_frame(t_var *ad, t_cub *admp)
{
	ft_draw_ceiling(ad, admp);
	ft_draw_floor(ad, admp);
	ad->buffer[ad->x][ad->drawstart] = 0;
	while (ad->drawstart <= ad->drawend)
	{
		ft_mlx_frame(ad, ad->x, ad->drawstart,
		ad->buffer[ad->x][ad->drawstart]);
		admp->saved[ad->x][ad->drawstart] = ad->buffer[ad->x][ad->drawstart];
		ad->buffer[ad->x][ad->drawstart] = 0;
		ad->drawstart++;
	}
}

void	ft_start_direction(t_var *ad)
{
	if (ad->dirx == 1 && ad->started == 0)
	{
		ad->start_north = 1;
		ad->started = 1;
	}
	if (ad->dirx == -1 && ad->started == 0)
	{
		ad->start_south = 1;
		ad->started = 1;
	}
	if (ad->diry == 1 && ad->started == 0)
	{
		ad->start_east = 1;
		ad->started = 1;
	}
	if (ad->diry == -1 && ad->started == 0)
	{
		ad->start_west = 1;
		ad->started = 1;
	}
}
