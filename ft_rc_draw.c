/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rc_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 16:28:47 by ablondel          #+#    #+#             */
/*   Updated: 2021/02/12 13:15:18 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

double			ft_rad(double degrees)
{
	return (degrees * (M_PI / 180.0));
}

int				ft_close(int keycode, void *param)
{
	(void)param;
	exit(EXIT_SUCCESS);
	return (keycode);
}

unsigned int	ft_create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void			ft_mlx_frame(t_var *ad, int x, int y, int color)
{
	char	*dst;

	dst = ad->addr + (y * ad->line_length + x * (ad->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void			*ft_load_xpm_files(t_var *ad, t_cub *admp)
{
	if ((!(ad->north = mlx_xpm_file_to_image(ad->mlx,
	admp->path_no, &ad->w_no, &ad->h_no))) ||
	(!(ad->south = mlx_xpm_file_to_image(ad->mlx,
	admp->path_so, &ad->w_so, &ad->h_so))) ||
	(!(ad->west = mlx_xpm_file_to_image(ad->mlx,
	admp->path_we, &ad->w_we, &ad->h_we))) ||
	(!(ad->east = mlx_xpm_file_to_image(ad->mlx,
	admp->path_ea, &ad->w_ea, &ad->h_ea))) ||
	(!(ad->sprite = mlx_xpm_file_to_image(ad->mlx,
	admp->path_sp, &ad->w_sp, &ad->h_sp))) ||
	(!(ad->addr_no = mlx_get_data_addr(ad->north,
	&ad->bpp_no, &ad->len_no, &ad->endian_no))) ||
	(!(ad->addr_so = mlx_get_data_addr(ad->south,
	&ad->bpp_so, &ad->len_so, &ad->endian_so))) ||
	(!(ad->addr_we = mlx_get_data_addr(ad->west,
	&ad->bpp_we, &ad->len_we, &ad->endian_we))) ||
	(!(ad->addr_ea = mlx_get_data_addr(ad->east,
	&ad->bpp_ea, &ad->len_ea, &ad->endian_ea))) ||
	(!(ad->addr_sp = mlx_get_data_addr(ad->sprite,
	&ad->bpp_sp, &ad->len_sp, &ad->endian_sp))))
		return (NULL);
	return (ad);
}
