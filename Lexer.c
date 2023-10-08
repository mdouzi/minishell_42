/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 20:29:26 by mzoheir           #+#    #+#             */
/*   Updated: 2023/10/04 07:31:23 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

int	checkquotes(char *line)
{
	int	singlequotes;
	int	doublequotes;
	int	i;

	singlequotes = 0;
	doublequotes = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\'' && doublequotes % 2 == 0)
			singlequotes++;
		else if (line[i] == '"' && singlequotes % 2 == 0)
			doublequotes++;
		i++;
	}
	return (singlequotes % 2 == 0 && doublequotes % 2 == 0);
}

int	new_size(char *str)
{
	int	i;
	int	inquotes;
	int	count;

	i = 0;
	inquotes = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
			inquotes = !inquotes;
		if (str[i] == '|' && !inquotes)
			count += 2;
		i++;
	}
	return (count);
}

char	*addnext_pipe(char *str)
{
	char	*new_str;
	t_index	index;

	initialize_index(&index);
	index.len = ft_strlen(str) + new_size(str);
	new_str = (char *)malloc((index.len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	while (str[index.i])
	{
		if ((str[index.i] == '"' || str[index.i] == '\'') && str[index.i])
		{
			index.inquotes = !(index.inquotes);
			new_str[index.index] = str[index.i];
			index.index++;
		}
		else if (str[index.i] == '|' && !index.inquotes && str[index.i])
			addnext_pipe_bis(&index, new_str);
		else
			new_str[index.index++] = str[index.i];
		index.i++;
	}
	new_str[index.len] = '\0';
	return (new_str);
}

char	**remove_pipe_pointers(char **str)
{
	t_lexer	index;

	initialize_lex(&index);
	while (str[index.i])
	{
		if (str[index.i][0] != '|')
			index.count++;
		index.i++;
	}
	index.result = (char **)malloc((index.count + 1) * sizeof(char *));
	if (!index.result)
		return (NULL);
	index.i = 0;
	while (str[index.i])
	{
		if (str[index.i][0] != '|')
		{
			index.result[index.j] = ft_strdup(str[index.i]);
			index.j++;
		}
		index.i++;
	}
	index.result[index.j] = NULL;
	free_double_array(str);
	return (index.result);
}

int	checkquote_index(char *str, int index)
{
	t_index	index_q;

	initialize_index(&index_q);
	while (str[index_q.i] != '\0')
	{
		if (str[index_q.i] == '\'' && (index_q.i == 0 || str[index_q.i
					- 1] != '\\') && index_q.indoublequotes % 2 == 0)
		{
			index_q.insinglequotes++;
			if (index_q.insinglequotes % 2 == 1 && index_q.i <= index)
				return (1);
		}
		else if (str[index_q.i] == '"' && (index_q.i == 0 || str[index_q.i
					- 1] != '\\') && index_q.insinglequotes % 2 == 0)
		{
			index_q.indoublequotes++;
			if (index_q.indoublequotes % 2 == 1 && index_q.i <= index)
				return (0);
		}
		index_q.i++;
	}
	return (0);
}
