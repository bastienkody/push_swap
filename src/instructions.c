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

void	push_a(t_nb **a, t_nb **b)
{
	t_nb	*tmp;

	if (!*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*a);
	*a = tmp;
	ft_fprintf(1, "pa\n");
}

void	push_b(t_nb **a, t_nb **b)
{
	t_nb	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*b);
	*b = tmp;
	ft_fprintf(1, "pb\n");
}

void	swap(t_nb **start, char c)
{
	t_nb	*tmp;

	if (!*start || !(*start)->next)
		return ;
	tmp = (*start)->next;
	(*start)->next = tmp->next;
	tmp->next = (*start);
	*start = tmp;
	if (c == 'a')
		ft_fprintf(1, "sa\n");
	else if (c == 'b')
		ft_fprintf(1, "sb\n");
}

void	rotate(t_nb **start, char c)
{
	t_nb	*tmp;

	if (!*start || !(*start)->next)
		return ;
	tmp = (*start);
	*start = (*start)->next;
	tmp->next = NULL;
	nb_lstadd_back(start, tmp);
	if (c == 'a')
		ft_fprintf(1, "ra\n");
	else if (c == 'b')
		ft_fprintf(1, "rb\n");
}

void	r_rotate(t_nb **start, char c)
{
	t_nb	*tmp;
	t_nb	*tmp2;

	if (!*start || !(*start)->next)
		return ;
	tmp = *start;
	tmp2 = *start;
	*start = nb_lstlast(tmp);
	while (tmp2)
	{
		if (!tmp2->next->next)
		{
			tmp2->next = NULL;
			break ;
		}
		tmp2 = tmp2->next;
	}
	(*start)->next = tmp;
	if (c == 'a')
		ft_fprintf(1, "rra\n");
	else if (c == 'b')
		ft_fprintf(1, "rrb\n");
}
