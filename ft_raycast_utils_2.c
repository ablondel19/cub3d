/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 16:11:44 by ablondel          #+#    #+#             */
/*   Updated: 2021/02/19 11:05:37 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_raycast_loop(t_var *ad)
{
	ad->texy = (int)ad->texpos & (ad->texheight - 1);
	ad->texpos += ad->step;
	ft_mlx_tex(ad, ad->texx, ad->texy, &ad->buffer[ad->x][ad->y]);
	ad->admp->saved[ad->x][ad->y] = ad->buffer[ad->x][ad->y];
	if (ad->side == 1)
	{
		ad->buffer[ad->x][ad->y] =
		(ad->buffer[ad->x][ad->y] >> 1) & 8355711;
		ad->admp->saved[ad->x][ad->y] =
		(ad->buffer[ad->x][ad->y] >> 1) & 8355711;
	}
	ad->y++;
}

void	ft_mlx_sprite(t_var *ad, int x, int y, size_t *color)
{
	char	*dst;

	dst = ad->addr_sp + (y * ad->len_sp + x * (ad->bpp_sp / 8));
	*color = *(unsigned int*)dst;
}

void	ft_mlx_tex(t_var *ad, int x, int y, size_t *color)
{
	char	*dst;

	dst = NULL;
	if (!ad->addr_no || !ad->addr_so || !ad->addr_we || !ad->addr_ea)
		return ;
	if (ad->select_tex == 1)
		dst = ad->addr_so + (y * ad->len_so + x * (ad->bpp_so / 8));
	if (ad->select_tex == 2)
		dst = ad->addr_no + (y * ad->len_no + x * (ad->bpp_no / 8));
	if (ad->select_tex == 3)
		dst = ad->addr_we + (y * ad->len_we + x * (ad->bpp_we / 8));
	if (ad->select_tex == 4)
		dst = ad->addr_ea + (y * ad->len_ea + x * (ad->bpp_ea / 8));
	*color = *(unsigned int*)dst;
}
