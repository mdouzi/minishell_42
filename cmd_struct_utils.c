/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_struct_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoheir <mzoheir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 06:31:29 by mzoheir           #+#    #+#             */
/*   Updated: 2023/10/04 07:30:39 by mzoheir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

int	skip_quote(char *str, int i)
{
	if (str[i] == '\"')
	{
		i++;
		while (str[i] != '\"')
			i++;
	}
	else if (str[i] == '\'')
	{
		i++;
		while (str[i] != '\'')
			i++;
	}
	return (i);
}

char	*fix_split(char *str)
{
	int		i;
	int		len;
	char	*fixed;

	i = 0;
	len = ft_strlen(str);
	fixed = malloc(sizeof(char) * len);
	while (i < len - 1)
	{
		fixed[i] = str[i];
		i++;
	}
	fixed[len - 1] = '\0';
	return (fixed);
}

void	free_double_array(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	check_dollar_bis(t_index *utils, char *str)
{
	if (str[utils->i] == '\'' && str[utils->i - 1] != '\\'
		&& utils->indoublequotes == 0 && utils->insinglequotes == 0)
		utils->insinglequotes = 1;
	else if (str[utils->i] == '\"' && str[utils->i - 1] != '\\'
		&& utils->indoublequotes == 0 && utils->insinglequotes == 0)
		utils->indoublequotes = 1;
	else if (str[utils->i] == '\'' && str[utils->i - 1] != '\\'
		&& utils->indoublequotes == 0 && utils->insinglequotes == 1)
		utils->insinglequotes = 0;
	else if (str[utils->i] == '\"' && str[utils->i - 1] != '\\'
		&& utils->indoublequotes == 1 && utils->insinglequotes == 0)
		utils->indoublequotes = 0;
}

int	check_dollar(char *str, int index)
{
	t_index	utils;

	initialize_index(&utils);
	while (utils.i < index)
	{
		check_dollar_bis(&utils, str);
		utils.i++;
	}
	if (utils.i == index && utils.indoublequotes == 1
		&& utils.insinglequotes == 0)
		return (0);
	else if (utils.i == index && utils.indoublequotes == 0
		&& utils.insinglequotes == 0)
		return (0);
	else if (utils.i == index && utils.indoublequotes == 0
		&& utils.insinglequotes == 1)
		return (1);
	return (0);
}
