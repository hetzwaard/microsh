/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execvp.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/08 02:17:27 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/06/08 02:17:27 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/microsh.h"

void	execvp_sh(const char *file, char *const argv[])
{
	if (!file || !argv)
	{
		fprintf(stderr, RED "Execvp: invalid arguments.\n" RST);
		exit(EXIT_FAILURE);
	}
	if (execvp(file, argv) == -1)
	{
		ft_putstr_fd(RED "MICRO_JR failed.\n" RST, STDERR_FILENO);
		exit(EX_UNAVAILABLE);
	}
}
