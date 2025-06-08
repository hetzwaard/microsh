/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fork.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/08 02:19:12 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/06/08 02:19:12 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/microsh.h"

pid_t	fork_sh(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		ft_putstr_fd(RED "Fork Failed.\n" RST, STDERR_FILENO);
		exit(EX_OSERR);
	}
	return (pid);
}
