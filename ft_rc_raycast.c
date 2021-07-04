/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rc_raycast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:20:42 by ablondel          #+#    #+#             */
/*   Updated: 2021/02/12 16:07:09 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void		ft_setup_sprite_drawing(t_var *ad)
{
	ft_transform(ad, ad->sp);
	if (ad->drawstarty < 0)
		ad->drawstarty = 0;
	ad->drawendy = ad->spriteheight / 2 + ad->h / 2;
	if (ad->drawendy >= ad->h)
		ad->drawendy = ad->h - 1;
	ad->spritewidth = abs((int)(ad->h / (ad->transformy)));
	ad->drawstartx = -ad->spritewidth / 2 + ad->spritescreenx;
	if (ad->drawstartx < 0)
		ad->drawstartx = 0;
	ad->drawendx = ad->spritewidth / 2 + ad->spritescreenx;
	if (ad->drawendx >= ad->w)
		ad->drawendx = ad->w - 1;
	ad->stripe = ad->drawstartx;
}

void		ft_sprite_loop(t_var *ad, t_cub *admp)
{
	ad->d = ad->z * 256 - ad->h * 128 + ad->spriteheight * 128;
	ad->texys = ((ad->d * ad->texheight) / ad->spriteheight) / 256;
	ft_mlx_sprite(ad, ad->texxs, ad->texys, &ad->buffer[ad->stripe][ad->z]);
	if (ad->buffer[ad->stripe][ad->z] != 0x0)
	{
		ft_mlx_frame(ad, ad->stripe, ad->z, ad->buffer[ad->stripe][ad->z]);
		admp->saved[ad->stripe][ad->z] = ad->buffer[ad->stripe][ad->z];
	}
	ad->buffer[ad->stripe][ad->z] = 0;
	ad->z++;
}

void		*ft_raycast_sprites(t_var *ad, t_cub *admp)
{
	if (!(ad->sp = ft_setup_sprites(ad)))
		return (NULL);
	ft_sort_sprites(ad->sprite_order, ad->sprite_distance, ad->n);
	while (ad->i < ad->n)
	{
		ft_setup_sprite_drawing(ad);
		while (ad->stripe < ad->drawendx)
		{
			ad->z = ad->drawstarty;
			ad->texxs = ((ad->stripe -
			(-ad->spritewidth / 2 + ad->spritescreenx)) *
			ad->texwidth / ad->spritewidth);
			if ((ad->transformy > 0 && ad->stripe > 0 && ad->stripe < ad->w) &&
			ad->transformy < ad->zbuffer[ad->stripe])
			{
				while (ad->z < ad->drawendy)
					ft_sprite_loop(ad, admp);
			}
			ad->stripe++;
		}
		ad->i++;
	}
	return (ad);
}

void		*ft_raycast(t_var *ad, t_cub *admp)
{
	ad->x = -1;
	while (++ad->x <= ad->w - 1)
	{
		ft_setup_for_raycast(ad);
		if (ad->side == 0 && ad->raydirx > 0)
			ad->texx = ad->texwidth - ad->texx - 1;
		if (ad->side == 1 && ad->raydiry < 0)
			ad->texx = ad->texwidth - ad->texx - 1;
		ad->step = 1.0 * ad->texheight / ad->lineheight;
		ad->texpos = (ad->drawstart - ad->h / 2 +
		ad->lineheight / 2) * ad->step;
		ad->y = ad->drawstart;
		while (ad->y < ad->drawend)
			ft_raycast_loop(ad);
		ad->zbuffer[ad->x] = ad->perpwalldist;
		ft_draw_frame(ad, admp);
	}
	if (!(ft_raycast_sprites(ad, admp)))
		return (NULL);
	if (admp->save)
		ft_save(admp);
	mlx_clear_window(ad->mlx, ad->mlx_win);
	mlx_put_image_to_window(ad->mlx, ad->mlx_win, ad->img, 0, 0);
	ad->x = -1;
	return (ad);
}
