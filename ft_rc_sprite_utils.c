/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 15:40:53 by ablondel          #+#    #+#             */
/*   Updated: 2021/02/07 17:48:39 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

t_sprite	*ft_setup_sprites(t_var *ad)
{
	ad->n = 0;
	ad->i = 0;
	ad->sp = NULL;
	ad->n = ft_count_sprites(ad);
	if (!(ad->sp = (t_sprite*)malloc(sizeof(t_sprite) * (ad->n + 1))))
		return (NULL);
	ad->sp[ad->n].x = 0;
	ad->sp[ad->n].y = 0;
	if (!(ad->sprite_order = (int*)malloc(sizeof(int) * (ad->n + 1))))
		return (NULL);
	if (!(ad->sprite_distance = (double*)malloc(sizeof(double) * (ad->n + 1))))
		return (NULL);
	ft_set_sprites(ad, ad->sp);
	while (ad->i < ad->n)
	{
		ad->sprite_order[ad->i] = ad->i;
		ad->sprite_distance[ad->i] = ((ad->posx - ad->sp[ad->i].x) *
		(ad->posx - ad->sp[ad->i].x) + (ad->posy - ad->sp[ad->i].y) *
		(ad->posy - ad->sp[ad->i].y));
		ad->i++;
	}
	ad->i = 0;
	return (ad->sp);
}

void		ft_transform_north_south(t_var *ad)
{
	ad->invdet = 1.0 / (ad->planex * ad->diry - ad->dirx * ad->planey);
	if (ad->start_south)
		ad->transformx = ad->invdet *
		(ad->diry * -ad->spritex - ad->dirx * -ad->spritey);
	else if (ad->start_north)
		ad->transformx = ad->invdet *
		(ad->diry * ad->spritex - ad->dirx * ad->spritey);
	ad->transformy = ad->invdet *
	(-ad->planey * ad->spritex + ad->planex * ad->spritey);
}

void		ft_transform_east_west(t_var *ad)
{
	ad->invdet = 1.0 / (ad->planex * ad->dirx + ad->diry * ad->planey);
	if (ad->start_east)
		ad->transformx = ad->invdet *
		(ad->diry * -ad->spritex + ad->dirx * ad->spritey);
	else if (ad->start_west)
		ad->transformx = ad->invdet *
		(ad->diry * ad->spritex + ad->dirx * -ad->spritey);
	ad->transformy = ad->invdet *
	(ad->planey * ad->spritey + ad->planex * ad->spritex);
}

void		ft_transform(t_var *ad, t_sprite *sp)
{
	ad->spritex = (sp[ad->sprite_order[ad->i]].x - ad->posx);
	ad->spritey = (sp[ad->sprite_order[ad->i]].y - ad->posy);
	if (ad->start_north || ad->start_south)
		ft_transform_north_south(ad);
	if (ad->start_east || ad->start_west)
		ft_transform_east_west(ad);
	ad->spritescreenx = (int)((ad->w / 2) *
	(1 + ad->transformx / ad->transformy));
	ad->spriteheight = abs((int)(ad->h / (ad->transformy)));
	ad->drawstarty = -ad->spriteheight / 2 + ad->h / 2;
}
