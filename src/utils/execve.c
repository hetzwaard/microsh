/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execve.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/08 02:17:27 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/06/08 02:17:27 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/microsh.h"

extern char	**environ;

void	execve_sh(const char *file, char *const argv[])
{
	char	*full_path;

	if (!file || !argv)
	{
		fprintf(stderr, RED "Execve: invalid arguments.\n" RST);
		exit(EXIT_FAILURE);
	}
	full_path = micro_path(file);
	if (!full_path)
	{
		ft_putstr_fd(RED "Command not found.\n" RST, STDERR_FILENO);
		exit(EX_UNAVAILABLE);
	}
	if (execve(full_path, argv, environ) == -1)
	{
		ft_putstr_fd(RED "MICRO_JR failed.\n" RST, STDERR_FILENO);
		exit(EX_UNAVAILABLE);
	}
}
