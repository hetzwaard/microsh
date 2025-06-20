/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   microsh.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/07 19:42:22 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/06/08 03:58:01 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICROSH_H
# define MICROSH_H

# include "libft/include/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <sysexits.h>
# include <unistd.h>

# define Y "\033[1;33m"
# define G "\033[1;32m"
# define C "\033[1;36m"
# define RED "\033[1;31m"
# define RST "\033[0m"
# define CLOVER "\033[38;2;120;200;80m"

# define DEL "\n\t \v\f\r"
# define MICRO_JR 0

typedef struct s_cmd_table
{
	char				**cmd;
	char				*infile;
	char				*outfile;
	int					infd;
	int					outfd;
	int					append_flag;
	char				*heredoc_delim;
	struct s_cmd_table	*next;

}						t_cmd_table;

typedef struct s_builtin
{
	const char			*builtin_name;
	int					(*foo)(char **);
}						t_builtin;

/* UTILS */
void					banner_sh(void);
void					execve_sh(const char *file, char *const argv[]);
void					getcwd_sh(char *buf, size_t size);
void					*malloc_sh(size_t size);
void					*realloc_sh(void *ptr, size_t size);
pid_t					wait_sh(int *status);
pid_t					fork_sh(void);

/* MICROSH */
char					**micro_split_line(char *line);
char					*micro_path(const char *cmd);
char					*micro_read_line(void);

/* COMMANDS */
void					micro_launch(char **args);
void					micro_exec(char **args);
int						micro_exit(char **args);
int						micro_env(char **args);
int						micro_env(char **args);
int						micro_cd(char **args);

#endif
