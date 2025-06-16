/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   micro_coms.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/08 02:24:16 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/06/08 03:52:11 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/microsh.h"

int			g_status = 0;

t_builtin	g_builtin[] = {
{.builtin_name = "cd", .foo = micro_cd},
	//{.builtin_name = "echo", .foo = micro_echo},
{.builtin_name = "env", .foo = micro_env},
{.builtin_name = "exit", .foo = micro_exit},
	//{.builtin_name = "export", .foo = micro_export},
	//{.builtin_name = "pwd", .foo = micro_pwd},
	//{.builtin_name = "unset", .foo = micro_unset},
{.builtin_name = NULL, .foo = NULL},
};

void	micro_launch(char **args)
{
	if (fork_sh() == MICRO_JR)
		execve_sh(args[0], args);
	else
		wait_sh(&g_status);
}

void	micro_exec(char **args)
{
	int			i;
	const char	*current;

	i = 0;
	current = g_builtin[i].builtin_name;
	while (current)
	{
		if (!ft_strcmp(current, args[0]))
		{
			g_status = g_builtin[i].foo(args);
			return ;
		}
		i++;
		current = g_builtin[i].builtin_name;
	}
	micro_launch(args);
}
