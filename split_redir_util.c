/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_redir_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 21:47:45 by mzoheir           #+#    #+#             */
/*   Updated: 2023/10/06 00:49:55 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	split_red_in(char *newstr, t_index *index)
{
	newstr[index->index++] = '\n';
	newstr[index->index++] = '>';
	newstr[index->index++] = '\n';
}

void	split_append(char *newstr, t_index *index)
{
	newstr[index->index++] = '\n';
	newstr[index->index++] = '>';
	newstr[index->index++] = '>';
	newstr[index->index++] = '\n';
	index->i++;
}

void	split_red_out(char *newstr, t_index *index)
{
	newstr[index->index++] = '\n';
	newstr[index->index++] = '<';
	newstr[index->index++] = '\n';
}

void	split_heredoc(char *newstr, t_index *index)
{
	newstr[index->index++] = '\n';
	newstr[index->index++] = '<';
	newstr[index->index++] = '<';
	newstr[index->index++] = '\n';
	index->i++;
}

void	split_redirections(char *newstr, t_index *index, char *str)
{
	if (str[index->i] == '\'' || str[index->i] == '\"')
		index->inquotes = !index->inquotes;
	if (!index->inquotes && str[index->i] == '>' && str[index->i + 1] != '>')
		split_red_in(newstr, index);
	else if (!index->inquotes && str[index->i] == '<' && str[index->i
			+ 1] != '<')
		split_red_out(newstr, index);
	else if (!index->inquotes && str[index->i] == '>' && str[index->i
			+ 1] == '>')
		split_append(newstr, index);
	else if (!index->inquotes && str[index->i] == '<' && str[index->i
			+ 1] == '<')
		split_heredoc(newstr, index);
	else if (!index->inquotes && iswhitespace(str[index->i]))
		newstr[index->index++] = '\n';
	else
		newstr[index->index++] = str[index->i];
}
