/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_define.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:04:27 by mzoheir           #+#    #+#             */
/*   Updated: 2023/10/06 00:54:50 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	define_delim(t_list *tmp, int i)
{
	tmp->define[i].content = ft_strdup(tmp->cmd[i]);
	tmp->define[i].state = DELIMITER;
	tmp->define[i].type = tmp->define[i].state;
	tmp->define[i].index = i;
}

void	define_word(t_list *tmp, int i)
{
	tmp->define[i].content = ft_strdup(tmp->cmd[i]);
	tmp->define[i].state = WORD;
	tmp->define[i].type = tmp->define[i].state;
	tmp->define[i].index = i;
}

void	define_all(t_list *tmp, int i)
{
	if (ft_strcmp("<<", tmp->cmd[i]) == 0)
		define_hrdc(tmp, &i);
	else if (ft_strcmp(">>", tmp->cmd[i]) == 0)
		define_append(tmp, &i);
	else if (ft_strncmp("<", tmp->cmd[i], 1) == 0)
		define_red_in(tmp, &i);
	else if (ft_strncmp(">", tmp->cmd[i], 1) == 0)
		define_red_out(tmp, &i);
	else if (tmp->define[i].state == 0 && tmp->define[i].type == 0)
		define_word(tmp, i);
}

void	cmd_define(t_list *cmds)
{
	int		i;
	t_list	*tmp;

	tmp = cmds;
	while (tmp)
	{
		tmp->define = malloc(sizeof(t_define) * (tmp->size_cmd));
		if (!(tmp->define))
			return ;
		initialize_define(tmp->define, tmp->size_cmd);
		i = 0;
		while (tmp->cmd[i])
		{
			define_all(tmp, i);
			if (ft_strchr(tmp->cmd[i], '$')
				&& tmp->define[i].state != DELIMITER)
				tmp->define[i].dollar = 1;
			i++;
		}
		tmp = tmp->next;
	}
}
