/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:48:17 by mzoheir           #+#    #+#             */
/*   Updated: 2023/10/07 02:17:51 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	final_cmd_bis(t_list *tmp, int i, int *j)
{
	if (tmp->define[i].content && tmp->define[i].state == WORD)
	{
		tmp->final_cmd[*j] = ft_strdup(tmp->define[i].content);
		(*j)++;
	}
}

void	final_cmd(t_list *cmds)
{
	int		i;
	int		j;
	t_list	*tmp;

	tmp = cmds;
	while (tmp)
	{
		tmp->size_cmd = new_struct_size(tmp);
		if (tmp->size_cmd - (tmp->red_nb * 2) > 0 && tmp->define)
		{
			tmp->final_cmd = (char **)malloc(sizeof(char *) * (tmp->size_cmd
						- (tmp->red_nb * 2) + 1));
			if (!tmp->final_cmd)
				return ;
			i = -1;
			j = 0;
			while (++i < tmp->size_cmd)
				final_cmd_bis(tmp, i, &j);
			if (tmp->final_cmd)
				tmp->final_cmd[j] = NULL;
		}
		else if (tmp->size_cmd - (tmp->red_nb * 2) == 0)
			tmp->final_cmd = NULL;
		tmp = tmp->next;
	}
}
