/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:17:31 by esimpson          #+#    #+#             */
/*   Updated: 2024/06/13 10:30:55 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_init_minishell(char **env, t_minishell *myshell)
{
	ft_memset(myshell, 0, sizeof(t_minishell));
	myshell->environ = env;
	init_env_list(env, &myshell->envlst);
	myshell->stdin = dup(0);
	myshell->stdout = dup(1);
	tcgetattr(STDIN_FILENO, &myshell->original_term);
}

static void	ft_start_execution(t_minishell *myshell)
{
	signal(SIGQUIT, ft_sigquit_handler);
	if (myshell->line[0])
		add_history(myshell->line);
	ft_init_tree(myshell->ast, myshell);
	if (myshell->heredoc_sigint)
	{
		ft_clear_ast(&myshell->ast, &myshell->tokens);
		myshell->heredoc_sigint = false;
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &myshell->original_term);
	myshell->exit_s = ft_exec_node(myshell->ast, false, myshell);
	ft_clear_ast(&myshell->ast, &myshell->tokens);
}

int	main(int argc, char **argv, char **env)
{
	t_minishell	my;

	((void)argc, (void)argv);
	ft_init_minishell(env, &my);
	while (1)
	{
		ft_init_signals(&my);
		my.line = readline(PROMPT_MSG);
		if (!my.line)
			(ft_clean_ms(&my), ft_putstr_fd("exit\n", 1), exit(my.exit_s));
		my.tokens = ft_tokenize(my.line, &my.exit_s);
		if (!my.tokens)
			continue ;
		my.ast = ft_parse(&my.tokens, &my.curr_token, &my.parse_err);
		if (my.parse_err.type)
		{
			ft_handle_parse_err(&my.parse_err, &my);
			continue ;
		}
		ft_start_execution(&my);
	}
	ft_garbage_collector(NULL, true);
	return (ft_clean_ms(&my), my.exit_s);
}
