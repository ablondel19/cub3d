/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mp_gnl_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 23:02:16 by ablondel          #+#    #+#             */
/*   Updated: 2021/02/12 16:46:50 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int				ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void			ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

char			*ft_memzero(size_t len)
{
	char	*dst;

	if (!(dst = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len)
		dst[--len] = '\0';
	return (dst);
}

char			*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	if (!(dst = ft_memzero(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	i = 0;
	while (*s1)
		dst[i++] = *s1++;
	while (*s2)
		dst[i++] = *s2++;
	dst[i] = '\0';
	return (dst);
}

char			*ft_strdup(char *src)
{
	int		i;
	char	*dst;

	i = -1;
	if (!src)
		return (NULL);
	if (!(dst = malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	while (src[++i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}
