/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:46:25 by bguillau          #+#    #+#             */
/*   Updated: 2023/02/09 15:46:28 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	invert_sort_two(t_nb **stack, char c)
{
	if (is_sorted(*stack))
		swap(stack, c);
}

int	is_sorted(t_nb *stack)
{
	t_nb	*tmp;

	while (stack->next)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (stack->val > tmp->val)
				return (0);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (1);
}

t_nb	*find_smallst(t_nb *stack_a)
{
	t_nb	*tmp;
	t_nb	*smlst;

	while (stack_a && stack_a->index != -1)
		stack_a = stack_a->next;
	smlst = stack_a;
	while (stack_a && stack_a->index != -1)
		stack_a = stack_a->next;
	tmp = stack_a;
	while (tmp)
	{
		if (smlst->val > tmp->val && tmp->index == -1)
			smlst = tmp;
		tmp = tmp->next;
	}
	return (smlst);
}

void	set_index(t_nb *stack, int argc)
{
	int		idx;
	t_nb	*tmp;

	idx = argc - 1 - 1;
	tmp = stack;
	while (idx > -1)
	{
		tmp = find_smallst(stack);
		if (!tmp)
			return ;
		tmp->index = idx;
		idx--;
	}
}
