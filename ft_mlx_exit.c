/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 11:33:30 by ablondel          #+#    #+#             */
/*   Updated: 2021/02/12 16:46:28 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		ft_mlx_exit(int code)
{
	if (code == 1)
		ft_putstr_fd("Error\nMalloc failed.\n", 2);
	else if (code == 2)
		ft_putstr_fd("Error\nFailed to initialize MLX.\n", 2);
	else if (code == 3)
		ft_putstr_fd("Error\nFailed to create window.\n", 2);
	else if (code == 4)
		ft_putstr_fd("Error\nFailed to create image.\n", 2);
	else if (code == 5)
		ft_putstr_fd("Error\nFailed to load xpm files.\n", 2);
	exit(EXIT_FAILURE);
	return (0);
}
