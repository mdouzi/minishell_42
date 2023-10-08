/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 04:04:13 by mdouzi            #+#    #+#             */
/*   Updated: 2023/09/21 06:24:33 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

int	delete_var(char **env, char *var)
{
	int	index;
	int	j;

	index = -1;
	index = get_env_var(env, var);
	if (index == -1)
		return (1);
	if (index != -1)
	{
		free(env[index]);
		j = index;
		while (env[j])
		{
			env[j] = env[j + 1];
			j++;
		}
	}
	return (0);
}

int	ft_unset(t_general *sa, char **cmd)
{
	int	i;
	int	res;

	i = 1;
	res = 0;
	while (cmd[i])
	{
		if (var_export_check(cmd[i]) == 1 || ft_strchr(cmd[i], '=') != NULL)
		{
			ft_putstr_fd("unset:  ", 2);
			ft_putstr_fd(cmd[i], 2);
			ft_putstr_fd(" : not a valid identifier\n", 2);
			res = 1;
		}
		else
		{
			res = delete_var(sa->env, cmd[i]);
			res = delete_var(sa->env_export, cmd[i]);
		}
		i++;
	}
	return (res);
}
