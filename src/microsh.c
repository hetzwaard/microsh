/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   microsh.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/07 19:42:36 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/06/08 03:58:24 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/microsh.h"

static void	microsh(void)
{
	char	*line;
	char	**args;

	banner_sh();
	line = micro_read_line();
	while (line)
	{
		args = micro_split_line(line);
		if (args[0] != NULL)
			micro_exec(args);
		free(line);
		free(args);
		line = micro_read_line();
	}
}

int	main(void)
{
	microsh();
	return (EXIT_SUCCESS);
}
