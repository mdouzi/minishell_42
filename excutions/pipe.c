/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 04:54:27 by mdouzi            #+#    #+#             */
/*   Updated: 2023/10/06 05:35:39 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

int	numberof_cmd(t_list *cmds)
{
	int		nb;
	t_list	*tmp;

	tmp = cmds;
	nb = 0;
	if (cmds->final_cmd == NULL)
		return (0);
	else
	{
		while (tmp)
		{
			nb++;
			tmp = tmp->next;
		}
	}
	return (nb);
}

void	child_job(int **fd, t_general *sa, t_list *tmp, int index)
{
	if (index > 0)
	{
		dup2(fd[index - 1][0], STDIN_FILENO);
		close(fd[index - 1][0]);
		close(fd[index - 1][1]);
	}
	if (index < (sa->num_cmds - 1))
	{
		dup2(fd[index][1], STDOUT_FILENO);
		close(fd[index][0]);
		close(fd[index][1]);
	}
	if (is_builtin(tmp->final_cmd) == 1)
	{
		dup_fds(tmp);
		handle_builtins(tmp, sa);
		close_fds(tmp);
	}
	else
	{
		dup_fds(tmp);
		ex_cmd(sa, tmp);
		close_fds(tmp);
	}
	exit(EXIT_SUCCESS);
}

void	parent_job(int **fd, int *index, t_list *tmp)
{
	close_fds(tmp);
	if (*index > 0)
	{
		close(fd[*index - 1][0]);
		close(fd[*index - 1][1]);
	}
	tmp = tmp->next;
	*index = *index + 1;
}

int	wait_and_close(int **fd, int num_cmds, t_general *sa)
{
	int	i;
	int	exit_status;

	i = 0;
	exit_status = 0;
	while (i < num_cmds - 1)
	{
		close(fd[i][0]);
		close(fd[i][1]);
		i++;
	}
	i = 0;
	while (i < num_cmds)
	{
		wait(&exit_status);
		i++;
	}
	free_pipe(fd, num_cmds);
	return (sa->ex_status = WEXITSTATUS(exit_status));
}

void	ex_pipe(t_list *cmd, t_general *sa, int num_cmds)
{
	t_list	*tmp;
	int		**fd;

	fd = NULL;
	tmp = cmd;
	if (!init_pipe(num_cmds, &fd))
		return ;
	g_sig = 1;
	while (tmp != NULL)
	{
		if (sa->index < num_cmds - 1 && pipe(fd[sa->index]) == -1)
			return (ft_putendl_fd("pipe !\n", 2));
		sa->pid = fork();
		if (sa->pid == -1)
			return (ft_putendl_fd("fork !\n", 2));
		if (sa->pid == 0)
			child_job(fd, sa, tmp, sa->index);
		else
		{
			parent_job(fd, &sa->index, tmp);
			tmp = tmp->next;
		}
	}
	wait_and_close(fd, num_cmds, sa);
}
