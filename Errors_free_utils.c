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

int	error_line_in(t_index_check *index)
{
	if (index->copy[index->i] == '<' && !index->inquotes)
	{
		if (index->copy[index->i + 1] && index->copy[index->i + 1] == '<'
			&& !index->inquotes)
		{
			if (index->copy[index->i + 2] && index->copy[index->i + 2] == '>'
				&& !index->inquotes)
			{
				printf("syntax error near unexpected token `>'\n");
				return (0);
			}
			else if (index->copy[index->i + 2] == '<' && !index->inquotes)
			{
				printf("syntax error near unexpected token `newline'\n");
				return (0);
			}
			else if (index->copy[index->i + 2] == '|' && !index->inquotes)
			{
				printf("syntax error near unexpected token `|'\n");
				return (0);
			}
		}
	}
	return (1);
}

int	error_line_out(t_index_check *index)
{
	if (index->copy[index->i] == '>' && !index->inquotes)
	{
		if (index->copy[index->i + 1] && index->copy[index->i + 1] == '>'
			&& !index->inquotes)
		{
			index->j = index->i + 2;
			while ((index->copy[index->j] == ' '
					|| index->copy[index->j] == '\t') && index->copy[index->j]
				&& !index->inquotes)
				index->j++;
			if (index->copy[index->j] && index->copy[index->j] == '>'
				&& !index->inquotes)
			{
				printf("syntax error near unexpected token `>'\n");
				return (0);
			}
			else if (index->copy[index->j] && index->copy[index->j] == '<'
				&& !index->inquotes)
			{
				printf("syntax error near unexpected token `<'\n");
				return (0);
			}
		}
	}
	return (1);
}

int	error_line_bis(t_index_check *index)
{
	if (index->copy[index->i] == '>' && !index->inquotes)
	{
		index->j = index->i + 1;
		while (index->copy[index->j] == ' ' || index->copy[index->j] == '\t')
			index->j++;
		if (index->copy[index->j] && index->copy[index->j] == '<' && (index->j
				- 1) > index->i)
		{
			printf("syntax error near unexpected token `<'\n");
			return (0);
		}
		if (index->copy[index->j] == '|' && (index->j - 1) > index->i)
		{
			printf("syntax error near unexpected token `|'\n");
			return (0);
		}
	}
	return (1);
}

int	error_bis(t_index_check *index)
{
	if (index->copy[index->i] == '<' && !index->inquotes)
	{
		index->j = index->i + 1;
		while (index->copy[index->j] == ' ' || index->copy[index->j] == '\t')
			index->j++;
		if (index->copy[index->j] && index->copy[index->j] == '>' && (index->j
				- 1) > index->i)
		{
			printf("syntax error near unexpected token `>'\n");
			return (0);
		}
		if (index->copy[index->j] == '|' && (index->j - 1) > index->i)
		{
			printf("syntax error near unexpected token `|'\n");
			return (0);
		}
	}
	return (1);
}

int	error_line_end(t_index_check *index)
{
	if (index->copy[index->len - 1] == '>' || index->copy[index->len
			- 1] == '<')
	{
		printf("syntax error near unexpected token `newline'\n");
		return (0);
	}
	else if (index->copy[index->len - 1] == '|')
	{
		printf("syntax error near unexpected token '|'\n");
		return (0);
	}
	return (1);
}
