/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:23:57 by bguillau          #+#    #+#             */
/*   Updated: 2023/02/01 13:24:21 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap_both(t_nb **stack_a, t_nb **stack_b)
{
	if ((*stack_a && (*stack_a)->next) || (*stack_b && (*stack_b)->next))
	{
		swap(stack_a, 's');
		swap(stack_b, 's');
		ft_fprintf(1, "ss\n");
	}
}

void	rotate_both(t_nb **stack_a, t_nb **stack_b)
{
	if ((*stack_a && (*stack_a)->next) || (*stack_b && (*stack_b)->next))
	{
		rotate(stack_a, 's');
		rotate(stack_b, 's');
		ft_fprintf(1, "rr\n");
	}
}

void	r_rotate_both(t_nb **stack_a, t_nb **stack_b)
{
	if ((*stack_a && (*stack_a)->next) || (*stack_b && (*stack_b)->next))
	{
		r_rotate(stack_a, 's');
		r_rotate(stack_b, 's');
		ft_fprintf(1, "rrr\n");
	}
}
