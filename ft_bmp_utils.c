/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:25:02 by ablondel          #+#    #+#             */
/*   Updated: 2021/02/12 17:28:04 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int			ft_get_r(int trgb)
{
	return (trgb & (0xFF << 16));
}

int			ft_get_g(int trgb)
{
	return (trgb & (0xFF << 8));
}

int			ft_get_b(int trgb)
{
	return (trgb & 0xFF);
}
