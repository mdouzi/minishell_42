/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 04:11:13 by mdouzi            #+#    #+#             */
/*   Updated: 2023/10/03 22:03:17 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

char	*make_path(char *path)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	while (path[i] && path[i] != '=')
		i++;
	if (path[i] == '=')
		i++;
	res = (char *)malloc(sizeof(char) * (ft_strlen(path) - i + 1));
	while (path[i])
	{
		res[j] = path[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}

char	*search_executable(char **directories, char *cmd)
{
	int		i;
	char	*res;
	char	*path;

	i = 0;
	res = NULL;
	while (directories[i])
	{
		path = ft_strjoin(directories[i], cmd);
		if (access(path, F_OK) == 0)
		{
			res = ft_strdup(path);
			free(path);
			break ;
		}
		free(path);
		i++;
	}
	return (res);
}

char	*get_path(char **env, char *cmd)
{
	char	*path;
	char	**splited;
	char	*fc;
	char	*res;

	if (get_env_var(env, "PATH") == -1)
	{
		ft_error("minishell: ", cmd, ": No such file or directory");
		return (NULL);
	}
	path = make_path(env[get_env_var(env, "PATH")]);
	splited = ft_split(path, ':');
	fc = ft_strjoin("/", cmd);
	res = search_executable(splited, fc);
	if (res == NULL)
	{
		ft_error("minishell : ", cmd, " : command not found");
		free(fc);
		free_tab(splited);
		exit(EXIT_FAILURE);
	}
	free_tab(splited);
	return (res);
}

void	ex_cmd(t_general *sa, t_list *cmd)
{
	char	*cm;

	cm = NULL;
	if (cmd->final_cmd[0][0] == '.' || cmd->final_cmd[0][0] == '/')
	{
		if (access(cmd->final_cmd[0], F_OK) != 0)
		{
			ft_error("minishell : ", cmd->final_cmd[0], " : command not found");
			sa->ex_status = 127;
			exit(1);
		}
		else
			execve(cmd->final_cmd[0], cmd->final_cmd, sa->env);
	}
	else
	{
		cm = ft_strdup(get_path(sa->env, cmd->final_cmd[0]));
		execve(cm, cmd->final_cmd, sa->env);
		free(cm);
	}
}
