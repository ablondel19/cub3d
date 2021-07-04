/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mp_add_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 15:14:10 by ablondel          #+#    #+#             */
/*   Updated: 2021/02/13 11:13:21 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		ft_valid_value(int a, int b, int c)
{
	return ((a >= 0 && a <= 255) &&
	(b >= 0 && b <= 255) &&
	(c >= 0 && c <= 255));
}

int		ft_is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

void	ft_skip_non_digit(char *s, int *i)
{
	int j;

	j = *i;
	while (s[j] && (s[j] == ' ' || s[j] == '\v' ||
	s[j] == '\r' || s[j] == '\t' || s[j] == '\f' ||
	s[j] == ','))
		j++;
	*i = j;
}

void	ft_skip_digit(char *s, int *i)
{
	int j;

	j = *i;
	while (s[j] && ft_is_digit(s[j]))
		j++;
	*i = j;
}

void	ft_goto_next(char *s, int *i)
{
	ft_skip_digit(s, i);
	ft_skip_non_digit(s, i);
}
