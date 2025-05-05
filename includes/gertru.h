/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gertru.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:51:48 by dgargant          #+#    #+#             */
/*   Updated: 2025/05/05 10:59:54 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GERTRU_H
# define GERTRU_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <fcntl.h>

# define RED "\001\033[0;31m\002"
# define GREEN "\001\033[0;32m\002"
# define PURPLE "\001\033[0;95m\002"
# define RESET "\001\033[0m\002"


# define N_NF -1 // no tiene fichero
# define N_INF 0 // es infile
# define N_OUTF 1 // es outfile
# define N_HRD 2 // es heredoc
# define N_AOUTF 3 // es outfile en modo apend

typedef struct s_files
{
	char			**file; // doble puntero con los fichero del nodo (done)
	int				*flagfd; // numero que indica que tipo de redireccion/ejecuciones (done)
	int				*fd; // fd del documento (pav)
	int				hrd_n; // 1 = delimitador entre comillas(no se expande), 0 = delimitador sin comillas
	int				nfiles; // numero de ficheros en el nodo  (done)
}		t_files;

typedef struct s_cmds
{
	char			**cmds; // doble puntero de los comandos (TO DO)
	int				flag; // flag para las comillas ""/''
	t_files			*s_files; // estructura que contiene los ficheros del nodo (done)
	char			**args;
	struct s_cmds	*next;
}			t_cmds;

//estructura de parsep
typedef struct s_pars
{
	int		fdb; //flag comillas dobles
	int		fs; //flag comillas simples
	int		count; //contador
	int		np;
	int		np2;
	int		i; // contador de posicion en la tiena de tokenizado
	int		c_cmd; // contador del puntero de ncmds
	int		hrd_n; // 1 = delimitador entre comillas(no se expande), 0 = delimitador sin comillas
	int		*ncmds; //puntero con el numero de comandos de cada nodo
}			t_pars;


typedef struct s_pipes
{
	int		**fd; // fds de los pipes
	int		mode; // (pav)
	pid_t	*pids; // (forcks)
	int		num_cmds; // numero de nodos (done)
	char	**env; // puntero a enviroment (done)
	char	**env_cp; // Copia de enviroment (to do)
	int		nhrd; // numero de heredocs (done) (modificado)
	int		npipes; // numero de pipes  (modificado)
	char	*pwd;
	char	*old_pwd;
	t_cmds	*cmds; // lista de comandos
	t_pars *pars; // estructura de datos de parseo
}			t_pipes;


typedef enum s_aut
{
	A_INI,
	A_ERR,
	A_SPA,
	A_PRI,
	A_DOB,
	A_SIN,
	A_PIP,
	A_RIN,
	A_ROU,
	A_RIO,
}	t_aut;

int		main(int argc, char **argv, char **envp);

void	read_imput(t_pipes *data);

void	parsing_init(t_pipes *data, char *line);

void	tokenizer_init(t_pipes *data, char *line);

int		init_fd(t_pipes *data);

int		init_pid(t_pipes **data);

void	take_hdelimiter(t_pipes *data, char *line);

void	take_tfile(t_pipes *data, char *line, int flagfd);

void	count_heredocs(t_pipes *data,char *line);

void	count_pipes(t_pipes *data, char *line);

void	count_node_files(t_pipes *data, char *line, int i);

char	*take_cmd(t_pipes *data,char *line ,int i);

void	take_token(t_pipes *data);

void		take_fist_token(t_pipes *data ,char *line);

void	take_pipes(t_pipes *data, char *line);

void	set_node_files(t_pipes *data, char *file, int flagfd);

void	insert_cmds(t_pipes *data, char *comand);

void	count_cmds(t_pipes *data, char *line);

void	take_quote(t_pipes *data, char *line, char c);

int	ft_is_token(char *line, int i);

char	**ft_init_env(char **str);

int	ft_array_length(char **str);

int		syntax_init(char *line);

int	ft_check_syntax(char *line);

int	check_state(int prev, char c);

int	get_state(int prev, int pos);

char	*expand_init(t_pipes *data, char *line);

char	*take_v(char *line, int i);

char	*search_in_env(t_pipes *data, char *v_search);

char	*insert_expansion(char *line, char * var, char *exp, int i);

void	delete_some_quotes(t_pipes *data, char *line, char *new_line, int i);

void	quote_manager(t_pipes *data, char *line);

//int	is_piped(char *line, int i);

//List Utils

int		init_pid(t_pipes **data);

int		init_fd(t_pipes *data);

t_cmds	*ft_lstlast(t_cmds *lst);

void	ft_lstadd_back(t_cmds *slst, t_cmds *new);

// list utils files

//t_files	*file_lstlast(t_files *lst);

//void	file_lstadd_back(t_files *lst, t_files *new);

//t_files	*file_lstnew(int flagfd);

//t_cmds	*ft_lstnew(int flagfd, char *cmd, char *file);

t_cmds	*ft_lstnew();

//Frees

void	free_fd(t_pipes *data);

void	ft_free_struct(t_pipes *data);

void	ft_free_tab(char **tab);

void	free_lists(t_cmds *lst);

void	close_files(t_cmds *list);

#endif