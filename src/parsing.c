/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:14:28 by bguillau          #+#    #+#             */
/*   Updated: 2023/01/26 17:56:22 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* check : non digit -->return(1) && int overflow -->exit(FAILURE) */
int	checker(int argc, char **argv)
{
	int	i;
	int	tmp;

	tmp = argc;
	while (--tmp > 0)
	{
		i = 0;
		while (argv[tmp][i])
		{
			if (i == 0 && (argv[tmp][i] == '+' || argv[tmp][i] == '-'))
				i++;
			if (!ft_isdigit(argv[tmp][i++]))
			{
				ft_fprintf(2, "Error\n");
				return (1);
			}
		}
		ft_atoi_novflw(argv[tmp]);
	}
	return (0);
}

/* nb to llist + set index (0==biggest) + free list return NULL if duplicate*/
t_nb	*nb_to_list(int argc, char **argv)
{
	t_nb	*start;
	t_nb	*nb;
	int		arg;

	arg = argc;
	start = nb_lstnew(ft_atoi(*(++argv)));
	if (!start)
		return (NULL);
	while (--argc > 1)
	{
		nb = nb_lstnew(ft_atoi(*(++argv)));
		if (!nb)
			nb_lstclear(&start);
		nb_lstadd_back(&start, nb);
	}
	if (check_duplicate(arg, start))
	{
		nb_lstclear(&start);
		return (NULL);
	}
	set_index(start, arg);
	return (start);
}

int	check_duplicate(int argc, t_nb *start)
{
	t_nb	*tmp;

	while (--argc > 1)
	{
		tmp = start->next;
		while (tmp)
		{
			if (start->val == tmp->val)
			{
				ft_fprintf(2, "Error\n");
				return (1);
			}
			tmp = tmp->next;
		}
		start = start->next;
	}
	return (0);
}
