/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:42:13 by bguillau          #+#    #+#             */
/*   Updated: 2023/02/09 17:35:27 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_nb	*stack_a;
	t_nb	*stack_b;

	if (argc < 2 || checker(argc, argv))
		return (1);
	stack_a = nb_to_list(argc, argv);
	if (!stack_a)
		return (1);
	stack_b = NULL;
	if (!is_sorted(stack_a))
	{
		if (argc < 7)
			sort_few(&stack_a, &stack_b, argc);
		else
			radix_sort(&stack_a, &stack_b, argc);
	}
	nb_lstclear(&stack_a);
	nb_lstclear(&stack_b);
}
