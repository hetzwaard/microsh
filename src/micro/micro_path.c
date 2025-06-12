/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   micro_path.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/12 14:47:23 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/06/12 14:47:23 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/microsh.h"

static char	*join_and_check(char *dir, const char *cmd)
{
	char	*tmp;
	char	*full;

	tmp = ft_strjoin(dir, "/");
	if (!tmp)
		return (NULL);
	full = ft_strjoin(tmp, cmd);
	free(tmp);
	if (!full)
		return (NULL);
	if (access(full, X_OK) == 0)
		return (full);
	free(full);
	return (NULL);
}

char	*micro_path(const char *cmd)
{
	char	**paths;
	char	*path_env;
	char	*full;
	int		i;

	if (!cmd || ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	path_env = getenv("PATH");
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		full = join_and_check(paths[i], cmd);
		if (full)
		{
			ft_free_arr(paths);
			return (full);
		}
		i++;
	}
	return (ft_free_arr(paths), NULL);
}
