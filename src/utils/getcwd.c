/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   getcwd.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/08 02:13:52 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/06/08 02:13:52 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/microsh.h"

void	getcwd_sh(char *buf, size_t size)
{
	if (getcwd(buf, size) == NULL)
		ft_putstr_fd(RED"getcwd FAILED.\n"RST, STDERR_FILENO);
}
