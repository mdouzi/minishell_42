/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 02:29:42 by mdouzi            #+#    #+#             */
/*   Updated: 2023/10/06 07:28:52 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

int	init_pipe(int num_cmds, int ***fd)
{
	int	i;

	*fd = malloc(sizeof(int *) * (num_cmds - 1));
	if (!(*fd))
		return (0);
	else
	{
		i = 0;
		while (i < (num_cmds - 1))
		{
			(*fd)[i] = malloc(sizeof(int) * 2);
			i++;
		}
	}
	return (1);
}

void	free_pipe(int **fd, int numb_cmds)
{
	int	i;

	i = 0;
	while (i < (numb_cmds - 1))
	{
		free(fd[i]);
		i++;
	}
	free(fd);
}

void	st_ex_pipe(t_general *sa)
{
	if (sa->ex_status == 1)
		sa->ex_status = 127;
}
