/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 22:34:03 by mzoheir           #+#    #+#             */
/*   Updated: 2023/10/06 07:30:01 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	default_fds(t_list *cmds, t_general *sa)
{
	t_list	*head;

	head = cmds;
	sa->num_cmds = 0;
	sa->index = 0;
	sa->pid = 1;
	sa->del = NULL;
	while (head)
	{
		head->fd_out = 1;
		head->fd_in = 0;
		head = head->next;
	}
}

void	init_env_data(t_general *sa, char **envp)
{
	int	i;

	i = 0;
	sa->env = malloc(sizeof(char *) * (ft_size(envp) + 1));
	while (envp[i])
	{
		sa->env[i] = ft_strdup(envp[i]);
		i++;
	}
	sa->env[i] = NULL;
}
