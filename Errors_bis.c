/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Errors_bis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/09/25 00:10:28 by mzoheir           #+#    #+#             */
/*   Updated: 2023/09/25 00:10:41 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

int	error_line_util(t_index_check *index)
{
	if (index->copy[index->i] == '>' && index->copy[index->i + 1] == '<'
		&& !index->inquotes)
	{
		printf("syntax error near unexpected token `<'\n");
		return (0);
	}
	else if (index->copy[index->i] == '<' && index->copy[index->i + 1] == '>'
		&& !index->inquotes)
	{
		printf("syntax error near unexpected token `newline'\n");
		return (0);
	}
	if (index->copy[index->i] == '|' && !index->inquotes)
	{
		if ((index->copy[index->i + 1] == '|' || index->copy[index->i
					- 1] == '|') && !index->inquotes)
		{
			printf("syntax error near unexpected token '|'\n");
			return (0);
		}
	}
	return (1);
}

int	error_line_util_pipe(t_index_check *index)
{
	if (index->copy[index->i] == '>' && index->copy[index->i + 1] == '|'
		&& !index->inquotes)
	{
		printf("syntax error near unexpected token `|'\n");
		return (0);
	}
	else if (index->copy[index->i] == '<' && index->copy[index->i + 1] == '|'
		&& !index->inquotes)
	{
		printf("syntax error near unexpected token `|'\n");
		return (0);
	}
	return (1);
}

int	error_line_util_red(t_index_check *index)
{
	if (index->copy[index->i] == '>' && !index->copy[index->i + 1]
		&& !index->inquotes)
	{
		printf("syntax error near unexpected token `>'\n");
		return (0);
	}
	else if (index->copy[index->i] == '<' && !index->copy[index->i + 1]
		&& !index->inquotes)
	{
		printf("syntax error near unexpected token `<'\n");
		return (0);
	}
	return (1);
}
