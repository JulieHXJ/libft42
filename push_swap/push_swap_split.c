/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:17:38 by xhuang            #+#    #+#             */
/*   Updated: 2024/12/07 12:17:40 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int word_count(char *s, char c)
{
	int wc;
	int	sign;

	wc = 0;
	sign = 0;
	while (*s)
	{
		if (*s != c && sign != 1)
		{
			wc++;
			sign = 1;
		}
		else if (*s == c)
			sign = 0;
		s++;
	}
	return (wc);


}

static char *get_next_word(char *s, char c)
{
	char *word;
	int len = 0;
	static int i = 0;
	int j = 0;
	while (s[i] == c)
	{
		++i;
	}
	while (s[i + len] && (s[i + len] != c))
	{
		++len;
	}
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
	{
		return (NULL);
	}
	while (s[i] && s[i] != c)
	{
		word[j++] = s[i++];
	}
	word[j] = '\0';
	return (word);
}

char **new_split(char *s, char c)
{
	int wc;
	char **arr;
	int i;
	
	i = 1;
	wc = word_count(s, c);
	arr = malloc(sizeof(char *) * (wc + 2));
	if (!arr)
	{
		return (NULL);
	}
	arr[0] = malloc(sizeof(char) * 1);
	if (!arr[0])
	{
		return (NULL);
	}
	arr[0][0] = '\0';

	while (wc-- >= 1)
	{
		arr[i++] == get_next_word(s, c);
	}
	arr[i] = NULL;
	return (arr);
	
}