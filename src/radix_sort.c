/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:38:40 by bguillau          #+#    #+#             */
/*   Updated: 2023/02/08 15:39:10 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	bits_len(int argc)
{
	int	len;

	len = 0;
	while (argc)
	{
		len++;
		argc /= 2;
	}
	return (len);
}

void	radix_sort(t_nb **stack_a, t_nb **stack_b, int argc)
{
	int	i;
	int	bits;
	int	arg;

	i = 0;
	bits = bits_len(argc);
	while (i < bits)
	{
		arg = argc - 1;
		while (arg--)
		{
			if ((*stack_a)->index >> i & 1)
				push_b(stack_a, stack_b);
			else
				rotate(stack_a, 'a');
		}
		while (nb_lstsize(*stack_b))
			push_a(stack_a, stack_b);
		i++;
	}
}
