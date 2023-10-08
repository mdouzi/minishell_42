/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 01:17:28 by mdouzi            #+#    #+#             */
/*   Updated: 2023/10/08 02:34:05 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

int		g_sig = 0;

void	initialize_signals(void)
{
	g_sig = 0;
	signal(SIGINT, restore_pt);
	signal(SIGQUIT, SIG_IGN);
}

t_list	*parse_commands(char *s, t_general *sa)
{
	char	*st;
	char	**stt;
	char	**str;
	int		i;
	t_list	*cmds;

	if (s[0] == '\0')
		return (NULL);
	if (checker_line(s) != 1 || checker_redir(s) != 1)
	{
		sa->ex_status = 258;
		return (NULL);
	}
	st = addnext_pipe(s);
	stt = ft_split(st, '\n');
	str = remove_pipe_pointers(stt);
	if (!str || !str[0])
		return (NULL);
	i = 0;
	cmds = create_node(str[0], i);
	while (++i < count_cmds(str))
		add_node_front(cmds, str[i], i);
	free_double_array(str);
	return (cmds);
}

void	execute_commands(t_general *sa, t_list *cmds)
{
	initialize_signals();
	cmd_define(cmds);
	final_struct(cmds, sa->env, sa);
	update_struct(cmds);
	redir_array(cmds);
	final_remove_quotes(cmds);
	final_cmd(cmds);
	default_fds(cmds, sa);
	make_red(cmds, sa);
	ex_test(cmds, sa);
}

void	init_sa(t_general *sa, char **env)
{
	init_env_data(sa, env);
	get_export_env(sa);
}

int	main(void)
{
	char		*s;
	t_general	*sa;
	t_list		*cmds;
	extern char	**environ;

	sa = malloc(sizeof(t_general));
	memset(sa, 0, sizeof(t_general));
	init_sa(sa, environ);
	initialize_signals(); 
	s = NULL;
	while (1)
	{
		g_sig = 0;
		s = readline("minishell$>");
		add_history(s);
		if (!s)
			exit(0);
		cmds = parse_commands(s, sa);
		if (cmds != NULL)
			execute_commands(sa, cmds);
		free_all(cmds);
		if (s)
			free(s);
	}
	return (0);
}
