/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 21:30:26 by mzoheir           #+#    #+#             */
/*   Updated: 2023/10/07 05:00:09 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

int	count_cmds(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*extract_env(char *str)
{
	int		i;
	char	*extract;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (str[i] == '=')
		i++;
	if (!str[i])
		return (NULL);
	else
		extract = ft_substr(str, i, ft_strlen(str) - i);
	return (extract);
}

void	expand_env_util(t_index_env *index, char *str, char **env)
{
	index->j = index->i + 1;
	while (str[index->j] && (ft_isalnum(str[index->j]) || str[index->j] == ' '))
		index->j++;
	if (index->j > index->i + 1)
	{
		index->check_env = ft_substr(str, index->i + 1, index->j - index->i
				- 1);
		if (get_env_var(env, index->check_env) == -1)
			index->i += ft_strlen(index->check_env);
		else if (get_env_var(env, index->check_env) != -1)
		{
			index->extract = extract_env(env[get_env_var(env,
						index->check_env)]);
			index->result = ft_strjoin2(index->result, index->extract);
			index->i += ft_strlen(index->check_env);
			free(index->extract);
		}
		else if (!extract_env(env[get_env_var(env, index->check_env)]))
			index->i += ft_strlen(index->check_env);
		free(index->check_env);
	}
}

void	expand_env_norm(t_index_env *index, t_general *sa)
{
	index->ex_status = ft_itoa(sa->ex_status);
	index->result = ft_strjoin2(index->result, index->ex_status);
	free(index->ex_status);
	index->i += 1;
}

char	*expand_env(char *str, char **env, t_general *sa)
{
	t_index_env	index;

	initialize_env(&index);
	index.result = ft_calloc(1, 1);
	if (!index.result)
		return (NULL);
	while (str[index.i])
	{
		if (str[index.i] == '$' && check_dollar(str, index.i) == 0
			&& str[index.i + 1] && str[index.i + 1] != ' ')
		{
			if (str[index.i + 1] == '?')
				expand_env_norm(&index, sa);
			else
				expand_env_util(&index, str, env);
		}
		else
			index.result = concatenate_char(index.result, str[index.i]);
		index.i++;
	}
	free(str);
	return (index.result);
}
