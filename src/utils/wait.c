/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wait.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/08 02:18:26 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/06/08 02:18:26 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/microsh.h"

pid_t	wait_sh(int *status)
{
	pid_t	result;

	if (!status)
	{
		fprintf(stderr, RED "Wait: status argument required.\n" RST);
		return (-1);
	}
	result = wait(status);
	if (result == -1)
		ft_putstr_fd(RED "Wait failed.\n" RST, STDERR_FILENO);
	if (WIFEXITED(*status))
		*status = WEXITSTATUS(*status);
	return (result);
}
