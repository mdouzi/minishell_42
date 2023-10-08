/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_struct_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 06:34:15 by mzoheir           #+#    #+#             */
/*   Updated: 2023/10/07 02:37:14 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	count_word_bis(char *str, t_count *count_words, int *i)
{
	if (str[*i] == '\'')
	{
		if (!count_words->indoublequotes)
			count_words->insinglequotes = !count_words->insinglequotes;
		else
			count_words->wordstart = 1;
	}
	else if (str[*i] == '"')
	{
		if (!count_words->insinglequotes)
			count_words->indoublequotes = !count_words->indoublequotes;
		else
			count_words->wordstart = 1;
	}
	else if ((str[*i] == ' ' || str[*i] == '\t') && !count_words->insinglequotes
		&& !count_words->indoublequotes)
	{
		if (count_words->wordstart == 1)
		{
			count_words->word_count++;
			count_words->wordstart = 0;
		}
	}
	else
		count_words->wordstart = 1;
}

int	countwords(char *str)
{
	int		i;
	t_count	count;

	i = 0;
	initialize_counter(&count);
	if (!str)
		return (0);
	while (str[i])
	{
		count_word_bis(str, &count, &i);
		i++;
	}
	if (count.wordstart == 1 && !count.insinglequotes && !count.indoublequotes)
		count.word_count++;
	return (count.word_count);
}

void	bis_update_struct(t_list *tmp, t_define *final_struct)
{
	int	i;
	int	index;

	i = -1;
	index = 0;
	while (++i < tmp->define->size_struct)
	{
		if (tmp->define[i].content)
		{
			if (countwords(tmp->define[i].content) > 1
				&& tmp->define[i].type != FYLE)
				fill_new_split(tmp->define[i].content, final_struct, &index);
			else if (countwords(tmp->define[i].content) == 1)
				update_struct_util(tmp, final_struct, &index, i);
			else if (countwords(tmp->define[i].content) > 1
				&& tmp->define[i].type == FYLE)
				fill_new_split_file(tmp->define[i].content,
					final_struct, &index);
		}
	}
}

void	update_struct(t_list *cmds)
{
	int			k;
	t_list		*tmp;
	t_define	*final_struct;

	tmp = cmds;
	while (tmp)
	{
		k = new_struct_size(tmp);
		if (k > 0)
		{
			final_struct = (t_define *)malloc(sizeof(t_define) * k);
			initialize_define(final_struct, k);
			bis_update_struct(tmp, final_struct);
			free_struct(tmp->define);
			tmp->define = final_struct;
		}
		tmp->size_cmd = k;
		tmp = tmp->next;
	}
}
