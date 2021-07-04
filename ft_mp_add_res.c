/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mp_add_res.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 13:21:05 by ablondel          #+#    #+#             */
/*   Updated: 2021/02/14 13:21:51 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_check_res(char *elem)
{
	while (((*elem >= '0' && *elem <= '9') || *elem == ' ' || *elem == '\t'))
		elem++;
	if (*elem != '\0')
		ft_exit_all(4);
}

void	ft_assign_rvalues(char *flags[3], t_cub *ad)
{
	if (flags[0] && flags[1])
	{
		ad->x_render_size = ft_atoi(flags[0]);
		ad->y_render_size = ft_atoi(flags[1]);
		if (ad->x_render_size)
			ad->x_ispec = 1;
		if (ad->y_render_size)
			ad->y_ispec = 1;
		if (ad->x_ispec == 1 && ad->y_ispec == 1)
			ad->data_found++;
	}
}

int		ft_add_res(char *elem, t_cub *ad)
{
	int		i;
	char	*flags[3];

	i = 0;
	flags[0] = 0;
	flags[1] = 0;
	flags[2] = 0;
	ft_check_res(elem);
	if (ad->x_ispec == 1 && ad->y_ispec == 1)
	{
		ad->data_found++;
		return (-1);
	}
	ft_skip_non_digit(elem, &i);
	if (ft_is_digit(elem[i]))
		flags[0] = &elem[i];
	ft_goto_next(elem, &i);
	if (ft_is_digit(elem[i]))
		flags[1] = &elem[i];
	ft_goto_next(elem, &i);
	if (ft_is_digit(elem[i]))
		return (ft_exit_all(4));
	ft_assign_rvalues(flags, ad);
	return (0);
}
