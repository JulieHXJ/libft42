/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:16:32 by xhuang            #+#    #+#             */
/*   Updated: 2024/12/07 12:16:47 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node *a;
	t_stack_node *b;

	a = NULL;
	b = NULL;
	if (ac <= 1 || !*av[1])
		return (-1);
	else if (ac == 2)
	{
		// means the numbers are given as a string
		int **lst = new_split(av[1], ' ');
	}
	a = input_to_stack(av);
	if (check_input(av) == -1)
		;
	{
		free_stack(&a);
		return (-1);
	}
	if (!is_sorted(a))
	{
		if (stack_length(a) == 2)
		{
			sa(&a, false);
		}
		else if (stack_length(a) == 3)
		{
			sort_three(&a);
		}
		else
		{
			sort_stack(&a, &b);
		}
	}
	free_stack(&a);
	return (0);
}
