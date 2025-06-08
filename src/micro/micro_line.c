/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   micro_line.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/08 02:22:55 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/06/08 02:22:55 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/microsh.h"

static void	split_loop(char **tokens, char *line, size_t *bufsize)
{
	unsigned int	position;
	char			*token;

	position = 0;
	token = strtok(line, DEL);
	while (token)
	{
		tokens[position++] = token;
		if (position >= *bufsize)
		{
			*bufsize *= 2;
			tokens = realloc_sh(tokens, (*bufsize) * sizeof(*tokens));
		}
		token = strtok(NULL, DEL);
	}
	tokens[position] = NULL;
}

char	**micro_split_line(char *line)
{
	char	**tokens;
	size_t	bufsize;

	bufsize = BUFSIZ;
	tokens = malloc_sh(bufsize * sizeof(*tokens));
	split_loop(tokens, line, &bufsize);
	return (tokens);
}

char	*micro_read_line(void)
{
	char	*buf;
	size_t	bufsize;
	char	cwd[BUFSIZ];

	buf = NULL;
	getcwd_sh(cwd, sizeof(cwd));
	ft_printf(CLOVER "☘️  %s$> " RST, cwd);
	if (getline(&buf, &bufsize, stdin) == -1)
	{
		free(buf);
		buf = NULL;
		if (feof(stdin))
			ft_printf(RED "[EOF]\n" RST);
		else
			ft_printf(RED "Getline failed.\n" RST);
	}
	return (buf);
}
