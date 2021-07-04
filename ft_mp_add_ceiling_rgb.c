/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mp_add_ceiling_rgb.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 13:44:26 by ablondel          #+#    #+#             */
/*   Updated: 2021/02/14 16:49:30 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_check_ceiling(char *elem)
{
	while (((*elem >= '0' && *elem <= '9') || *elem == ',' ||
	*elem == '\t' || *elem == ' '))
		elem++;
	if (*elem != '\0')
		ft_exit_all(4);
}

void	ft_assign_cvalues(char *flags[3], t_cub *ad)
{
	if (flags[0] && flags[1] && flags[2])
	{
		ad->c_r = ft_atoi(flags[0]);
		ad->c_g = ft_atoi(flags[1]);
		ad->c_b = ft_atoi(flags[2]);
		if (ft_valid_value(ad->c_r, ad->c_g, ad->c_b))
		{
			ad->c_rgb = 1;
			ad->data_found++;
		}
	}
}

int		ft_add_ceiling_rgb(char *elem, t_cub *ad)
{
	int		i;
	char	*flags[3];

	i = 0;
	flags[0] = 0;
	flags[1] = 0;
	flags[2] = 0;
	ft_check_ceiling(elem);
	if ((!ft_commas(elem)) || (ad->c_rgb == 1))
		return (-1);
	ft_skip_non_digit(elem, &i);
	if (ft_is_digit(elem[i]))
		flags[0] = &elem[i];
	ft_goto_next(elem, &i);
	if (ft_is_digit(elem[i]))
		flags[1] = &elem[i];
	ft_goto_next(elem, &i);
	if (ft_is_digit(elem[i]))
		flags[2] = &elem[i];
	ft_goto_next(elem, &i);
	if (ft_is_digit(elem[i]))
		ft_exit_all(4);
	ft_assign_cvalues(flags, ad);
	return (0);
}
