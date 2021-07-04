/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mp_playable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 11:30:09 by ablondel          #+#    #+#             */
/*   Updated: 2021/02/15 15:54:33 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_player_can_start(t_cub *ad)
{
	if (ad->x_start <= 0 || ad->y_start <= 0 ||
	ad->x_start >= ad->nbr_line - 1 || ad->y_start >= ad->len_line - 1)
		ft_exit_all(4);
}

int		ft_playable(t_cub *ad)
{
	ad->opened = 0;
	ft_check_borders(ad);
	if (ft_player_start(ad) == -1)
		if (ad->start_point != 1)
			ft_exit_all(4);
	ft_player_can_start(ad);
	ft_check_closed(ad);
	if (!ad->x_start || !ad->y_start)
		ft_exit_all(4);
	if (ad->opened == 1)
		ft_exit_all(5);
	return (1);
}
