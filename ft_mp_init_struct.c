/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mp_init_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 12:28:33 by ablondel          #+#    #+#             */
/*   Updated: 2021/02/12 17:08:01 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_init_hlpr(t_cub *ad)
{
	ad->ret = 1;
	ad->fd = -1;
	ad->line = 0;
	ad->map = 0;
	ad->path_no = 0;
	ad->path_so = 0;
	ad->path_we = 0;
	ad->path_ea = 0;
	ad->path_sp = 0;
	ad->player = 0;
	ad->start_point = 0;
	ad->opened = 0;
	ad->i = 0;
	ad->j = 0;
}

void	ft_init_struct(t_cub *ad)
{
	ft_init_hlpr(ad);
	ad->data_found = 0;
	ad->nbr_line = 0;
	ad->len_line = 0;
	ad->path_no_ispec = -1;
	ad->path_so_ispec = -1;
	ad->path_we_ispec = -1;
	ad->path_ea_ispec = -1;
	ad->path_sp_ispec = -1;
	ad->x_render_size = -1;
	ad->x_ispec = -1;
	ad->y_render_size = -1;
	ad->y_ispec = -1;
	ad->f_r = -1;
	ad->f_g = -1;
	ad->f_b = -1;
	ad->f_rgb = -1;
	ad->c_r = -1;
	ad->c_g = -1;
	ad->c_b = -1;
	ad->c_rgb = -1;
	ad->x_start = -1;
	ad->y_start = -1;
	ad->empty_lines = 0;
}
