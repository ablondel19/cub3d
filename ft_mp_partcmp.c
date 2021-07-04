/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mp_partcmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:27:15 by ablondel          #+#    #+#             */
/*   Updated: 2021/02/10 11:56:50 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

size_t	ft_partcmp(char *s1)
{
	size_t	i;
	size_t	j;
	char	*s2;

	i = ft_strlen(s1) - 4;
	j = 0;
	s2 = ".cub";
	if (s1[0] == '.')
		return (1);
	while (s1[i] && s2[j])
	{
		if (s1[i] != s2[j])
			return (1);
		i++;
		j++;
	}
	return (0);
}
