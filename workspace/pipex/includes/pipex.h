/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:18:01 by fandre-b          #+#    #+#             */
/*   Updated: 2024/04/26 11:18:01 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/wait.h>
# include <unistd.h>
# include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

typedef struct	s_info
{
    int		fd[2];
    int		here_doc;
    char	***arg_cmd;
    char	*limiter;
}				t_info;


int		main(int argc, char **argv);
int		pipe_arg_cmd(t_info *info);
void	free_info(t_info *info);
//extract info
int		parcel_argv(int argc, char **argv, t_info *info);
int		parcel_open_fd(int argc, char **argv, t_info *info);
char	*ft_witch(char *first_cmd);
int		input_gnl(t_info *info);
//run program/command
void	exe_cmd_child(int input_fd, int output_fd, int *fd_error,  char **cmd);
void	exe_cmd_child(int input_fd, int output_fd, int *fd_error,  char **cmd);

int		execute_command(int input_fd, int output_fd, char **cmd);
//big utils
int		get_next_line(int fd, char **new_str);
char	**ft_split(char *str, char c);

	//split TODO static rest of functions
//libft utils
int		ft_strlen(char *s);
char	*ft_strstr(const char *big, const char *little);
int		ft_strchr_index(char *str, char c);
char	*ft_strnjoin(char *old_str, char *str_add, int size);

char	*ft_strnjoin_gnl(char *old_str, char *str_add, int size);
int	ft_strchr_index_gnl(char *str, char c);
char	*ft_clearbuffer(void *str, int size);
char	*ft_memshift_gnl(void *str, int n_shift);

void	print_struct(char *str, t_info *info);
void	print_cmds(char *str, char **matrix);


#endif