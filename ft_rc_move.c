/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rc_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:15:31 by ablondel          #+#    #+#             */
/*   Updated: 2021/02/11 16:56:33 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_move_fb(t_var *ad, int key)
{
	if (key == 13)
	{
		if (ad->worldmap[(int)(ad->posx + ad->dirx * ad->movespeed)]
		[(int)(ad->posy)] == 0)
			ad->posx += ad->dirx * ad->movespeed;
		if (ad->worldmap[(int)(ad->posx)]
		[(int)(ad->posy + ad->diry * ad->movespeed)] == 0)
			ad->posy += ad->diry * ad->movespeed;
	}
	if (key == 1)
	{
		if (ad->worldmap[(int)(ad->posx - ad->dirx * ad->movespeed)]
		[(int)(ad->posy)] == 0)
			ad->posx -= ad->dirx * ad->movespeed;
		if (ad->worldmap[(int)(ad->posx)]
		[(int)(ad->posy - ad->diry * ad->movespeed)] == 0)
			ad->posy -= ad->diry * ad->movespeed;
	}
	ft_raycast(ad, ad->admp);
}

void	ft_move_lr(t_var *ad, int key)
{
	if (key == 0)
	{
		if (ad->worldmap[(int)(ad->posx + ad->diry * 0.1)]
		[(int)(ad->posy)] == 0)
			ad->posx += ad->diry * 0.1;
		if (ad->worldmap[(int)(ad->posx)]
		[(int)(ad->posy - ad->dirx * 0.1)] == 0)
			ad->posy -= ad->dirx * 0.1;
	}
	if (key == 2)
	{
		if (ad->worldmap[(int)(ad->posx - ad->diry * 0.1)]
		[(int)(ad->posy)] == 0)
			ad->posx -= ad->diry * 0.1;
		if (ad->worldmap[(int)(ad->posx)]
		[(int)(ad->posy + ad->dirx * 0.1)] == 0)
			ad->posy += ad->dirx * 0.1;
	}
	ft_raycast(ad, ad->admp);
}

void	ft_rotate_right(t_var *ad)
{
	double olddirx;
	double oldplanex;

	olddirx = ad->dirx;
	oldplanex = ad->planex;
	ad->dirx = ad->dirx * cos(ft_rad(-ad->rotspeed)) -
	ad->diry * sin(ft_rad(-ad->rotspeed));
	ad->diry = olddirx * sin(ft_rad(-ad->rotspeed)) +
	ad->diry * cos(ft_rad(-ad->rotspeed));
	ad->planex = ad->planex * cos(ft_rad(-ad->rotspeed)) -
	ad->planey * sin(ft_rad(-ad->rotspeed));
	ad->planey = oldplanex * sin(ft_rad(-ad->rotspeed)) +
	ad->planey * cos(ft_rad(-ad->rotspeed));
	ft_raycast(ad, ad->admp);
}

void	ft_rotate_left(t_var *ad)
{
	double olddirx;
	double oldplanex;

	olddirx = ad->dirx;
	oldplanex = ad->planex;
	ad->dirx = ad->dirx * cos(ft_rad(ad->rotspeed)) -
	ad->diry * sin(ft_rad(ad->rotspeed));
	ad->diry = olddirx * sin(ft_rad(ad->rotspeed)) +
	ad->diry * cos(ft_rad(ad->rotspeed));
	ad->planex = ad->planex * cos(ft_rad(ad->rotspeed)) -
	ad->planey * sin(ft_rad(ad->rotspeed));
	ad->planey = oldplanex * sin(ft_rad(ad->rotspeed)) +
	ad->planey * cos(ft_rad(ad->rotspeed));
	ft_raycast(ad, ad->admp);
}

int		ft_keycode(int key, void *param)
{
	if (key == 53)
		exit(0);
	if (key == 13 || key == 1)
		ft_move_fb(param, key);
	if (key == 0 || key == 2)
		ft_move_lr(param, key);
	if (key == 124)
		ft_rotate_left(param);
	if (key == 123)
		ft_rotate_right(param);
	return (key);
}
