/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_ms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 09:47:32 by esimpson          #+#    #+#             */
/*   Updated: 2024/06/13 09:54:56 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_clear_envlst(t_env **envlst)
{
	t_env	*current;
	t_env	*temp;

	current = *envlst;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	(*envlst) = NULL;
}

void	ft_clean_ms(t_minishell *myshell)
{
	ft_garbage_collector(NULL, true);
	ft_clear_ast(&myshell->ast, &myshell->tokens);
	ft_clear_envlst(&myshell->envlst);
	tcsetattr(STDIN_FILENO, TCSANOW, &myshell->original_term);
}
