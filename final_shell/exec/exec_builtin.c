/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 09:49:49 by esimpson          #+#    #+#             */
/*   Updated: 2024/06/13 09:50:13 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exec_builtin(char **args, t_minishell *myshell)
{
	if (ft_strcmp(args[0], "echo") == 0)
		return (ft_echo(args));
	if (ft_strcmp(args[0], "cd") == 0)
		return (ft_cd(args, &myshell->exit_s, myshell->envlst));
	if (ft_strcmp(args[0], "env") == 0)
		return (ft_env(myshell));
	if (ft_strcmp(args[0], "pwd") == 0)
		return (ft_pwd(&myshell->exit_s));
	if (ft_strcmp(args[0], "export") == 0)
		return (ft_export(args, &myshell->envlst, &myshell->exit_s));
	if (ft_strcmp(args[0], "unset") == 0)
		return (ft_unset(args, &myshell->envlst, &myshell->exit_s));
	ft_exit(args, &myshell->exit_s);
	return (ENO_GENERAL);
}

bool	ft_is_builtin(char *arg)
{
	if (!arg)
		return (false);
	if (!ft_strcmp(arg, "echo") || !ft_strcmp(arg, "cd") || !ft_strcmp(arg,
			"exit") || !ft_strcmp(arg, "pwd") || !ft_strcmp(arg, "export")
		|| !ft_strcmp(arg, "unset") || !ft_strcmp(arg, "env"))
		return (true);
	return (false);
}
