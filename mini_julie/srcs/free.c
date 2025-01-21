/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:57:51 by xhuang            #+#    #+#             */
/*   Updated: 2025/01/21 18:09:21 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_ptr(char *s)
{
	if (s != NULL)
	{
		free(s);
		s = NULL;
	}
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}

void	free_token(t_token *token)
{
	t_token	*current;

	current = token;
	while (current)
	{
		if (current->type)
			free(current->type);
		if (current->str)
			free_ptr(current->str);
		free(current);
		current = current->next;
	}
	token = NULL;
}

void	free_cmd(void)
{
}

void	free_shell(t_shell *mini)
{
	if (!mini)
		return ;
	reset_shell(mini);
	if (mini->envp)
		free_arr(mini->envp);
}
