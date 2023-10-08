/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_array_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 22:11:10 by mzoheir           #+#    #+#             */
/*   Updated: 2023/09/30 00:49:01 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	redir_heredoc(t_list *tmp, int *i, int *j)
{
	tmp->redir[*j].type = HEREDOC;
	tmp->redir[*j].delimiter = ft_strdup(tmp->define[*i + 1].content);
	(*j)++;
}

void	redir_append(t_list *tmp, int *i, int *j)
{
	tmp->redir[*j].type = APPEND;
	tmp->redir[*j].file = ft_strdup(tmp->define[*i + 1].content);
	(*j)++;
}

void	redir_red_out(t_list *tmp, int *i, int *j)
{
	tmp->redir[*j].type = RED_OUT;
	tmp->redir[*j].file = ft_strdup(tmp->define[*i + 1].content);
	(*j)++;
}

void	redir_red_in(t_list *tmp, int *i, int *j)
{
	tmp->redir[*j].type = RED_IN;
	tmp->redir[*j].file = ft_strdup(tmp->define[*i + 1].content);
	(*j)++;
}

void	redir_arrayx(t_list *tmp, int *i, int *j)
{
	if (ft_strncmp("<<", tmp->define[*i].content, 2) == 0)
		redir_heredoc(tmp, i, j);
	else if (ft_strncmp(">>", tmp->define[*i].content, 2) == 0)
		redir_append(tmp, i, j);
	else if (ft_strncmp(">", tmp->define[*i].content, 1) == 0)
		redir_red_out(tmp, i, j);
	else if (ft_strncmp("<", tmp->define[*i].content, 1) == 0)
		redir_red_in(tmp, i, j);
}
