/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:42:46 by mzoheir           #+#    #+#             */
/*   Updated: 2023/10/04 05:08:05 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

t_list	*create_node(char *cmd, int i)
{
	t_list	*newnode;
	int		j;

	newnode = (t_list *)malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	newnode->index = i;
	newnode->red_nb = 0;
	newnode->fd_in = 0;
	newnode->fd_out = 0;
	newnode->redir = 0;
	newnode->final_cmd = 0;
	newnode->cmd = split_cmd(cmd);
	j = 0;
	if (newnode->cmd)
	{
		while (newnode->cmd[j])
			j++;
	}
	newnode->size_cmd = j;
	newnode->next = NULL;
	newnode->prev = NULL;
	return (newnode);
}

void	add_node_front(t_list *head, char *str, int i)
{
	t_list	*current;

	current = head;
	while (current->next != NULL)
		current = current->next;
	current->next = create_node(str, i);
}

void	add_prev_list(t_list *cmds)
{
	t_list	*tmp;
	t_list	*prev;

	tmp = cmds;
	prev = NULL;
	while (tmp)
	{
		tmp->prev = prev;
		prev = tmp;
		tmp = tmp->next;
	}
}
