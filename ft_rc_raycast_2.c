/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 15:32:28 by ablondel          #+#    #+#             */
/*   Updated: 2021/02/07 17:30:35 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_update(t_var *ad)
{
	if (ad->start_north)
	{
		ad->raydirx = ad->dirx + ad->planex * ad->camerax;
		ad->raydiry = ad->diry + ad->planey * ad->camerax;
	}
	if (ad->start_south)
	{
		ad->raydirx = ad->dirx - ad->planex * ad->camerax;
		ad->raydiry = ad->diry - ad->planey * ad->camerax;
	}
	if (ad->start_east)
	{
		ad->raydirx = ad->dirx - ad->planey * ad->camerax;
		ad->raydiry = ad->diry + ad->planex * ad->camerax;
	}
	if (ad->start_west)
	{
		ad->raydirx = ad->dirx + ad->planey * ad->camerax;
		ad->raydiry = ad->diry - ad->planex * ad->camerax;
	}
}

void	ft_select_texture(t_var *ad)
{
	if (ad->side == 0)
	{
		if ((int)ad->posx < ad->mapx)
			ad->select_tex = 1;
		else
			ad->select_tex = 2;
	}
	if (ad->side == 1)
	{
		if ((int)ad->posy < ad->mapy)
			ad->select_tex = 3;
		else
			ad->select_tex = 4;
	}
	ad->hit = 1;
}

void	ft_step(t_var *ad)
{
	if (ad->raydirx < 0)
	{
		ad->stepx = -1;
		ad->sidedistx = (ad->posx - ad->mapx) * ad->deltadistx;
	}
	else
	{
		ad->stepx = 1;
		ad->sidedistx = (ad->mapx + 1.0 - ad->posx) * ad->deltadistx;
	}
	if (ad->raydiry < 0)
	{
		ad->stepy = -1;
		ad->sidedisty = (ad->posy - ad->mapy) * ad->deltadisty;
	}
	else
	{
		ad->stepy = 1;
		ad->sidedisty = (ad->mapy + 1.0 - ad->posy) * ad->deltadisty;
	}
	ad->hit = 0;
}

void	ft_collision(t_var *ad)
{
	while (ad->hit == 0)
	{
		if (ad->sidedistx < ad->sidedisty)
		{
			ad->sidedistx += ad->deltadistx;
			ad->mapx += ad->stepx;
			ad->side = 0;
		}
		else
		{
			ad->sidedisty += ad->deltadisty;
			ad->mapy += ad->stepy;
			ad->side = 1;
		}
		if (ad->worldmap[ad->mapx][ad->mapy] == 1)
			ft_select_texture(ad);
	}
	if (ad->side == 0)
		ad->perpwalldist = (ad->mapx - ad->posx +
		(1 - ad->stepx) / 2) / ad->raydirx;
	else if (ad->side == 1)
		ad->perpwalldist = (ad->mapy - ad->posy +
		(1 - ad->stepy) / 2) / ad->raydiry;
}

void	ft_setup_for_raycast(t_var *ad)
{
	ad->camerax = ((double)(2 * ad->x) / (double)(ad->w) - 1);
	ad->mapx = (int)ad->posx;
	ad->mapy = (int)ad->posy;
	ft_update(ad);
	ad->deltadistx = sqrt(1 + (ad->raydiry * ad->raydiry) /
	(ad->raydirx * ad->raydirx));
	ad->deltadisty = sqrt(1 + (ad->raydirx * ad->raydirx) /
	(ad->raydiry * ad->raydiry));
	ft_step(ad);
	ft_collision(ad);
	ad->lineheight = (int)(ad->h / ad->perpwalldist);
	ad->drawstart = -ad->lineheight / 2 + ad->h / 2;
	if (ad->drawstart < 0)
		ad->drawstart = 0;
	ad->drawend = ad->lineheight / 2 + ad->h / 2;
	if (ad->drawend >= ad->h)
		ad->drawend = ad->h - 1;
	if (ad->side == 0)
		ad->wallx = ad->posy + ad->perpwalldist * ad->raydiry;
	else
		ad->wallx = ad->posx + ad->perpwalldist * ad->raydirx;
	ad->wallx -= floor((ad->wallx));
	ad->texx = (int)(ad->wallx * (double)ad->texwidth);
}
