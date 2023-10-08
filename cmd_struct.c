/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:54:36 by mzoheir           #+#    #+#             */
/*   Updated: 2023/10/07 02:34:21 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	final_struct(t_list *cmds, char **env, t_general *sa)
{
	t_list	*tmp;
	int		i;

	tmp = cmds;
	while (tmp)
	{
		i = -1;
		while (++i < tmp->size_cmd)
		{
			if (tmp->define[i].dollar == 1)
			{
				tmp->define[i].content = expand_env(tmp->define[i].content,
						env, sa);
			}
		}
		tmp = tmp->next;
	}
}

char	*filler_split(char *str)
{
	int		i;
	char	*res;
	int		j;

	res = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\"' || str[i] == '\'')
		{
			j = i;
			j = skip_quote(str, i);
			while (i++ < j)
				res[i] = str[i];
		}
		else if (str[i] == ' ' || str[i] == '\t')
			res[i] = '\n';
		else
			res[i] = str[i];
		i++;
	}
	res[ft_strlen(str)] = '\0';
	return (res);
}

void	fill_new_split_file(char *str, t_define *new_struct, int *index)
{
	int		i;
	char	**split_words;
	char	*copy;

	copy = filler_split(str);
	split_words = ft_split(copy, '\n');
	i = 0;
	while (split_words[i])
	{
		new_struct[*index].content = ft_strdup(split_words[i]);
		if (i == 0)
			new_struct[*index].state = FYLE;
		else
			new_struct[*index].state = WORD;
		new_struct[*index].index = *index;
		new_struct[*index].type = new_struct[i].state;
		(*index)++;
		i++;
	}
	free_tab(split_words);
}

void	fill_new_split(char *str, t_define *new_struct, int *index)
{
	int		i;
	char	**split_words;
	char	*copy;

	copy = filler_split(str);
	split_words = ft_split(copy, '\n');
	i = 0;
	while (split_words[i])
	{
		new_struct[*index].content = ft_strdup(split_words[i]);
		new_struct[*index].state = WORD;
		new_struct[*index].index = *index;
		new_struct[*index].type = new_struct[i].state;
		(*index)++;
		i++;
	}
	free_tab(split_words);
}

int	new_struct_size(t_list *tmp)
{
	int	i;
	int	k;

	i = -1;
	k = 0;
	while (++i < tmp->size_cmd)
		k += countwords(tmp->define[i].content);
	return (k);
}
