/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mp_add_south_tex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 13:32:53 by ablondel          #+#    #+#             */
/*   Updated: 2021/02/14 14:33:03 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		ft_add_south_tex(char *elem, t_cub *ad)
{
	int i;

	i = 0;
	if (ad->path_so_ispec == 1)
		return (-1);
	ft_skip_non_digit(elem, &i);
	if ((!(ad->path_so = ft_get_path(&elem[i]))) || (!elem[i]))
		return (-1);
	ad->path_so_ispec = 1;
	ad->data_found++;
	return (0);
}
