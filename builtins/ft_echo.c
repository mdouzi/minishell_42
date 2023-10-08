/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 03:59:54 by mdouzi            #+#    #+#             */
/*   Updated: 2023/09/25 03:24:13 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

int	check_n_line(char *line)
{
	int	i;

	i = 0;
	if (line && line[i])
	{
		if (line[i] == '-' && line[i + 1] == 'n')
		{
			i++;
			while (line[i] != '\0')
			{
				if (line[i] != 'n' && line[i] != '\0')
					return (1);
				i++;
			}
			return (0);
		}
	}
	return (1);
}

int	ft_echo(char **cmd)
{
	int	j;
	int	i;

	j = 1;
	i = 0;
	while (cmd[j])
	{
		if (!check_n_line(cmd[j]))
			i++;
		else
		{
			ft_putstr_fd(cmd[j], 1);
			if (cmd[j + 1] != NULL)
				ft_putstr_fd(" ", 1);
		}
		j++;
	}
	if (!i)
		printf("\n");
	return (0);
}
