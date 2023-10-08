/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_redir_util_bis.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 01:19:03 by mzoheir           #+#    #+#             */
/*   Updated: 2023/10/04 23:25:26 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

int	iswhitespace(char c)
{
	return (c == ' ' || c == '\t');
}

void	update_struct_util(t_list *tmp, t_define *final_struct, int *index,
		int i)
{
	final_struct[*index].content = ft_strdup(tmp->define[i].content);
	final_struct[*index].type = tmp->define[i].type;
	final_struct[*index].state = tmp->define[i].state;
	final_struct[*index].index = *index;
	final_struct[*index].size_struct = new_struct_size(tmp);
	(*index)++;
}
