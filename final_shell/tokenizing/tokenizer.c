/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:27:41 by esimpson          #+#    #+#             */
/*   Updated: 2024/06/13 10:27:45 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*ft_tokenize(char *line, int *exit_code)
{
	t_token	*token_list;

	token_list = ft_tokenization_handler(line, exit_code);
	return (token_list);
}
