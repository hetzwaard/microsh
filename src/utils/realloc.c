/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   realloc.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/08 02:16:29 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/06/08 02:16:29 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/microsh.h"

void	*realloc_sh(void *ptr, size_t size)
{
	void	*new_ptr;

	new_ptr = realloc(ptr, size);
	if (!new_ptr && size != 0)
	{
		ft_putstr_fd(RED "Realloc failed.\n" RST, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (new_ptr);
}
