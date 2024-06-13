/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 09:54:13 by esimpson          #+#    #+#             */
/*   Updated: 2024/06/13 10:25:05 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_heredoc_sigint_handler(int signum)
{
	(void)signum;
	exit(SIGINT);
}

void	ft_heredoc(t_io_node *io, int p[2], t_minishell *myshell)
{
	char	*line;
	char	*quotes;

	signal(SIGINT, ft_heredoc_sigint_handler);
	quotes = io->value;
	while (*quotes && *quotes != '"' && *quotes != '\'')
		quotes++;
	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (ft_is_delimiter(io->value, line))
			break ;
		if (!*quotes)
			ft_heredoc_expander(line, p[1], myshell);
		else
		{
			ft_putstr_fd(line, p[1]);
			ft_putstr_fd("\n", p[1]);
		}
	}
	ft_clean_ms(myshell);
	exit(0);
}

static bool	ft_leave_leaf(int p[2], int *pid, t_minishell *myshell)
{
	waitpid(*pid, pid, 0);
	signal(SIGQUIT, ft_sigquit_handler);
	myshell->signint_child = false;
	close(p[1]);
	if (WIFEXITED(*pid) && WEXITSTATUS(*pid) == SIGINT)
		return (true);
	return (false);
}

static void	ft_init_leaf(t_node *node, t_minishell *my)
{
	t_io_node	*io;
	int			p[2];
	int			pid;

	if (node->args)
		node->expanded_args = ft_expand(node->args, &my->exit_s, &my->envlst);
	io = node->io_list;
	while (io)
	{
		if (io->type == IO_HEREDOC)
		{
			pipe(p);
			my->signint_child = true;
			pid = (signal(SIGQUIT, SIG_IGN), fork());
			if (!pid)
				ft_heredoc(io, p, my);
			if (ft_leave_leaf(p, &pid, my))
				return ;
			io->here_doc = p[0];
		}
		else
			io->expanded_value = ft_expand(io->value, &my->exit_s, &my->envlst);
		io = io->next;
	}
}

void	ft_init_tree(t_node *node, t_minishell *myshell)
{
	if (!node)
		return ;
	if (node->type == N_PIPE)
	{
		ft_init_tree(node->left, myshell);
		if (!myshell->heredoc_sigint)
			ft_init_tree(node->right, myshell);
	}
	else
		ft_init_leaf(node, myshell);
}
