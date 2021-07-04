/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mp_exit_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 14:16:11 by ablondel          #+#    #+#             */
/*   Updated: 2021/02/13 13:26:17 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		ft_exit_all(int code)
{
	if (code == 1)
		ft_putstr_fd("Error\nMalloc failed.\n", 2);
	else if (code == 2)
		ft_putstr_fd("Error\nExtension is not .cub.\n", 2);
	else if (code == 3)
		ft_putstr_fd("Error\nOpen failed.\n", 2);
	else if (code == 4)
		ft_putstr_fd("Error\nMisconfiguration.\n", 2);
	else if (code == 5)
		ft_putstr_fd("Error\nMap is not closed.\n", 2);
	else if (code == 6)
		ft_putstr_fd("Error\nFailed to read lines from file.\n", 2);
	else if (code == 7)
		ft_putstr_fd("Error\nFile name missing.\n", 2);
	exit(EXIT_FAILURE);
	return (-1);
}
