/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rc_save_bmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 13:05:31 by ablondel          #+#    #+#             */
/*   Updated: 2021/02/12 16:49:31 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_save_color(t_var *ad, int x, int y, size_t *color)
{
	char	*dst;

	dst = ad->addr + (y * ad->line_length + x * (ad->bits_per_pixel / 8));
	*color = *(unsigned int*)dst;
}

void	ft_save_buffer(t_var *ad, t_cub *admp)
{
	int i;

	i = -1;
	if (!(admp->saved = (size_t**)malloc(sizeof(size_t*) * (ad->w + 1))))
		ft_exit_all(1);
	while (++i < ad->w)
		if (!(admp->saved[i] = (size_t*)malloc(sizeof(size_t) * (ad->h + 1))))
			ft_exit_all(1);
	admp->saved[i] = NULL;
}
