/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeong <jujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 14:56:31 by jujeong           #+#    #+#             */
/*   Updated: 2020/07/15 13:56:08 by jujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_findpath(char **envp, char *line, t_child c)
{
	c.i = -1;
	while (envp[++c.i])
	{
		if (!(ft_strncmp(envp[c.i], "PATH=", 5)))
			break ;
		else if (!envp[c.i])
			exit(-1); //PATH가 없는 경우
	}
	c.paths = ft_split(envp[c.i] + 5, ':');
	c.lines = ft_split(line, ' ');
	c.i = -1;
	while (c.paths[++c.i])
	{
		ft_memset(c.cmd, 0, 1024);
		ft_strcat(c.cmd, c.paths[c.i]);
		ft_strcat(c.cmd, "/");
		ft_strcat(c.cmd, c.tok);
		execve(c.cmd, c.lines, envp);
	}
	ft_free(c.lines);
	ft_free(c.paths);
	return (0);
}

int		ft_child(t_arg *a)
{
	t_child	c;

	c.tok = ft_strtok(a->line, ' ');
	ft_rediretion(a);
	if (*a->line == '/' || *a->line == '.')
		execve(c.tok, ft_split(a->line, ' '), a->envp);
	else
		ft_findpath(a->envp, a->line, c);
	write(2, "minishell: command not found: ", 30);
	write(2, c.tok, ft_strlen(c.tok));
	write(2, "\n", 1);
	exit(127);
}

int		ft_pwd(t_arg *a, int newline)
{
	if (!(getcwd(a->pwd, 1024)))
	{
		// chdir("..");
		// if (!(getcwd(a->pwd, 1024)))
		// {
		// 	write(2, "pwd error : ", 12);
		// 	write(2, strerror(errno), ft_strlen(strerror(errno)));
		// 	write(2, "\n", 1);
		// 	exit(-1);
		// }
	}
	if (!newline)
		write(1, a->pwd, ft_strlen(a->pwd));
	if (newline)
	{
		write(a->fd, a->pwd, ft_strlen(a->pwd));
		write(a->fd, "\n", 1);
	}
	return (1);
}

int		ft_prompt(t_arg *a)
{
	// ft_pwd(a, 0);
	// write(1, " $ ", 3);
	if (!get_next_line(0, &(a->line)))
		exit(1);
	//printf("|%s|\n", a->line);
	ft_memset(a->echo, 0, 1024);
	ft_strlcpy(a->echo, a->line, ft_strlen(a->line) + 1);
	ft_convert(a);
	a->fd = 1;
	//ft_redirection_out(a);
	//printf("|%s|\n", a->echo);
	return (0);
}

int		ft_cd_home(char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (!(ft_strncmp(envp[i], "HOME=", 5)))
			break ;
		i++;
		if (!envp[i])
			return(-1); // HOME이 없는 경우 찾아볼것
	}
	if ((chdir(envp[i] + 5) == -1))
	{
		write(2, "cd: no such file or directory: ", 31);
		write(2, envp[i] + 5, ft_strlen(envp[i] + 5));
		write(2, "\n", 1);
	}
	return (0);
}

int		ft_cd(t_arg *a)
{
	char	**lines;

	lines = ft_split(a->line, ' ');
	if (!lines[1])
		ft_cd_home(a->envp);
	else if ((chdir(lines[1]) == -1))
	{
		write(2, "cd: no such file or directory: ", 31);
		write(2, lines[1], ft_strlen(lines[1]));
		write(2, "\n", 1);
	}
	ft_free(lines);
	return (1);
}

int		ft_export_only(t_arg *a)
{
	char	**tmp;
	char	*change;
	int		i;
	int		j;

	i = 0;
	while (a->envp[i])
		i++;
	tmp = (char **)malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (a->envp[++i])
		tmp[i] = a->envp[i];
	tmp[i] = 0;
	i = 0;
	while (tmp[i])
	{
		j = i + 1;
		while (tmp[j])
		{
			if (ft_strcmp(tmp[i], tmp[j]) > 0)
			{
				change = tmp[i];
				tmp[i] = tmp[j];
				tmp[j] = change;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (tmp[i])
	{
		if (ft_strncmp(tmp[i], "_=", 2))
		{
			write(a->fd, tmp[i], ft_strlen(tmp[i]));
			write(a->fd, "\n", 1);
		}
		i++;
	}
	free(tmp);
	return (1);
}

int		ft_export(t_arg *a)
{
	int		i;
	int		j;
	int		len;
	char	**tmp;
	char	**lines;

	lines = ft_split(a->line, ' ');
	if (!lines[1])
	{
		ft_free(lines);
		ft_export_only(a);
		return (1);
	}
	j = 0;
	while (lines[++j])
	{
		i = 0;
		free(a->line);
		a->line = ft_strdup(lines[j]);
		if (!ft_strchr(a->line, '='))
		{
			write(2, "export: not an identifier: ", 27);
			write(2, a->line, ft_strlen(a->line));
			write(2, "\n", 1);
			ft_free(lines);
			continue ;
		}
		len = ft_strchr(a->line, '=') - a->line;
		while (a->envp[i])
		{
			if (!ft_strncmp(a->envp[i], a->line, len + 1))
			{
				free(a->envp[i]);
				a->envp[i] = ft_strdup(a->line);
				ft_set_var(a);
				break ;
			}
			i++;
		}
		if (!a->envp[i])
		{
			tmp = (char **)malloc(sizeof(char *) * (i + 2));
			i = -1;
			while (a->envp[++i])
				tmp[i] = a->envp[i];
			tmp[i] = ft_strdup(a->line);
			tmp[++i] = 0;
			free(a->envp);
			a->envp = tmp;
			ft_set_var(a);
		}
	}
	ft_free(lines);
	return (1);
}

int		ft_env(t_arg *a)
{
	int		i;

	i = 0;
	while (a->envp[i])
	{
		write(a->fd, a->envp[i], ft_strlen(a->envp[i]));
		write(a->fd, "\n", 1);
		i++;
	}
	return (1);
}

int		ft_unset(t_arg *a)
{
	char	**lines;
	int		i;
	int		j;

	lines = ft_split(a->line, ' ');
	if (!lines[1])
	{
		write(2, "unset: not enough arguments\n", 28);
		ft_free(lines);
		return (1);
	}
	i = 0;
	while (lines[++i])
	{
		j = 0;
		while (j < a->vars)
		{
			if (!ft_strncmp(a->var[j], lines[i], ft_strlen(lines[i])))
			{
				free(a->var[j]);
				while (++j < a->vars)
					a->var[j - 1] = a->var[j];
				a->var[j - 1] = a->var[j];
				a->vars--;
				break ;
			}
			j++;
		}
		j = 0;
		while (a->envp[j])
		{
			if (!ft_strncmp(a->envp[j], lines[i], ft_strlen(lines[i])))
			{
				free(a->envp[j]);
				while (a->envp[++j])
					a->envp[j - 1] = a->envp[j];
				a->envp[j - 1] = a->envp[j];
				break ;
			}
			j++;
		}
	}
	ft_free(lines);
	return (1);
}

int		ft_echo(t_arg *a) //echo 작성할때 "    "를 제대로 표현하는 방법 찾기 원본은 따로 저장하고 사용해야 할 듯
{
	int		newline;
	char	**lines;
	int		i;
	int		j;

	if (ft_strchr(a->echo, '>'))
		*(ft_strchr(a->echo, '>')) = '\0';
	if (ft_strchr(a->echo, '<'))
		*(ft_strchr(a->echo, '<')) = '\0';
	if (ft_strchr(a->echo, '|'))
		*(ft_strchr(a->echo, '|')) = '\0';
	lines = ft_echo_split(a->echo);
	i = 0;
	//while (lines[i])
	//	printf("lines : %s\n", lines[i++]);
	i = 1;
	newline = 0;
	while (lines[i] && !ft_strcmp(lines[i], "-n"))
	{
		i++;
		newline++;
	}
	i--;
	while (lines[++i])
	{
		if (i > newline + 1)
			write(a->fd, " ", 1);
		j = 0;
		while (lines[i][j])
		{
			if (lines[i][j] == '\'' && (ft_strchr(lines[i], '\'') != ft_strrchr(lines[i], '\'')))
			{
				while (lines[i][++j] != '\'')
					write(a->fd, &lines[i][j], 1);
				j++;
			}
			else if (lines[i][j] == '\"' && (ft_strchr(lines[i], '\"') != ft_strrchr(lines[i], '\"')))
			{
				if (lines[i][j + 1] == '$')
				{
					int		len;
					char	*var;
					len = 0;
					while (ft_isalnum(lines[i][j + len + 2]) || lines[i][j + len + 2] == '?')
						len++;
					if ((var = ft_find_var(a, &lines[i][j + 1], len)))
						write(a->fd, var, ft_strlen(var));
					j += len + 3;
				}
				else
					while (lines[i][++j] != '\"')
						write(a->fd, &lines[i][j], 1);
			}
			else if (lines[i][j] == '\\')
			{
				write(a->fd, &lines[i][++j], 1);
				j++;
			}
			else
			{
				if (lines[i][j] == '$')
				{
					int		len;
					char	*var;
					len = 0;
					while (ft_isalnum(lines[i][j + len + 1]) || lines[i][j + len + 1] == '?')
						len++;
					if ((var = ft_find_var(a, &lines[i][j], len)))
						write(a->fd, var, ft_strlen(var));
					j += len + 1;
				}
				else
					write(a->fd, &lines[i][j++], 1);
			}
		}
	}
	if (!newline)
		write(a->fd, "\n", 1);
	ft_free(lines);
	return (1);
}

int		ft_exit(t_arg *a)
{
	char	**lines;
	int		num;

	lines = ft_split(a->line, ' ');
	if (lines[1])
	{
		if (lines[2])
		{
			ft_free(lines);
			write(2, "exit: too many arguments\n", 25);
			return (1);
		}
		num = ft_atoi(lines[1]);
		ft_free(lines);
		exit(num);
	}
	ft_free(lines);
	exit(a->ret);
}

int		ft_built_in(t_arg *a, int ret)
{
	char	**lines;

	lines = ft_split(a->line, ' ');
	a->fd = ft_redirection_out(a);
	if (!ft_redirection_in(a))
		return (1);
	if (!(ft_strcmp(lines[0], "echo")))
		ret = ft_echo(a);
	else if (!(ft_strcmp(lines[0], "cd")))
		ret = ft_cd(a);
	else if (!(ft_strcmp(lines[0], "pwd")))
		ret = ft_pwd(a, 1);
	else if (!(ft_strcmp(lines[0], "export")))
		ret = ft_export(a);//필요
	else if (!(ft_strcmp(lines[0], "unset")))
		ret = ft_unset(a);
	else if (!(ft_strcmp(lines[0], "env")))
		ret = ft_env(a);
	else if (!(ft_strcmp(lines[0], "exit")))
		ret = ft_exit(a);
	else if (!(ft_strcmp(lines[0], "set")))
		ret = ft_print_var(a);
	else if (ft_strchr(lines[0], '='))
		ret = ft_set_var(a);
	ft_free(lines);
	return (ret);
}

int		ft_exec(t_arg *a)
{
	char	*tmp;
	int		status;

	tmp = a->line;
	a->line = ft_strtrim(tmp, " ");
	free(tmp);
	a->fd = 1;
	if (!*a->line)
		return (0);
	if (ft_pipe(a))
		return (0);
	if (ft_built_in(a, 0))
		return (0);
	a->pid = fork();
	if (!a->pid)
		ft_child(a);
	else if (a->pid > 0)
		waitpid(a->pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (WTERMSIG(status));
	return (0);
}

int		ft_exec_semi(t_arg *a)
{
	char	*multi;
	char	*tmp;
	int		len;

	len = 0;
	multi = a->line;
	tmp = multi;
	while (ft_strchr(multi, ';'))
	{
		a->line = ft_strtok_s(multi, ";", &len);
		ft_memset(a->echo, 0, 1024);
		ft_strlcpy(a->echo, a->line, len + 1);
		//a->echo[len - 1] = '\0';
		//printf("len %d\n", len);
		//printf("line %s\n", a->echo);
		multi += len;
		ft_exec(a);
		free(a->line);
	}
	a->line = ft_strdup(multi);
	ft_exec(a);
	free(tmp);
	return (0);
}

int		ft_init_envp(t_arg *a)
{
	int		i;
	char	**envp;

	i = 0;
	while (a->envp[i])
		i++;
	envp = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (a->envp[i])
	{
		envp[i] = ft_strdup(a->envp[i]);
		i++;
	}
	envp[i] = 0;
	a->envp = envp;
	return (1);
}

int		ft_init_var(t_arg *a)
{
	int		i;

	ft_init_envp(a);
	i = 0;
	a->vars = 0;
	a->ret = 0;
	while (a->envp[i])
		i++;
	a->var = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (a->envp[i])
	{
		a->var[i] = ft_strdup(a->envp[i]);
		a->vars++;
		i++;
	}
	a->var[i] = 0;
	return (0);
}

int		ft_set_var(t_arg *a)
{
	int		i;
	int		j;
	int		len;
	char	**tmp;
	char	**lines;

	lines = ft_split(a->line, ' ');
	j = 0;
	while (lines[j])
	{
		free(a->line);
		a->line = ft_strdup(lines[j]);
		len = ft_strchr(a->line, '=') - a->line;
		//printf("len : %d\n", len);
		i = 0;
		while (i < a->vars)
		{
			if (!ft_strncmp(a->var[i], a->line, len + 1))
			{
				free(a->var[i]);
				a->var[i] = ft_strdup(a->line);
				break ;
			}
			i++;
		}
		if (i == a->vars)
		{
			a->vars++;
			tmp = (char **)malloc(sizeof(char *) * (a->vars + 2));
			i = -1;
			while (++i < a->vars - 1)
				tmp[i] = a->var[i];
			tmp[i] = ft_strdup(a->line);
			tmp[++i] = 0;
			free(a->var);
			a->var = tmp;
		}
		j++;
	}
	ft_free(lines);
	return (1);
}

int		ft_print_var(t_arg *a) // 임시 확인용
{
	int		i;

	i = 0;
	while (a->var && a->var[i])
	{
		write(1, a->var[i], ft_strlen(a->var[i]));
		write(1, "\n", 1);
		i++;
	}
	return (1);
}

char	*ft_find_var(t_arg *a, char *var, int len)
{
	int		i;
	char	*ret;

	if (!ft_strcmp(var, "$?"))
	{
		ret = ft_itoa(a->ret);
		ft_strlcpy(a->str, ret, ft_strlen(ret) + 1);
		//printf("ret %s str %s\n", ret, a->str);
		free(ret);
		return (a->str);
	}
	i = 0;
	var++;
	while (a->var[i])
	{
		if (!ft_strncmp(a->var[i], var, len))
			return (a->var[i] + len + 1);
		i++;
	}
	return (0);
}

void	ft_convert(t_arg *a)
{
	char	*str;
	char	*tmp;
	int		i;
	int		j;
	int		save;

	i = -1;
	while (a->line[++i])
	{
		if (a->line[i] == '\'')
		{
			save = 0;
			j = 1;
			while (a->line[i + j] && a->line[i + j] != '\'')
				j++;
			if (a->line[i + j] == '\'')
			{
				j = 1;
				while (a->line[i] && a->line[i + j])
				{
					if (a->line[i + j] == '\'')
					{
						save = i;
						j = 2;
					}
					a->line[i] = a->line[i + j];
					i++;
				}
				a->line[i] = a->line[i + j];
			}
			i = save > 0 ? save - 1 : i;
		}
		if (a->line[i] == '\"')
		{
			save = i;
			j = 1;
			while (a->line[i + j] && a->line[i + j] != '\"')
				j++;
			if (a->line[i + j] == '\"')
			{
				j = 1;
				while (a->line[i] && a->line[i + j])
				{
					if (a->line[i + j] == '\"')
						j = 2;
					a->line[i] = a->line[i + j];
					i++;
				}
				a->line[i] = a->line[i + j];
			}
			i = save;
		}
		if (a->line[i] == '$')
		{
			j = 1;
			while (ft_isalnum(a->line[i + j]) || a->line[i + j] == '?')
				j++;
			if (!ft_find_var(a, a->line + i, j - 1))
				str = ft_strdup("");
			else
				str = ft_strdup(ft_find_var(a, a->line + i, j - 1));
			tmp = a->line;
			a->line = (char *)malloc(ft_strlen(str) + i + ft_strlen(tmp + i + j) + 2);
			ft_strlcpy(a->line, tmp, i + 1);
			ft_strcat(a->line, str);
			ft_strcat(a->line, tmp + i + j);
			i += j;
			free(tmp);
			free(str);
		}
	}
}

int		ft_redirection_out(t_arg *a)
{
	int		fd;
	int		i;
	int		len;
	char	*file;
	char	*tmp;

	i = 0;
	if ((file = ft_strchr(a->line, '>')))
	{
		if (*(file + 1) == '>')
		{
			i = 0;
			len = 0;
			file += 2;
			while (*file && *file == ' ')
				file++;
			while (file[i] && file[i++] != ' ')
				len++;
			file = ft_strldup(file, len);
			if ((fd = open(file, O_RDWR | O_APPEND | S_IROTH, 0644)) < 0)
				return (ft_error_file(file));
			tmp = ft_strldup(a->line, ft_strchr(a->line, '>') - a->line);
			free(a->line);
			a->line = tmp;
			free(file);
			return (fd);
		}
		else
		{
			i = 0;
			len = 0;
			file += 1;
			while (*file && *file == ' ')
				file++;
			while (file[i] && file[i++] != ' ')
				len++;
			file = ft_strldup(file, len);
			if ((fd = open(file, O_RDWR | O_CREAT | S_IROTH, 0644)) < 0)
				return (ft_error_file(file));
			tmp = ft_strldup(a->line, ft_strchr(a->line, '>') - a->line);
			free(a->line);
			a->line = tmp;
			free(file);
			return (fd);
		}
	}
	return (1);
}

int		ft_redirection_in(t_arg *a)
{
	int		fd;
	int		i;
	int		len;
	char	*file;
	char	*tmp;

	i = 0;
	if ((file = ft_strchr(a->line, '<')))
	{
		i = 0;
		len = 0;
		file += 1;
		while (*file && *file == ' ')
			file++;
		while (file[i] && file[i++] != ' ')
			len++;
		file = ft_strldup(file, len);
		if ((fd = open(file, O_RDONLY)) < 0)
			return (ft_error_file(file));
		tmp = ft_strldup(a->line, ft_strchr(a->line, '<') - a->line);
		free(a->line);
		a->line = tmp;
		free(file);
		return (fd);
	}
	return (1);
}

int		ft_error_file(char *file)
{
	write(2, "minishell: ", 12);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, ": ", 2);
	write(2, file, ft_strlen(file));
	write(2, "\n", 1);
	free(file);
	return(0);
}

int		ft_rediretion(t_arg *a)
{
	int		fd;

	fd = ft_redirection_in(a);
	if (fd > 2)
	{
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	fd = ft_redirection_out(a);
	if (fd > 2)
	{
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	return (0);
}

int		ft_pipe(t_arg *a)
{
	int		pid1;
	int		pid2;
	int		fd[2];
	int		status1;
	int		status2;
	char	*line1;
	char	*line2;
	char	*tmp;

	if (ft_strchr(a->line, '|'))
	{
		line1 = ft_strldup(a->line, ft_strchr(a->line, '|') - a->line);
		line2 = ft_strdup(ft_strchr(a->line, '|') + 1);
		tmp = line1;
		line1 = ft_strtrim(tmp, " ");
		free(tmp);
		tmp = line2;
		line2 = ft_strtrim(tmp, " ");
		free(tmp);
		//printf("%s\n%s\n", line1, line2);
		pipe(fd);
		pid1 = fork();
		if (pid1 == -1)
		{
			write(2, "fork error\n", 11);
		}
		if (pid1 == 0)
		{
			dup2(fd[1], STDOUT_FILENO);
			close(fd[1]);
			close(fd[0]);
			free(a->line);
			a->line = line1;
			ft_exec(a);
			exit(0);
		}
		pid2 = fork();
		if (pid2 == -1)
		{
			write(2, "fork error\n", 11);
		}
		if (pid2 == 0)
		{
			dup2(fd[0], STDIN_FILENO);
			close(fd[1]);
			close(fd[0]);
			free(a->line);
			a->line = line2;
			ft_exec(a);
			exit(0);
		}
		close(fd[1]);
		close(fd[0]);
		waitpid(pid2, &status2, 0);
		waitpid(pid1, &status1, WNOHANG);
		//printf("waitpid : %d\n", WIFEXITED(status1));
		free(line1);
		free(line2);
		return (1);
	}
	return (0);
}

void	sig_handler(int signo)
{
	char	pwd[1024];
	int		status;
	int		pid;

	pid = waitpid(-1, &status, WNOHANG);
	if (signo == SIGQUIT)
	{
		if (pid == 0)
			write(1, "quit\n", 5);
	}
	else
	{
		write(1, "\n", 1);
		if (pid != 0)
		{
			getcwd(pwd, 1024);
			write(1, pwd, ft_strlen(pwd));
			write(1, " $ ", 3);
		}
	}
}

int		main(int argc, char *argv[], char *envp[])
{
	t_arg	a;

	a.argc = argc;
	a.argv = argv;
	a.envp = envp;
	ft_init_var(&a);
	signal(SIGINT, (void *)sig_handler);
	signal(SIGQUIT, (void *)sig_handler);
	while (1)
	{
		ft_prompt(&a);
		if (ft_strchr(a.line, ';'))
			a.ret = ft_exec_semi(&a);
		else
			a.ret = ft_exec(&a);
		free(a.line);
		a.line = 0;
	}
	return (0);
}
