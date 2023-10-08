/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Errors_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:54:45 by mzoheir           #+#    #+#             */
/*   Updated: 2023/10/06 07:19:39 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

char	*ft_strtrim2(char *s1, char *set)
{
	int	len;
	int	i;

	i = 0;
	if (s1 == 0 || set == 0)
		return (NULL);
	while (ft_strchr(set, s1[i]) && s1[i])
		i++;
	if (!s1[i])
	{
		free(s1);
		return (ft_substr(s1, 0, 0));
	}
	len = ft_strlen(s1);
	while (ft_strchr(set, s1[len - 1]) && len > i)
		len--;
	free(s1);
	return (ft_substr(s1, i, len - i));
}

int	checker_line(char *line)
{
	char	*copy;

	if (checkquotes(line) == 0)
	{
		printf("Invalid command: quotes not closed\n");
		return (0);
	}
	copy = ft_strdup(line);
	copy = ft_strtrim2(copy, " \t");
	if (copy[0] == '|')
	{
		printf("syntax error near unexpected token `|'\n");
		free(copy);
		return (0);
	}
	if (!copy || copy[0] == '\0')
	{
		free(copy);
		return (0);
	}
	free(copy);
	return (1);
}

int	error_handler(t_index_check *index)
{
	if (error_line_util(index) == 0)
		return (0);
	if (error_bis(index) == 0)
		return (0);
	if (error_line_bis(index) == 0)
		return (0);
	if (error_line_out(index) == 0)
		return (0);
	if (error_line_in(index) == 0)
		return (0);
	if (error_line_util_pipe(index) == 0)
		return (0);
	if (error_line_util_red(index) == 0)
		return (0);
	return (1);
}

int	checker_redir(char *line)
{
	t_index_check	index;

	initialize_checker(&index);
	index.copy = ft_strtrim(line, " \t");
	if (index.copy[0] == '\0')
		return (0);
	index.len = ft_strlen(index.copy);
	if (error_line_end(&index) == 0)
	{
		free(index.copy);
		return (0);
	}
	while (index.copy[index.i])
	{
		if (index.copy[index.i] == '\'' || index.copy[index.i] == '"')
			index.inquotes = !index.inquotes;
		if (error_handler(&index) == 0)
		{
			free(index.copy);
			return (0);
		}
		index.i++;
	}
	free(index.copy);
	return (1);
}
