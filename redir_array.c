/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 22:06:09 by mzoheir           #+#    #+#             */
/*   Updated: 2023/10/04 04:41:41 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

int	redir_array_bis(t_list *tmp)
{
	int	i;
	int	nb_red;

	i = -1;
	nb_red = 0;
	while (++i < tmp->size_cmd)
	{
		if (tmp->define[i].content[0] != '\0')
		{
			if (tmp->define[i].type == HEREDOC || tmp->define[i].type == RED_IN
				|| tmp->define[i].type == RED_OUT
				|| tmp->define[i].type == APPEND)
				nb_red++;
		}
	}
	return (nb_red);
}

void	initialize_redir(t_list *tmp)
{
	tmp->redir->delimiter = NULL;
	tmp->redir->file = NULL;
	tmp->redir->type = 0;
}

void	redir_array(t_list *commands)
{
	int		i;
	int		j;
	int		nb_red;
	t_list	*tmp;

	tmp = commands;
	while (tmp)
	{
		nb_red = redir_array_bis(tmp);
		if (nb_red > 0)
		{
			tmp->red_nb = nb_red;
			tmp->redir = malloc(sizeof(t_redir) * nb_red);
			if (!tmp->redir)
				return ;
			initialize_redir(tmp);
			i = -1;
			j = 0;
			while (++i < tmp->define->size_struct && j < nb_red)
				redir_arrayx(tmp, &i, &j);
		}
		tmp = tmp->next;
	}
}
