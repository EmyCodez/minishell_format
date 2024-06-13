/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:45:25 by esimpson          #+#    #+#             */
/*   Updated: 2024/06/13 10:45:28 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strs_len(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
