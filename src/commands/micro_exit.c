/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   micro_exit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/12 15:16:11 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/06/12 15:16:11 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/microsh.h"

int	micro_exit(char **args)
{
	(void)args;
	exit(EXIT_SUCCESS);
}
