/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:17:01 by xhuang            #+#    #+#             */
/*   Updated: 2024/12/07 12:17:10 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(char *s)
{
}

int	cmd_error(char *s)
{
}

int	is_dup(t_stack_node *a, int n)
{
}

/*
handle the input: if input are seperated arguments or is a string
*/
void	append_stack(t_stack_node a, int n)
{
	t_stack_node	*a;

	else
	{
		while (av[i])
		{
			a->data = av[i];
			a = a->next;
			i++;
		}
	}
	return (a);
}

/*
check input arguments or string only contain digits, '-' and '+';
handle overflow, duplicates, syntax error, string to long integer
*/
int	check_args(char **av)
{
	long	nbr;
	int		i;

	i = 0;
	while (av[i])
	{
		if (cmd_error(av[i]))
		{
			error_handling(a);
		}
		nbr = ft_atol(av[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
		{
			error_handling(a);
		}
		if (is_dup(&a, (int)nbr))
		{
			/* code */
		}
		append_stack(a, (int)nbr);
		i++;
	}
}

/*
check if stack a is already in right order
*/
int	is_sorted(t_stack_node *a)
{
}