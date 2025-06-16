/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   micro_cd.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/12 15:20:16 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/06/12 15:20:16 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/microsh.h"

static char	*get_env(char *name)
{
	char	*val;

	val = getenv(name);
	if (!val)
	{
		write(2, "microsh: cd: ", 14);
		write(2, name, strlen(name));
		write(2, " not set\n", 9);
	}
	return (val);
}

int	micro_cd(char **args)
{
	static char	oldpwd[4096];
	char		cwd[4096];
	char		*target;

	getcwd_sh(cwd, sizeof(cwd));
	if (!args[1] || !ft_strcmp(args[1], "~"))
		target = get_env("HOME");
	else if (!ft_strcmp(args[1], "-"))
	{
		if (!*oldpwd)
			return (write(2, "microsh: cd: OLDPWD not set\n", 28), 1);
		target = oldpwd;
		ft_printf("%s\n", oldpwd);
	}
	else
		target = args[1];
	if (!target || chdir(target))
		return (perror("microsh: cd"), 1);
	ft_strcpy(oldpwd, cwd);
	return (0);
}
