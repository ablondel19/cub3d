/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:06:23 by ablondel          #+#    #+#             */
/*   Updated: 2021/02/12 17:28:07 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void		ft_init_bmp(t_bmp_h *bfh, t_bmp_i *bih, t_cub *admp)
{
	bfh->bfreserved1 = 0;
	bfh->bfreserved2 = 0;
	bfh->bfsize = 2 + sizeof(t_bmp_h) + sizeof(t_bmp_i) +
	admp->x_render_size * admp->y_render_size * 3;
	bfh->bfoffbits = 0x36;
	bih->bisize = sizeof(t_bmp_i);
	bih->biwidth = admp->x_render_size;
	bih->biheight = admp->y_render_size;
	bih->biplanes = 1;
	bih->bibitcount = 24;
	bih->bicompression = 0;
	bih->bisizeimage = 0;
	bih->bixpixelspermeter = 0;
	bih->biypixelspermeter = 0;
	bih->biclrused = 0;
	bih->biclrimportant = 0;
}

void		ft_bmp_loop(int fd, t_cub *admp)
{
	admp->r = ft_get_r(admp->saved[admp->x][admp->y]) / 255 / 255;
	admp->g = ft_get_g(admp->saved[admp->x][admp->y]) / 255;
	admp->b = ft_get_b(admp->saved[admp->x][admp->y]);
	write(fd, &admp->b, 1);
	write(fd, &admp->g, 1);
	write(fd, &admp->r, 1);
}

void		ft_save(t_cub *admp)
{
	t_bmp_h			bfh;
	t_bmp_i			bih;
	unsigned short	bftype;
	int				fd;

	bftype = 0x4d42;
	fd = open("save.bmp", O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	ft_init_bmp(&bfh, &bih, admp);
	write(fd, &bftype, sizeof(bftype));
	write(fd, &bfh, sizeof(bfh));
	write(fd, &bih, sizeof(bih));
	admp->y = bih.biheight - 1;
	admp->x = 0;
	while (admp->y >= 0)
	{
		while (admp->x < bih.biwidth)
		{
			ft_bmp_loop(fd, admp);
			admp->x++;
		}
		admp->x = 0;
		admp->y--;
	}
	close(fd);
	exit(EXIT_SUCCESS);
}
