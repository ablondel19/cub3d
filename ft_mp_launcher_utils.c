/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mp_launcher_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 18:07:50 by ablondel          #+#    #+#             */
/*   Updated: 2021/02/15 15:56:29 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		ft_commas(char *elem)
{
	int commas;

	commas = 0;
	while (*elem)
	{
		if (*elem == ',')
			commas++;
		elem++;
	}
	if (commas != 2)
		return (0);
	return (1);
}

int		ft_valid_char(char c)
{
	return (c == '0' || c == '1' || c == '2' || c == ' ' ||
	c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

char	*ft_dup(t_cub *ad, char *src, char *dst)
{
	int i;

	i = 0;
	dst = NULL;
	if (!(dst = (char*)malloc(sizeof(char) * (ad->len_line + 1))))
		return (NULL);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	while (i < ad->len_line)
	{
		dst[i] = ' ';
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int		ft_select(char *elem, t_cub *ad)
{
	int n;

	n = -1;
	while (*elem == ' ' || *elem == '\t')
		elem++;
	if (*elem == '\0')
		n = 0;
	else if (*elem == 'R' && *(elem + 1) == ' ')
		n = ft_add_res((elem + 1), ad);
	else if (*elem == 'N' && *(elem + 1) == 'O')
		n = ft_add_north_tex((elem + 2), ad);
	else if (*elem == 'S' && *(elem + 1) == 'O')
		n = ft_add_south_tex((elem + 2), ad);
	else if (*elem == 'W' && *(elem + 1) == 'E')
		n = ft_add_west_tex((elem + 2), ad);
	else if (*elem == 'E' && *(elem + 1) == 'A')
		n = ft_add_east_tex((elem + 2), ad);
	else if (*elem == 'S' && *(elem + 1) == ' ')
		n = ft_add_sprite_tex((elem + 1), ad);
	else if (*elem == 'F' && *(elem + 1) == ' ')
		n = ft_add_floor_rgb((elem + 1), ad);
	else if (*elem == 'C' && *(elem + 1) == ' ')
		n = ft_add_ceiling_rgb((elem + 1), ad);
	return (n);
}

int		ft_launcher(t_cub *admp, t_list *lst)
{
	while (lst)
	{
		if (ft_select(lst->data, admp) == -1)
			return (ft_exit_all(4));
		else
		{
			free(lst->data);
			if (!(lst->data = ft_strdup("")))
				return (ft_exit_all(1));
		}
		if (ft_all_infos(admp) && admp->data_found == 8)
		{
			admp->data_found = 0;
			if (ft_find_dim(admp, lst) == -1)
				return (ft_exit_all(4));
			else if (ft_playable(admp) == -1)
				return (ft_exit_all(4));
			else
				ft_raycasting(admp);
			return (1);
		}
		lst = lst->next;
	}
	return (ft_exit_all(4));
}
