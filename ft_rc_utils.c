/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rc_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 17:01:10 by ablondel          #+#    #+#             */
/*   Updated: 2021/02/11 14:16:05 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_sort_sprites(int *spo, double *spd, int nbsp)
{
	int		i;
	int		itmp;
	double	dtmp;

	i = 0;
	itmp = 0;
	dtmp = 0;
	while (i + 1 < nbsp)
	{
		if (spd[i] <= spd[i + 1])
		{
			itmp = spo[i];
			dtmp = spd[i];
			spo[i] = spo[i + 1];
			spd[i] = spd[i + 1];
			spo[i + 1] = itmp;
			spd[i + 1] = dtmp;
			i = -1;
		}
		i++;
	}
}

void	ft_set_sprites(t_var *ad, t_sprite *sp)
{
	int i;
	int j;
	int spr;

	i = 0;
	j = 0;
	spr = 0;
	while (i < ad->nbr_line)
	{
		while (j < ad->len_line)
		{
			if (ad->worldmap[i][j] == 2)
			{
				sp[spr].x = i + 0.501;
				sp[spr].y = j + 0.498;
				spr++;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int		ft_count_sprites(t_var *ad)
{
	int i;
	int j;
	int nbsp;

	i = 0;
	j = 0;
	nbsp = 0;
	while (i < ad->nbr_line)
	{
		while (j < ad->len_line)
		{
			if (ad->worldmap[i][j] == 2)
				nbsp++;
			j++;
		}
		j = 0;
		i++;
	}
	return (nbsp);
}
