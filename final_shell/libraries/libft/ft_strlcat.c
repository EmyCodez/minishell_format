/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:43:37 by esimpson          #+#    #+#             */
/*   Updated: 2024/06/13 10:43:40 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	i;
	size_t	j;

	if ((!dst || !src) && !dstsize)
	{
		if (dst)
			return (ft_strlen(dst));
		return (ft_strlen(src));
	}
	dst_len = ft_strlen(dst);
	if (dstsize <= dst_len)
		return (dstsize + ft_strlen(src));
	i = 0;
	while (dst[i])
		i++;
	j = 0;
	while (src[j] && i < (dstsize - 1))
		dst[i++] = src[j++];
	dst[i] = 0;
	return (dst_len + ft_strlen(src));
}
