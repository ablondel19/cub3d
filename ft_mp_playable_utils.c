/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mp_playable_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 14:06:56 by ablondel          #+#    #+#             */
/*   Updated: 2021/02/15 15:56:46 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		ft_player_start(t_cub *ad)
{
	ad->i = 0;
	ad->j = 0;
	ad->start_point = 0;
	while (ad->i < ad->nbr_line)
	{
		while (ad->j < ad->len_line)
		{
			if (!ft_valid_char(ad->map[ad->i][ad->j]))
				return (-1);
			if (ad->map[ad->i][ad->j] == 'N' || ad->map[ad->i][ad->j] == 'S' ||
			ad->map[ad->i][ad->j] == 'E' || ad->map[ad->i][ad->j] == 'W')
			{
				ad->x_start = ad->i;
				ad->y_start = ad->j;
				ad->player = ad->map[ad->i][ad->j];
				ad->start_point++;
			}
			ad->j++;
		}
		ad->j = 0;
		ad->i++;
	}
	if (ad->start_point > 1 || ad->start_point == 0)
		return (-1);
	return (1);
}

int		ft_check_borders(t_cub *ad)
{
	ad->i = 0;
	ad->j = 0;
	while (ad->i < ad->nbr_line)
	{
		while (ad->j <= ad->len_line - 1)
		{
			if ((ad->map[ad->i][ad->j] == '0' ||
			ad->map[ad->i][ad->j] == '2') &&
			(ad->j - 1 < 0 || ad->i - 1 < 0 ||
			ad->j + 1 >= ad->len_line || ad->i + 1 >= ad->nbr_line))
			{
				ad->opened = 1;
				return (-1);
			}
			ad->j++;
		}
		ad->j = 0;
		ad->i++;
	}
	return (1);
}

int		ft_closed(t_cub *ad, int x, int y)
{
	if (ad->map[x][y] == '0' &&
	(ad->map[x][y + 1] == ' ' || ad->map[x][y - 1] == ' ' ||
	ad->map[x + 1][y] == ' ' || ad->map[x - 1][y] == ' ' ||
	ad->map[x + 1][y + 1] == ' ' || ad->map[x + 1][y - 1] == ' ' ||
	ad->map[x - 1][y - 1] == ' ' || ad->map[x - 1][y + 1] == ' ' ||
	ad->map[x][y] == ' ' || ad->map[x][y] == '\0'))
		ad->opened = 1;
	if (ad->cells++ >= 2000000)
		ad->opened = 1;
	if (ad->opened == 0)
	{
		if (x >= ad->nbr_line || y >= ad->len_line - 1 ||
		x <= 0 || y <= 0 || ad->map[x][y] != '0')
			return (0);
		ad->map[x][y] = '.';
		ft_closed(ad, x, y + 1);
		ft_closed(ad, x, y - 1);
		ft_closed(ad, x + 1, y);
		ft_closed(ad, x - 1, y);
		ft_closed(ad, x + 1, y + 1);
		ft_closed(ad, x + 1, y - 1);
		ft_closed(ad, x - 1, y - 1);
		ft_closed(ad, x - 1, y + 1);
	}
	return (0);
}

int		ft_check_closed(t_cub *ad)
{
	ad->cells = 0;
	ad->map[ad->x_start][ad->y_start] = '0';
	if (ft_closed(ad, ad->x_start, ad->y_start) == -1)
	{
		ad->map[ad->x_start][ad->y_start] = ad->player;
		return (-1);
	}
	ad->map[ad->x_start][ad->y_start] = ad->player;
	return (0);
}
