/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_define_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:20:41 by mzoheir           #+#    #+#             */
/*   Updated: 2023/10/03 02:33:45 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	define_hrdc(t_list *tmp, int *i)
{
	tmp->define[*i].state = HEREDOC;
	tmp->define[*i].content = ft_strdup(tmp->cmd[*i]);
	tmp->define[*i].type = tmp->define[*i].state;
	tmp->define[*i].index = *i;
	tmp->define[*i + 1].state = DELIMITER;
	tmp->define[*i + 1].content = ft_strdup(tmp->cmd[*i + 1]);
	tmp->define[*i + 1].type = tmp->define[*i + 1].state;
	tmp->define[*i + 1].index = *i + 1;
	(*i)++;
}

void	define_append(t_list *tmp, int *i)
{
	tmp->define[*i].state = APPEND;
	tmp->define[*i].content = ft_strdup(tmp->cmd[*i]);
	tmp->define[*i].type = tmp->define[*i].state;
	tmp->define[*i].index = *i;
	tmp->define[*i + 1].state = FYLE;
	tmp->define[*i + 1].content = ft_strdup(tmp->cmd[*i + 1]);
	tmp->define[*i + 1].type = tmp->define[*i + 1].state;
	tmp->define[*i + 1].index = *i + 1;
	(*i)++;
}

void	define_red_in(t_list *tmp, int *i)
{
	tmp->define[*i].state = RED_IN;
	tmp->define[*i].content = ft_strdup(tmp->cmd[*i]);
	tmp->define[*i].type = tmp->define[*i].state;
	tmp->define[*i].index = *i;
	tmp->define[*i + 1].state = FYLE;
	tmp->define[*i + 1].content = ft_strdup(tmp->cmd[*i + 1]);
	tmp->define[*i + 1].type = tmp->define[*i + 1].state;
	tmp->define[*i + 1].index = *i + 1;
	(*i)++;
}

void	define_red_out(t_list *tmp, int *i)
{
	tmp->define[*i].state = RED_OUT;
	tmp->define[*i].content = ft_strdup(tmp->cmd[*i]);
	tmp->define[*i].type = tmp->define[*i].state;
	tmp->define[*i].index = *i;
	tmp->define[*i + 1].state = FYLE;
	tmp->define[*i + 1].content = ft_strdup(tmp->cmd[*i + 1]);
	tmp->define[*i + 1].type = tmp->define[*i + 1].state;
	tmp->define[*i + 1].index = *i + 1;
	(*i)++;
}
