/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 15:44:58 by mzoheir           #+#    #+#             */
/*   Updated: 2023/10/04 05:27:15 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	initialize_define(t_define *define, int size)
{
	int	j;

	j = 0;
	while (j < size)
	{
		define[j].type = 0;
		define[j].state = 0;
		define[j].index = 0;
		define[j].content = 0;
		define[j].dollar = 0;
		define[j].size_struct = size;
		j++;
	}
}

void	initialize_define_inserted(t_define *define, int inserted)
{
	int	j;

	j = 0;
	while (j < inserted)
	{
		define[j].state = 0;
		define[j].type = 0;
		define[j].dollar = 0;
		define[j].content = 0;
		define[j].index = 0;
		define[j].size_struct = 0;
		define[j].size_struct_inserted = inserted;
		j++;
	}
}

void	initialize_counter(t_count *counter)
{
	counter->word_count = 0;
	counter->insinglequotes = 0;
	counter->indoublequotes = 0;
	counter->wordstart = 0;
}

void	initialize_index(t_index *index)
{
	index->i = 0;
	index->j = 0;
	index->insinglequotes = 0;
	index->indoublequotes = 0;
	index->len = 0;
	index->index = 0;
	index->inquotes = 0;
}

void	initialize_env(t_index_env *index)
{
	index->i = 0;
	index->j = 0;
	index->ex_status = 0;
	index->check_env = 0;
	index->extract = 0;
	index->result = NULL;
}
