/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   malloc.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/08 02:15:35 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/06/08 02:15:35 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/microsh.h"

void	*malloc_sh(size_t size)
{
	void	*ptr;

	if (size == 0)
		return (NULL);
	ptr = malloc(size);
	if (!ptr)
	{
		ft_putstr_fd(RED "Malloc failed.\n" RST, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (ptr);
}
