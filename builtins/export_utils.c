/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 03:21:32 by mdouzi            #+#    #+#             */
/*   Updated: 2023/10/07 03:39:46 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

// Function to split the input string for the export command
char	**export_split_var(char *arg)
{
	char	**tmp;
	char	*equal_ptr;

	equal_ptr = ft_strchr(arg, '=');
	if (equal_ptr == NULL)
	{
		tmp = (char **)malloc(sizeof(char *) * 2);
		tmp[0] = ft_substr(arg, 0, ft_strlen(arg));
		tmp[1] = NULL;
	}
	else
	{
		tmp = malloc(sizeof(char *) * (2 + 1));
		tmp[0] = ft_substr(arg, 0, equal_ptr - arg);
		tmp[1] = ft_substr(equal_ptr, 1, ft_strlen(equal_ptr));
		tmp[2] = NULL;
	}
	return (tmp);
}

void	get_export_env(t_general *sa)
{
	int	i;

	i = 0;
	sa->env_export = (char **)malloc(sizeof(char *) * (ft_size(sa->env) + 1));
	while (i < ft_size(sa->env))
	{
		sa->env_export[i] = ft_strdup(sa->env[i]);
		i++;
	}
	sa->env_export[i] = NULL;
}

void	double_swap(int i, int j, t_general *sa)
{
	char	*tmp;

	tmp = ft_strdup(sa->env_export[i]);
	free(sa->env_export[i]);
	sa->env_export[i] = ft_strdup(sa->env_export[j]);
	free(sa->env_export[j]);
	sa->env_export[j] = ft_strdup(tmp);
	free(tmp);
}

// print all the export when i get export cmd with no args
void	solo_export(t_general *sa)
{
	int	i;
	int	j;

	i = 0;
	while (sa->env_export[i])
	{
		j = i + 1;
		while (sa->env_export[j])
		{
			if (ft_strcmp(sa->env_export[i], sa->env_export[j]) > 0)
				double_swap(i, j, sa);
			j++;
		}
		i++;
	}
	i = 0;
	while (sa->env_export[i])
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(sa->env_export[i++], 1);
		ft_putstr_fd("\n", 1);
	}
}

void	check_in_var(char *var, char **new_var, t_general *sa, int index)
{
	char	*vr_env;
	int		index_env;

	index_env = get_env_var(sa->env, new_var[0]);
	vr_env = expand_quotes(ft_strdup(var));
	free(sa->env_export[index]);
	sa->env_export[index] = ft_strdup(var);
	index_env = get_env_var(sa->env, new_var[0]);
	if (index_env != -1)
	{
		free(sa->env[index_env]);
		sa->env[index_env] = ft_strdup(vr_env);
	}
	else if (index_env == -1 && ft_strchr(var, '='))
	{
		sa->env = export_update(sa->env, vr_env);
	}
	free(vr_env);
}
