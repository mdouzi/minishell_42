/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi < mdouzi@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:20:00 by mzoheir           #+#    #+#             */
/*   Updated: 2023/10/07 03:39:01 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <fcntl.h>
#include <limits.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

extern int			g_sig;
void				rl_replace_line(const char *text, int clear_undo);

typedef enum e_type
{
	WORD = 1,
	HEREDOC,
	APPEND,
	RED_OUT,
	RED_IN,
	FYLE,
	NOT,
	END,
	ENV,
	DELIMITER,
}					t_type;

typedef struct s_define
{
	int				type;
	t_type			state;
	int				index;
	char			*content;
	int				dollar;
	int				size_struct;
	int				size_struct_inserted;
}					t_define;

typedef struct s_redir
{
	int				type;
	char			*file;
	char			*delimiter;
}					t_redir;

typedef struct s_index
{
	int				i;
	int				j;
	int				insinglequotes;
	int				indoublequotes;
	int				inquotes;
	int				len;
	int				index;
}					t_index;

typedef struct s_count
{
	int				word_count;
	int				insinglequotes;
	int				indoublequotes;
	int				wordstart;
}					t_count;

typedef struct s_lexer
{
	int				i;
	int				j;
	int				count;
	char			**result;
}					t_lexer;

typedef struct s_index_check
{
	int				i;
	int				j;
	int				inquotes;
	int				len;
	int				index;
	char			*copy;
}					t_index_check;

typedef struct s_env
{
	int				i;
	int				j;
	char			*result;
	char			*check_env;
	char			*extract;
	char			*ex_status;
}					t_index_env;

typedef struct s_list
{
	char			**cmd;
	pid_t			id;
	int				fd_in;
	int				fd_out;
	int				index;
	int				size_cmd;
	t_define		*define;
	int				red_nb;
	t_redir			*redir;
	char			**final_cmd;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

typedef struct s_general
{
	int				ex_status;
	char			*del;
	char			**env;
	pid_t			pid;
	int				num_cmds;
	int				index;
	char			**env_export;
	t_list			*cmds;

}					t_general;

//   PARSING UTILS

int					checker_line(char *line);
int					checker_redir(char *line);
int					cnt_cmds(char *line);
int					valid_cmd(char **splitted);
int					checkquotes(char *line);
char				*addnext_pipe(char *str);
void				addnext_pipe_bis(t_index *index, char *new_str);
void				addnext_pipe_util(t_index *index, char *str, char *new_str);
void				remove_xtra_newlines(char *str);
void				tokenizer(char **str);
t_list				*create_node(char *cmd, int i);
void				add_node_front(t_list *head, char *str, int i);
void				add_prev_list(t_list *cmds);
int					checkquote_index(char *str, int index);
int					check_dollar(char *str, int index);
char				**remove_pipe_pointers(char **str);
char				**split_cmd(char *str);
int					iswhitespace(char c);
void				split_whitespace(char *newstr, t_index *index, char *str);
void				split_red_in(char *newstr, t_index *index);
void				split_append(char *newstr, t_index *index);
void				split_red_out(char *newstr, t_index *index);
void				split_heredoc(char *newstr, t_index *index);
void				split_quotes(char *newstr, t_index *index, char *str);
void				split_redirections(char *newstr, t_index *index, char *str);
int					count_cmds(char **str);
int					sizeof_cmd(t_list *cmds);

void				add_prev_list(t_list *cmds);

// LINE ERRORS

int					error_line_in(t_index_check *index);
int					error_line_out(t_index_check *index);
int					error_line_bis(t_index_check *index);
int					error_bis(t_index_check *index);
int					error_line_end(t_index_check *index);
int					error_line_util(t_index_check *index);
int					error_line_util_pipe(t_index_check *index);
int					error_line_util_red(t_index_check *index);

// DEFINES

void				define_word(t_list *tmp, int i);
void				define_all(t_list *tmp, int i);
void				cmd_define(t_list *cmds);
void				define_hrdc(t_list *tmp, int *i);
void				define_append(t_list *tmp, int *i);
void				define_red_in(t_list *tmp, int *i);
void				define_red_out(t_list *tmp, int *i);

//  ENV Expand
char				*extract_env(char *str);
char				*expand_env(char *str, char **env, t_general *sa);
char				*expand_quotes(char *str);
char				*concatenate_char(char *str, char c);
void				initialize_define(t_define *new_struct, int size);
void				initialize_define_inserted(t_define *define, int inserted);
void				initialize_counter(t_count *counter);
void				initialize_index(t_index *index);
void				initialize_env(t_index_env *index);
void				initialize_checker(t_index_check *index);
void				initialize_lex(t_lexer *index);
int					countwords(char *str);
void				count_word_bis(char *str, t_count *count_words, int *i);
int					skip_quote(char *str, int i);
void				free_double_array(char **str);

// Expand

void				fill_new_struct(char *str, t_define *new_struct);
void				final_struct(t_list *cmds, char **env, t_general *sa);
void				redir_array(t_list *commands);
void				redir_arrayx(t_list *tmp, int *i, int *j);
void				redir_red_in(t_list *tmp, int *i, int *j);
void				redir_red_out(t_list *tmp, int *i, int *j);
void				redir_append(t_list *tmp, int *i, int *j);
void				redir_heredoc(t_list *tmp, int *i, int *j);
void				final_cmd(t_list *cmds);
void				final_remove_quotes(t_list *cmds);
char				*filler_split(char *str);
void				fill_new_split(char *str, t_define *new_struct, int *index);
void				fill_new_split_file(char *str, t_define *new_struct,
						int *index);
int					new_struct_size(t_list *cmds);
void				update_struct(t_list *cmds);
void				update_struct_util(t_list *tmp, t_define *final_struct,
						int *index, int i);
void				update_struct_bis(t_list *tmp, t_general *sa, int i);
char				*ft_strjoin2(char *s1, char *s2);
void				cp_st(char *src, char *dst, int *i);

// FREE !

void				free_words(char **words, int count);
void				free_redir(t_list *cmds);
void				free_struct(t_define *define);
void				free_final_cmd(t_list *cmds);
void				free_inserted(t_define *define);
void				free_cmd(t_list *cmds);
void				free_all(t_list *cmds);

//general functions
int					ft_size(char **str);
int					ft_strcmp(char *s1, char *s2);
void				free_tab(char **tab);

// redirections
void				dup_fds(t_list *cmds);
void				close_fds(t_list *cmds);
int					handle_append(t_list *cmd, t_redir red);
int					handle_redout(t_list *cmd, t_redir red);
int					handle_redin(t_list *cmd, t_redir red);
// builtin export
void				check_in_var(char *var, char **new_var,
						t_general *sa, int index);
char				**export_update(char **env, char *var);
int					var_export_check(char *env_var);
void				get_export_env(t_general *sa);
void				double_swap(int i, int j, t_general *sa);
void				solo_export(t_general *sa);
int					ft_export(t_general *sa, char **cmd);
char				**export_split_var(char *arg);
int					check_number_of_wr(char *str, char c);
char				*only_name(char *name, char *arg);
char				*with_value(char **new_var);
int					double_qchek(char *str);

// builtin echo
int					check_n_line(char *line);
int					ft_echo(char **cmd);

// builtin exit
int					ft_exit(char **cmd, t_general *sa);

// builtin unset
int					ft_unset(t_general *sa, char **cmd);

// builtin env
int					ft_env(t_general *sa);

// builtin pwd
int					ft_pwd(void);

//builtin cd
int					ft_cd(t_general *sa, char **cmd);
int					cd_home(t_general *sa);
int					update_oldpwd(t_general *sa);
char				*get_path_env(char *env);
char				*env_join(char *s1, char *s2);
int					remplace_env_var(char **str, int index, char *name);
int					compare_env_var(char *str, char *var);
int					get_env_var(char **env, char *var);

//exuction functions
int					handle_builtins(t_list *cmds, t_general *sa);
int					ex_minishell(t_list *cmd, t_general *sa);
int					is_builtin(char **args);
void				ex_cmd(t_general *sa, t_list *cmd);
int					make_red(t_list *cmd, t_general *sa);
int					ex_builtins(t_list *cmd, t_general *sa);
void				ex_test(t_list *cmd, t_general *sa);
//pipe
int					init_pipe(int num_cmds, int ***fd);
void				ex_pipe(t_list *cmd, t_general *sa, int num_cmds);
void				free_pipe(int **fd, int numb_cmds);
void				st_ex_pipe(t_general *sa);

// heredocument
int					hrdc_expand(char *delimiter);
int					ft_heredoc(t_list *cmds, t_general *sa, t_redir red);
int					hrdc_expand(char *delimiter);
void				write_exp(t_general *sa, char *line, int pipefd[2]);
void				error_fork(void);

// mak
void				pipex(t_list *cmds, t_general *sa);
int					numberof_cmd(t_list *cmds);

// signals
void				handle_sig(int mode);

void				ft_error(char *first, char *arg, char *last);

void				default_fds(t_list *cmds, t_general *sa);
void				ft_handler(int sig);
void				restore_pt(int sig);
void				killo(int sig);
void				init_env_data(t_general *sa, char **envp);
