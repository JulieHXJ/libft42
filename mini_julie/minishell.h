/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:01:39 by xhuang            #+#    #+#             */
/*   Updated: 2025/01/21 18:13:45 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// Prompt string
# define PROMPT "Mini-julie;) >$ "

typedef struct s_token
{
	int type;  // Token type (e.g., CMD, WORD, PIPE, etc.)
	char *str; // String value of the token
	struct s_token	*next;
	struct s_token	*prev;
}					t_token;

// Struct for a syntx tree
typedef struct s_tree
{
	char *cmd;              // Command name
	char **args;            // Command arguments
	char *infile;           // Input redirection file
	char *outfile;          // Output redirection file
	bool is_piped;          // Is the command piped to the next
	struct s_command *next; // Pointer to the next command in the pipeline
	struct s_command *prev; // Pointer to the previous command
}					t_tree;

// Struct for input/output redirection (can be expanded as needed)
typedef struct s_redir
{
	int				inp_fd;
	int				out_fd;
	int				pipe_fd[2];
	bool			here_doc;
}					t_redir;

typedef struct s_shell
{
	char			*cmdline;
	t_tree			*astree;
	t_token			*token_lst;
	pid_t			pid;
	char			**envp;
	char			*cur_dir;
	char			*old_dir;
	int				exit_status;
}					t_shell;

// Enumeration for token types
typedef enum e_token_type
{
	CMD = 0,      // Command
	WORD,         // Word (argument or file)
	VAR,          // Variable(e.g., $HOME)
	PIPE,         // (|)
	REDIRECT_IN,  // (<)
	REDIRECT_OUT, // (>)
	HERE_DOC,     // (<<)
	APPEND,       // (>>)
	END
}					t_token_type;

// ---------------------Initialization--------------------
bool				shell_init(t_shell *mini, char **envp);
void				reset_shell(t_shell *mini);
// init_envp
// init_dir
// init_cmd
// init_token

// -------------------------Parsing------------------------
t_token				*tokenize_input(const char *cmdline);
t_tree				*token_to_tree(t_token *tokens);
void				expand_tokens(t_token *tokens, char **envp);
void				expand_variable(t_token *token, char **envp);

// Token_list utils
t_token				*create_token(int type, char *str);
void				free_token(t_token *tokens);

// ASTree utils
t_command			*create_command(void);
void				free_commands(t_command *cmd_lst);

// ------------------------Execution-----------------------
void				execute_commands(t_shell *shell);

// ---------------------Signal handling--------------------
void				setup_signals(void);
void				reset_signals(void);

// ----------------------Error and free--------------------
void				free_shell(t_shell *shell);
void				free_ptr(char *s);
void				print_error(const char *msg);
void				handle_syntax_error(const char *token);

#endif
