/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:22:04 by esimpson          #+#    #+#             */
/*   Updated: 2024/06/13 09:46:03 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	flag_nl(char *str)
{
	int	i;

	i = 1;
	if (str[0] == '-')
	{
		while (str[i] && str[i] == 'n')
			i++;
		if (str[i] == '\0')
			return (1);
	}
	return (0);
}

int	ft_echo(char **av)
{
	int	i;
	int	flag;

	i = 1;
	flag = 1;
	while (av[i] && flag_nl(av[i]))
	{
		flag = 0;
		i++;
	}
	while (av[i])
	{
		printf("%s", av[i]);
		if (av[i++ + 1])
			printf(" ");
	}
	if (flag)
		printf("\n");
	return (0);
}
