/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 04:01:27 by mdouzi            #+#    #+#             */
/*   Updated: 2023/09/20 04:01:45 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

int	ft_pwd(void)
{
	char	cur[PATH_MAX];

	if (getcwd(cur, PATH_MAX) == NULL)
		return (1);
	ft_putstr_fd(cur, 1);
	ft_putstr_fd("\n", 1);
	return (0);
}
