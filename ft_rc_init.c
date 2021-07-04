/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rc_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:03:59 by ablondel          #+#    #+#             */
/*   Updated: 2021/02/12 14:08:05 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_init_textures(t_var *ad)
{
	ad->w_no = 0;
	ad->h_no = 0;
	ad->bpp_no = 0;
	ad->len_no = 0;
	ad->endian_no = 0;
	ad->w_so = 0;
	ad->h_so = 0;
	ad->bpp_so = 0;
	ad->len_so = 0;
	ad->endian_so = 0;
	ad->w_we = 0;
	ad->h_we = 0;
	ad->bpp_we = 0;
	ad->len_we = 0;
	ad->endian_we = 0;
	ad->w_ea = 0;
	ad->h_ea = 0;
	ad->bpp_ea = 0;
	ad->len_ea = 0;
	ad->endian_ea = 0;
	ad->w_sp = 0;
	ad->h_sp = 0;
	ad->bpp_sp = 0;
	ad->len_sp = 0;
	ad->endian_sp = 0;
}

void	ft_init_drawing(t_var *ad)
{
	ad->bits_per_pixel = 0;
	ad->line_length = 0;
	ad->endian = 0;
	ad->drawstart = 0;
	ad->drawend = 0;
	ad->lineheight = 0;
	ad->texwidth = 64;
	ad->texheight = 64;
	ad->select_tex = 0;
	ad->texx = 0;
	ad->texy = 0;
	ad->step = 0;
	ad->texpos = 0;
	ad->x = 0;
	ad->y = 0;
	ad->mapx = 0;
	ad->mapy = 0;
}

int		ft_alloc_buffer(t_var *ad)
{
	int i;

	i = -1;
	if (!(ad->zbuffer = (double*)malloc(sizeof(double) * (ad->w + 1))))
		return (ft_exit_all(1));
	if (!(ad->buffer = (size_t**)malloc(sizeof(size_t*) * (ad->w + 1))))
		return (ft_exit_all(1));
	while (++i < ad->w)
		if (!(ad->buffer[i] = (size_t*)malloc(sizeof(size_t) * (ad->h + 1))))
			return (ft_exit_all(1));
	ad->buffer[i] = NULL;
	return (0);
}

t_var	*ft_init(t_var *ad, t_cub *admp)
{
	if (!(ad = (t_var*)malloc(sizeof(t_var))))
		return (NULL);
	ad->w = admp->x_render_size;
	ad->h = admp->y_render_size;
	ad->worldmap = NULL;
	ft_map(ad, admp);
	ft_init_refs_and_start_pos(ad, admp);
	ft_init_textures(ad);
	ft_init_drawing(ad);
	ft_alloc_buffer(ad);
	ad->stepx = 0;
	ad->stepy = 0;
	ad->hit = 0;
	ad->side = 0;
	ad->camerax = 0;
	ad->raydirx = 0;
	ad->raydiry = 0;
	ad->sidedistx = 0;
	ad->sidedisty = 0;
	ad->deltadistx = 0;
	ad->deltadisty = 0;
	ad->perpwalldist = 0;
	ad->wallx = 0;
	return (ad);
}
