/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 03:16:21 by mdouzi            #+#    #+#             */
/*   Updated: 2023/10/07 04:08:00 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

char	*copy_name_var(char *name, int len, int equal)
{
	int		i;
	char	*res;

	i = 0;
	res = NULL;
	res = (char *)malloc(sizeof(char) * len);
	while (name[i])
	{
		res[i] = name[i];
		i++;
		if (name[i] == '\0' && equal == 1)
		{
			res[i] = '=';
			while (i < len)
				res[++i] = '"';
		}
	}
	res[i] = '\0';
	return (res);
}

char	*only_name(char *name, char *arg)
{
	int		len;
	char	*res;
	int		equal;

	len = 0;
	equal = 0;
	if (ft_strchr(arg, '=') != NULL)
	{
		len = ft_strlen(name) + 3;
		equal = 1;
	}
	else
		len = ft_strlen(name);
	res = copy_name_var(name, len, equal);
	return (res);
}

int	var_export_check(char *env_var)
{
	int	i;

	i = 0;
	if (ft_isalpha(env_var[i]) == 0 && env_var[i] != '_')
		return (1);
	i++;
	while (env_var[i] && env_var[i] != '=')
	{
		if (ft_isalnum(env_var[i]) == 0 && env_var[i] != '_')
			return (1);
		i++;
	}
	return (0);
}

//check number of words for export like var= || var=value
int	check_number_of_wr(char *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	if (str[0] != c && str[0] != '\0')
		count++;
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != '\0')
			return (2);
		i++;
	}
	return (1);
}

int	double_qchek(char *str)
{
	if (!str)
		return (0);
	else if (str[0] == '"' && str[1] == '"' && str[2] == '\0')
		return (1);
	else if (str[0] == '"' && str[ft_strlen(str) - 1] == '"')
		return (1);
	return (0);
}
