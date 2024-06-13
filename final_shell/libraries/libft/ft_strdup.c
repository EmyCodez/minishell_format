/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:42:21 by esimpson          #+#    #+#             */
/*   Updated: 2024/06/13 10:42:25 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s1cpy;
	size_t	s1len;

	s1len = ft_strlen(s1);
	s1cpy = ft_calloc(s1len + 1, sizeof(char));
	if (!s1cpy)
		return (NULL);
	return (ft_memcpy(s1cpy, s1, s1len));
}
