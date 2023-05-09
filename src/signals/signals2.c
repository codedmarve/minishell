/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:17:04 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/05/09 12:17:18 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ctrl_c_heredoc(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "> ^C\n", 5);
		exit(1);
	}
}

void	sig_heredoc(void)
{
	struct sigaction	sa;

	ignore_ctrl_bslash();
	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_handler = &ctrl_c_heredoc;
	sigaction(SIGINT, &sa, NULL);
}

// void	sig_parent_heredoc(void)
// {
// 	struct sigaction	sa;

// 	ignore_ctrl_bslash();
// 	ft_memset(&sa, 0, sizeof(sa));
// 	sa.sa_handler = SIG_IGN;
// 	sigaction(SIGINT, &sa, NULL);
// }

void	ctrl_c_heredoc_parent(int sig)
{
	(void)sig;
}

void	sig_parent_heredoc2(void)
{
	struct sigaction	sa;

	ignore_ctrl_bslash();
	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_handler = ctrl_c_heredoc_parent;
	sigaction(SIGINT, &sa, NULL);
}