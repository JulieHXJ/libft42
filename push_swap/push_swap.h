/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:17:51 by xhuang            #+#    #+#             */
/*   Updated: 2024/12/07 12:17:53 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack_node
{
	int					data;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	struct s_stack_node	*target;
}						t_stack_node;

int						stack_length(t_stack_node *a);
t_stack_node			*sort_three(t_stack_node *a);
t_stack_node			*sort_stack(t_stack_node *a, t_stack_node *b);
void					free_stack(t_stack_node *a);
char					**new_split(char *s, char c);
void					error_handling(t_stack_node *a);
#endif