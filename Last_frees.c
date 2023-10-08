/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Errors_free_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/09/24 23:31:44 by mzoheir           #+#    #+#             */
/*   Updated: 2023/09/25 00:10:53 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	free_redir(t_list *cmds)
{
	int			i;
	t_list		*tmp;

	tmp = cmds;
	while (tmp)
	{
		i = -1;
		while (++i < tmp->red_nb)
		{
			if (tmp->redir)
			{
				if (tmp->redir[i].type == HEREDOC)
					free(tmp->redir[i].delimiter);
				else if (tmp->redir[i].type == RED_IN
					|| tmp->redir[i].type == RED_OUT
					|| tmp->redir[i].type == APPEND)
					free(tmp->redir[i].file);
			}
		}
		if (tmp->redir)
			free(tmp->redir);
		tmp = tmp->next;
	}
}

void	free_struct(t_define *define)
{
	int	i;

	if (define)
	{
		i = -1;
		while (++i < define->size_struct)
		{
			if (define[i].content)
				free(define[i].content);
			else
			{
				define[i].content = ft_strdup("");
				free(define[i].content);
			}
		}
		free(define);
	}
}

void	free_final_cmd(t_list *cmds)
{
	int				i;
	t_list			*tmp;

	tmp = cmds;
	while (tmp)
	{
		if (tmp->final_cmd)
		{
			i = 0;
			while (tmp->final_cmd[i])
			{
				free(tmp->final_cmd[i]);
				i++;
			}
			free(tmp->final_cmd);
		}
		tmp = tmp->next;
	}
}

void	free_cmd(t_list *cmds)
{
	int				i;
	t_list			*tmp;

	tmp = cmds;
	while (tmp)
	{
		if (tmp->cmd)
		{
			i = 0;
			while (tmp->cmd[i])
			{
				free(tmp->cmd[i]);
				i++;
			}
			free(tmp->cmd);
		}
		tmp = tmp->next;
	}
}

void	free_all(t_list *cmds)
{
	t_list	*tmp;

	free_final_cmd(cmds);
	free_cmd(cmds);
	free_redir(cmds);
	tmp = cmds;
	while (tmp)
	{
		free_struct(tmp->define);
		cmds = tmp->next;
		free(tmp);
		tmp = cmds;
	}
	if (cmds)
		free(cmds);
}
