/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:59:26 by xhuang            #+#    #+#             */
/*   Updated: 2025/01/21 18:00:19 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int parse_input(t_shell *mini)
{
	//function takes input and return token list
	mini->token_lst = tokenize_input(mini->cmdline);
	if (!mini->token_lst)
	{
		return (1);
	}
	
	mini->astree = token_to_tree(mini->token_lst);
	if (!mini->astree)
	{
		free_token(mini->token_lst);
	}
	
	expandor(mini->astree, mini->envp);
	free_token(mini->token_lst);
	return(0);
}

void execute_cmd(t_tree *ast, char **envp)
{
	//todo
	// t_command *current = cmd_lst;

    // while (current)
    // {
    //     // Example execution logic
    //     if (fork() == 0)
    //     {
    //         // In child process
    //         if (execve(current->cmd, current->args, envp) == -1)
    //         {
    //             perror("minishell");
    //             exit(EXIT_FAILURE);
    //         }
    //     }
    //     else
    //     {
    //         // In parent process, wait for the child
    //         wait(NULL);
    //     }
    //     current = current->next;
    // }
}

int main(int ac, char **av, char **envp)
{
	t_shell minishell;
	
	if (ac != 1 || av[1])
		return (ft_printf("Input format: ./minishell\n"), 1);
	if (shell_init(&minishell, envp) == 0)
	{
		while (1)
		{
			sig_ignore();//handle ctrl+\ and ctul+c
			minishell.cmdline = readline(PROMPT);
			if (!minishell.cmdline)
			{
				//EOF
				ft_printf("Failed to read command line.\n");
				break;
			}
			if (*minishell.cmdline)
			{
				add_history(minishell.cmdline);
				if (parse_input(&minishell) == 0)
					execute_cmd(minishell.astree, envp);
			}
			reset_shell(&minishell);
		}
		exit_shell();//free_shell() included;
	}
	else
		exit_shell();
	return(0);
}
