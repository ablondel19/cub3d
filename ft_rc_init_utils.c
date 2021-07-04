/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rc_init_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 11:24:53 by ablondel          #+#    #+#             */
/*   Updated: 2021/02/14 11:43:55 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_alloc_map(t_var *ad, t_cub *admp)
{
	int i;

	i = -1;
	if (!(ad->worldmap = (int**)malloc(sizeof(int*) * (admp->nbr_line))))
		ft_exit_all(1);
	while (++i < admp->nbr_line)
		if (!(ad->worldmap[i] = (int*)malloc(sizeof(int) * (admp->len_line))))
			ft_exit_all(1);
}

int		ft_map(t_var *ad, t_cub *admp)
{
	int i;
	int j;

	i = -1;
	j = -1;
	ad->nbr_line = admp->nbr_line;
	ad->len_line = admp->len_line;
	ft_alloc_map(ad, admp);
	while (++i < admp->nbr_line)
	{
		while (++j < admp->len_line)
		{
			if (admp->map[i][j] == '1' || admp->map[i][j] == '0'
			|| admp->map[i][j] == '2')
				ad->worldmap[i][j] = admp->map[i][j] - '0';
			else
				ad->worldmap[i][j] = 0;
		}
		j = -1;
	}
	return (0);
}

void	ft_player_start_pos(t_var *ad, t_cub *admp)
{
	ad->posx = admp->x_start + 0.5;
	ad->posy = admp->y_start + 0.5;
	if (admp->player == 'N')
	{
		ad->dirx = -1.0;
		ad->diry = 0.0;
	}
	if (admp->player == 'S')
	{
		ad->dirx = 1.0;
		ad->diry = 0.0;
	}
	if (admp->player == 'W')
	{
		ad->dirx = 0.0;
		ad->diry = -1.0;
	}
	if (admp->player == 'E')
	{
		ad->dirx = 0.0;
		ad->diry = 1.0;
	}
}

void	ft_init_refs_and_start_pos(t_var *ad, t_cub *admp)
{
	ft_player_start_pos(ad, admp);
	ad->mlx = NULL;
	ad->mlx_win = NULL;
	ad->img = NULL;
	ad->addr = NULL;
	ad->north = NULL;
	ad->addr_no = NULL;
	ad->south = NULL;
	ad->addr_so = NULL;
	ad->west = NULL;
	ad->addr_we = NULL;
	ad->east = NULL;
	ad->addr_ea = NULL;
	ad->sprite = NULL;
	ad->addr_sp = NULL;
	ad->planey = M_2_PI;
	ad->planex = 0;
	ad->movespeed = ad->planey / 3;
	ad->rotspeed = 4;
	ad->start_north = 0;
	ad->start_south = 0;
	ad->start_west = 0;
	ad->start_east = 0;
	ad->started = 0;
}
