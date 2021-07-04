/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mp_add_north_tex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 13:27:33 by ablondel          #+#    #+#             */
/*   Updated: 2021/02/14 14:36:24 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

char	*ft_get_path(char *src)
{
	int		i;
	char	*dst;

	i = -1;
	if (!src)
		return (NULL);
	if (!(dst = malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	while (src[++i] && (src[i] != ' ' && src[i] != '\t'))
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}

int		ft_add_north_tex(char *elem, t_cub *ad)
{
	int i;

	i = 0;
	if (ad->path_no_ispec == 1)
		return (-1);
	ft_skip_non_digit(elem, &i);
	if ((!(ad->path_no = ft_get_path(&elem[i]))) || (!elem[i]))
		return (-1);
	ad->path_no_ispec = 1;
	ad->data_found++;
	return (0);
}
