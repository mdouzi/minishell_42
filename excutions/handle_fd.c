/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 19:58:38 by mdouzi            #+#    #+#             */
/*   Updated: 2023/10/06 06:26:06 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

int	handle_redin(t_list *cmd, t_redir red)
{
	int	fd;

	if (access(red.file, F_OK) != 0)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd("no such file or directory: ", 2);
		ft_putstr_fd(red.file, 2);
		ft_putstr_fd("\n", 2);
		return (-3);
	}
	if (access(red.file, R_OK) != 0)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd("Permission denied: ", 2);
		ft_putstr_fd(red.file, 2);
		ft_putstr_fd("\n", 2);
		return (-2);
	}
	if (cmd->fd_in > 2)
		close(cmd->fd_in);
	fd = open(red.file, O_RDONLY);
	return (fd);
}

int	handle_redout(t_list *cmd, t_redir red)
{
	int	fd;

	fd = open(red.file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (access(red.file, W_OK) != 0)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd("Permission denied: ", 2);
		ft_putstr_fd(red.file, 2);
		ft_putstr_fd("\n", 2);
		close(fd);
		return (-2);
	}
	if (cmd->fd_out > 2)
		close(cmd->fd_out);
	return (fd);
}

int	handle_append(t_list *cmd, t_redir red)
{
	int	fd;

	fd = open(red.file, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (access(red.file, W_OK) != 0)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd("Permission denied: ", 2);
		ft_putstr_fd(red.file, 2);
		ft_putstr_fd("\n", 2);
		close(fd);
		return (-3);
	}
	if (cmd->fd_out > 2)
		close(cmd->fd_out);
	return (fd);
}
