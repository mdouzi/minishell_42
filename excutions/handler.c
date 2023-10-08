/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 05:48:21 by mdouzi            #+#    #+#             */
/*   Updated: 2023/10/07 03:05:01 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

int	handle_builtins(t_list *cmds, t_general *sa)
{
	if (cmds)
	{
		if (ft_strcmp(cmds->final_cmd[0], "cd") == 0)
			sa->ex_status = ft_cd(sa, cmds->final_cmd);
		else if (ft_strcmp(cmds->final_cmd[0], "echo") == 0)
			sa->ex_status = ft_echo(cmds->final_cmd);
		else if (ft_strcmp(cmds->final_cmd[0], "env") == 0)
			sa->ex_status = ft_env(sa);
		else if (ft_strcmp(cmds->final_cmd[0], "export") == 0)
			sa->ex_status = ft_export(sa, cmds->final_cmd);
		else if (ft_strcmp(cmds->final_cmd[0], "pwd") == 0)
			sa->ex_status = ft_pwd();
		else if (ft_strcmp(cmds->final_cmd[0], "unset") == 0)
			sa->ex_status = ft_unset(sa, cmds->final_cmd);
		else if (ft_strcmp(cmds->final_cmd[0], "exit") == 0)
			sa->ex_status = ft_exit(cmds->final_cmd, sa);
	}
	return (0);
}

void	reset_fds(int in, int out)
{
	dup2(in, STDIN_FILENO);
	close(in);
	dup2(out, STDOUT_FILENO);
	close(out);
}

int	red_built(t_list *cmds)
{
	if (cmds->fd_in != 0)
	{
		if (cmds->fd_in < 0)
		{
			close_fds(cmds);
			return (-1);
		}
		else
			dup2(cmds->fd_in, STDIN_FILENO);
	}
	if (cmds->fd_out != 1)
	{
		if (cmds->fd_out < 1)
		{
			close_fds(cmds);
			return (-1);
		}
		else
			dup2(cmds->fd_out, STDOUT_FILENO);
	}
	return (1);
}

int	ex_builtins(t_list *cmd, t_general *sa)
{
	int	in;
	int	out;

	in = dup(0);
	out = dup(1);
	if (red_built(cmd) == 1)
		handle_builtins(cmd, sa);
	close(cmd->fd_in);
	close(cmd->fd_out);
	reset_fds(in, out);
	return (0);
}

void	ex_test(t_list *cmd, t_general *sa)
{
	t_list	*head;

	if (g_sig == -2)
	{
		sa->ex_status = 130;
		return ;
	}
	head = cmd;
	sa->num_cmds = numberof_cmd(cmd);
	if (sa->num_cmds == 0)
		return (close_fds(cmd));
	if (cmd && !cmd->next && is_builtin(cmd->final_cmd) == 1 && cmd->final_cmd)
		ex_builtins(cmd, sa);
	else
	{
		ex_pipe(cmd, sa, sa->num_cmds);
		st_ex_pipe(sa);
	}
	while (head)
	{
		close_fds(head);
		if (head->next == NULL)
			break ;
		head = head->next;
	}
}
