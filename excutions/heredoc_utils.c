/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 02:24:00 by mdouzi            #+#    #+#             */
/*   Updated: 2023/10/01 05:41:54 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

int	hrdc_expand(char *delimiter)
{
	if (ft_strchr(delimiter, '\'') || ft_strchr(delimiter, '"'))
		return (0);
	return (1);
}

void	write_exp(t_general *sa, char *line, int pipefd[2])
{
	char	*tmp;

	tmp = ft_strdup(sa->del);
	tmp = expand_env(line, sa->env, sa);
	write(pipefd[1], tmp, ft_strlen(tmp));
	free(tmp);
}

void	error_fork(void)
{
	ft_putstr_fd("fork her\n", 2);
	exit(EXIT_FAILURE);
}
