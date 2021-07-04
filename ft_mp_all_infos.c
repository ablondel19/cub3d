/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mp_all_infos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:49:21 by ablondel          #+#    #+#             */
/*   Updated: 2021/02/13 12:41:01 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		ft_all_infos(t_cub *ad)
{
	if (ad->path_no_ispec == -1 || ad->path_so_ispec == -1 ||
	ad->path_we_ispec == -1 || ad->path_ea_ispec == -1 ||
	ad->path_sp_ispec == -1 || ad->x_ispec == -1 ||
	ad->y_ispec == -1 || ad->f_rgb == -1 || ad->c_rgb == -1)
		return (0);
	return (1);
}

void	ft_check_for_valid_map(char *s)
{
	while (ft_valid_char(*s))
		s++;
	if (*s != '\0')
		ft_exit_all(4);
}
