/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:07:42 by xhuang            #+#    #+#             */
/*   Updated: 2025/01/21 18:00:50 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_envp(t_shell *mini, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	mini->envp = malloc((i + 1) * sizeof(char *));
	if (!mini->envp)
	{
		perror("minishell: malloc");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (envp[i])
	{
		mini->envp[i] = ft_strdup(envp[i]);
		i++;
	}
	mini->envp[i] = NULL;
}

bool	shell_init(t_shell *mini, char **envp)
{
	int	i;

	ft_memset(&mini, 0, sizeof(t_shell));
	if (!mini)
	{
		return (1);
	}
	init_envp(mini, envp);
	// init_dir
	mini->cmdline = NULL;
	mini->token_lst = NULL;
	mini->astree = NULL;
	mini->pid = -1;
	mini->exit_status = 0;
	return (0);
}

void reset_shell(t_shell *mini)
{
    if (!mini)
        return;
    if (mini->cmdline)
        free_ptr(mini->cmdline);
    
}