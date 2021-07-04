/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mp_launcher.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 11:35:17 by ablondel          #+#    #+#             */
/*   Updated: 2021/02/13 13:26:35 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		ft_copy_map(t_cub *ad, t_list *lst)
{
	int	i;

	i = 0;
	if (ft_check_lst(lst) == -1)
		return (ft_exit_all(4));
	if (!(ad->map = (char**)malloc(sizeof(char*) * (ad->nbr_line + 1))))
		return (ft_exit_all(1));
	while (lst)
	{
		if (ft_strlen(lst->data))
		{
			if (!(ad->map[i] = ft_dup(ad, lst->data, ad->map[i])))
				return (ft_exit_all(1));
			i++;
		}
		lst = lst->next;
	}
	ad->map[i] = 0;
	return (0);
}

int		ft_find_dim(t_cub *ad, t_list *lst)
{
	t_list	*node;

	node = lst;
	while (lst)
	{
		if (ft_strlen(lst->data))
		{
			ft_check_for_valid_map(lst->data);
			if (ft_strlen(lst->data) > ad->len_line)
				ad->len_line = ft_strlen(lst->data);
			ad->nbr_line++;
		}
		lst = lst->next;
	}
	if (ft_copy_map(ad, node) == -1)
		return (ft_exit_all(1));
	return (0);
}

void	ft_has_to_be_saved(int ac, char **av, t_cub *ad)
{
	if (ac == 3)
		if (ft_strcmp(av[2], "--save") == 0)
			ad->save = 1;
}

int		ft_launch(int ac, char **av, t_cub *ad)
{
	if (ft_partcmp(av[1]))
		return (ft_exit_all(2));
	ft_init_struct(ad);
	ft_has_to_be_saved(ac, av, ad);
	if ((ad->fd = open(av[1], O_RDONLY)) == -1)
		return (ft_exit_all(3));
	return (1);
}

int		main(int ac, char **av)
{
	t_cub	*ad;
	t_list	*lst;

	ad = NULL;
	lst = NULL;
	if (ac > 1)
	{
		if (!(ad = (t_cub*)malloc(sizeof(t_cub))))
			return (ft_exit_all(1));
		ft_launch(ac, av, ad);
		while (1)
		{
			if ((ad->ret = ft_gnl(ad->fd, &ad->line)) == -1)
				return (ft_exit_all(1));
			if (!(ft_stock_lines(&lst, ad->line)))
				return (ft_exit_all(6));
			free(ad->line);
			if (ad->ret <= 0)
			{
				ft_launcher(ad, lst);
				exit(EXIT_SUCCESS);
			}
		}
	}
	return (ft_exit_all(7));
}
