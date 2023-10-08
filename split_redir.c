/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/09/15 15:48:02 by mzoheir           #+#    #+#             */
/*   Updated: 2023/09/15 15:48:02 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

int	count_redir(char *str, t_index *index)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			index->inquotes = !index->inquotes;
		if (i > 1 && !index->inquotes && (str[i] == '>' || str[i] == '<')
			&& str[i + 1] != '>' && str[i - 1] && str[i - 1] != '<'
			&& str[i - 1] != '>')
			count += 2;
		else if (!index->inquotes && str[i] == '<' && str[i + 1] == '<')
			count += 2;
		else if (!index->inquotes && str[i] == '>' && str[i + 1] == '>')
			count += 2;
		else if (!index->inquotes && i == 0 && (str[i] == '<'
				|| str[i] == '>') && str[i + 1]
			&& str[i + 1] != '<' && str[i + 1] != '>')
			count += 2;
		i++;
	}
	return (count);
}

char	**split_cmd(char *str)
{
	t_index	index;
	char	*newstr;
	int		i;
	char	**splitted;

	initialize_index(&index);
	index.len = ft_strlen(str) + count_redir(str, &index);
	newstr = (char *)malloc((index.len + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	index.i = -1;
	index.inquotes = 0;
	while (++(index.i) < ft_strlen(str))
		split_redirections(newstr, &index, str);
	newstr[index.len] = '\0';
	i = 0;
	splitted = ft_split(newstr, '\n');
	return (splitted);
}

void	final_remove_quotes(t_list *cmds)
{
	int		i;
	t_list	*tmp;

	tmp = cmds;
	while (tmp)
	{
		i = -1;
		while (++i < tmp->define->size_struct)
		{
			if (tmp->define)
			{
				if (tmp->define[i].content && tmp->define[i].type != DELIMITER
					&& tmp->define[i].content != NULL)
					tmp->define[i].content
						= expand_quotes(tmp->define[i].content);
			}
		}
		tmp = tmp->next;
	}
}

void	expand_quotes_util(t_index *index, char *str, char *result)
{
	if (str[index->i] == '\'' && (index->i == 0 || str[index->i - 1] != '\\')
		&& index->indoublequotes % 2 == 0)
		index->insinglequotes = (index->insinglequotes + 1) % 2;
	else if (str[index->i] == '"' && (index->i == 0 || str[index->i
				- 1] != '\\') && index->insinglequotes % 2 == 0)
		index->indoublequotes = (index->indoublequotes + 1) % 2;
	else
	{
		if (!(str[index->i] == '\'' && index->insinglequotes)
			&& !(str[index->i] == '"' && index->indoublequotes))
		{
			result[index->j] = str[index->i];
			index->j++;
		}
	}
}

char	*expand_quotes(char *str)
{
	t_index	index;
	char	*result;

	initialize_index(&index);
	index.len = ft_strlen(str);
	result = (char *)malloc(index.len + 1);
	if (!result)
		return (NULL);
	while (str[index.i])
	{
		expand_quotes_util(&index, str, result);
		index.i++;
	}
	result[index.j] = '\0';
	free(str);
	return (result);
}
