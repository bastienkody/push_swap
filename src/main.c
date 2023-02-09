/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:42:13 by bguillau          #+#    #+#             */
/*   Updated: 2023/01/26 12:07:56 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_both_stacks(t_nb *stack_a, t_nb *stack_b)
{
	ft_fprintf(1, "Both stacks\n");
	ft_fprintf(1, "stack_a\n");
	nb_lstprint(stack_a);
	ft_fprintf(1, "stack_b\n");
	nb_lstprint(stack_b);
	ft_fprintf(1, "End of both stacks\n");
	ft_fprintf(1, "------------------\n");
}

void	print_index(t_nb *lst)
{
	while (lst)
	{
		ft_fprintf(1, "val:%i, idx:%i\n", lst->val, lst->index);
		lst = lst->next;
	}
}

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
