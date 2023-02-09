/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:32:21 by bguillau          #+#    #+#             */
/*   Updated: 2023/02/02 18:43:17 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_two(t_nb **stack, char c)
{
	if (!is_sorted(*stack))
		swap(stack, c);
}

void	sort_three(t_nb **stack, char c)
{
	int	t[3];

	t[0] = (*stack)->val;
	t[1] = (*stack)->next->val;
	t[2] = (*stack)->next->next->val;
	if (is_sorted(*stack))
		return ;
	if (t[0] < t[1] && t[0] < t[2] && t[1] > t[2])
	{
		swap(stack, c);
		rotate(stack, c);
	}
	if (t[0] < t[1] && t[0] > t[2] && t[1] > t[2])
		r_rotate(stack, c);
	if (t[0] > t[1] && t[0] < t[2] && t[1] < t[2])
		swap(stack, c);
	if (t[0] > t[1] && t[0] > t[2] && t[1] > t[2])
	{
		rotate(stack, c);
		swap(stack, c);
	}
	if (t[0] > t[1] && t[0] > t[2] && t[1] < t[2])
		rotate(stack, c);
}

void	sort_four(t_nb **stack_a, t_nb **stack_b)
{
	while (nb_lstsize((*stack_b)) != 2)
	{
		if ((*stack_a)->index == 3 || (*stack_a)->index == 2)
			push_b(stack_a, stack_b);
		else
			rotate(stack_a, 'a');
	}
	invert_sort_two(stack_b, 'b');
	sort_two(stack_a, 'a');
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void	sort_five(t_nb **stack_a, t_nb **stack_b)
{
	while (nb_lstsize((*stack_b)) != 2)
	{
		if ((*stack_a)->index == 3 || (*stack_a)->index == 4)
			push_b(stack_a, stack_b);
		else
			rotate(stack_a, 'a');
	}
	invert_sort_two(stack_b, 'b');
	sort_three(stack_a, 'a');
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void	sort_few(t_nb **stack_a, t_nb **stack_b, int argc)
{
	if (is_sorted(*stack_a))
		return ;
	if (argc == 3)
		sort_two(stack_a, 'a');
	if (argc == 4)
		sort_three(stack_a, 'a');
	if (argc == 5)
		sort_four(stack_a, stack_b);
	if (argc == 6)
		sort_five(stack_a, stack_b);
}
