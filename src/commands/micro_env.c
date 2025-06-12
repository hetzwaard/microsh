/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   micro_env.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/12 14:59:49 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/06/12 14:59:49 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/microsh.h"

int	micro_env(char **args)
{
	extern char	**environ;
	int			i;

	(void)args;
	if (!environ)
		return (1);
	i = 0;
	while (environ[i])
	{
		ft_printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}
