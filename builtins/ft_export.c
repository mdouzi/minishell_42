/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 03:18:58 by mdouzi            #+#    #+#             */
/*   Updated: 2023/10/07 03:36:41 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

char	**export_update(char **env, char *var)
{
	int		i;
	char	**new_export;
	int		j;

	i = 0;
	j = 0;
	new_export = NULL;
	while (env[i] != NULL)
		i++;
	new_export = (char **)malloc(sizeof(char *) * (i + 2));
	while (j < i)
	{
		new_export[j] = ft_strdup(env[j]);
		j++;
		if (env[j] == NULL)
			free_tab(env);
	}
	new_export[i] = ft_strdup(var);
	new_export[i + 1] = NULL;
	return (new_export);
}

char	*with_value(char **new_var)
{
	char	*res;
	size_t	len_res;

	res = NULL;
	len_res = ft_strlen(new_var[0]) + ft_strlen(new_var[1]) + 4;
	res = (char *)malloc(len_res + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, new_var[0], len_res + 1);
	ft_strlcat(res, "=", len_res + 1);
	ft_strlcat(res, "\"", len_res + 1);
	ft_strlcat(res, new_var[1], len_res + 1);
	ft_strlcat(res, "\"", len_res + 1);
	return (res);
}

int	check_or_update(char **new_var, char *var, t_general *sa)
{
	int		index;
	char	*var_fr_env;
	int		index_env;

	index = -1;
	index_env = -1;
	index = get_env_var(sa->env_export, new_var[0]);
	if (index != -1 && ft_strchr(var, '=') != NULL)
		check_in_var(var, new_var, sa, index);
	else if (index != -1 && ft_strchr(var, '=') == NULL)
		return (0);
	else
	{
		if (ft_strchr(var, '=') != NULL)
		{
			var_fr_env = expand_quotes(ft_strdup(var));
			sa->env_export = export_update(sa->env_export, var);
			sa->env = export_update(sa->env, var_fr_env);
			free(var_fr_env);
		}
		else
			sa->env_export = export_update(sa->env_export, var);
	}
	return (1);
}

void	export_with_var(t_general *sa, char *cmd)
{
	char	*var;
	char	**new_var;

	new_var = export_split_var(cmd);
	if (new_var[1] == NULL)
	{
		var = only_name(new_var[0], cmd);
		check_or_update(new_var, var, sa);
	}
	else
	{
		var = with_value(new_var);
		check_or_update(new_var, var, sa);
	}
	free_tab(new_var);
	free(var);
}

int	ft_export(t_general *sa, char **cmd)
{
	int	i;
	int	res;

	res = 0;
	i = 1;
	if (cmd[1] == NULL)
	{
		solo_export(sa);
		res = 1;
	}
	while (cmd[i])
	{
		if (var_export_check(cmd[i]) == 1)
		{
			ft_error("export: '", cmd[i], "' : not a valid identifier");
			res = 1;
		}
		else
			export_with_var(sa, cmd[i]);
		i++;
	}
	return (res);
}
