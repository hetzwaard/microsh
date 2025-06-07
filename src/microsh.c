/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   microsh.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/07 19:42:36 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/06/07 19:42:36 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/microsh.h"

char	*cell_read_line(void)
{
	char	*buf;
	size_t	bufsize;

	buf = NULL;
	ft_printf("microsh$>");
	if (getline(&buf, &bufsize, stdin) == -1)
	{
		buf = NULL;
		if (feof(stdin))
			ft_printf(RED "[EOF]" RST);
		else
			ft_printf(RED "Getline failed." RST);
		ft_printf("%s", buf);
	}
	return (buf);
}

int	main(void)
{
	char	*line;

	while (1)
	{
		line = cell_read_line();
		ft_printf("%s", line);
	}
	return (EXIT_SUCCESS);
}
