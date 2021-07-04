/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mp_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:24:34 by ablondel          #+#    #+#             */
/*   Updated: 2021/02/13 11:13:23 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		ft_check_lst(t_list *lst)
{
	int n;

	n = 0;
	if (ft_strlen(lst->data))
		n = 1;
	while (lst->next)
	{
		if (ft_strlen(lst->data) == 0 && ft_strlen(lst->next->data))
			n++;
		lst = lst->next;
	}
	if (n > 1)
		return (-1);
	return (0);
}

void	ft_lstclear(t_list **lst)
{
	t_list *node;
	t_list *next;

	node = (*lst);
	next = NULL;
	if (!node)
		return ;
	while (node->next)
	{
		next = node->next;
		free(node->data);
		free(node);
		node = next;
	}
	free(node->data);
	free(node);
	(*lst) = NULL;
}

t_list	*ft_lstnew(char *data)
{
	t_list *new;

	new = NULL;
	new = (t_list*)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = ft_strdup(data);
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new_elem)
{
	t_list *node;

	node = (*lst);
	if (!(*lst))
	{
		new_elem->next = (*lst);
		(*lst) = new_elem;
		return ;
	}
	while (node->next)
		node = node->next;
	node->next = new_elem;
}

int		ft_stock_lines(t_list **lst, char *line)
{
	t_list	*new;

	if (!(new = ft_lstnew(line)))
		return (-1);
	ft_lstadd_back(lst, new);
	return (1);
}
