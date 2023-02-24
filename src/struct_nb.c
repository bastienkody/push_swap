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

t_nb	*nb_lstnew(int val)
{
	t_nb	*ptr;

	ptr = malloc(sizeof(t_nb));
	if (!ptr)
		return (NULL);
	ptr->val = val;
	ptr->index = -1;
	ptr->next = NULL;
	return (ptr);
}

t_nb	*nb_lstlast(t_nb *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	nb_lstadd_back(t_nb **lst, t_nb *new)
{
	t_nb	*ptr;

	if (!new)
		return ;
	if (lst)
	{
		if (!*lst)
		{
			*lst = new;
			return ;
		}
		ptr = nb_lstlast(*lst);
		ptr->next = new;
	}
}

void	nb_lstclear(t_nb **lst)
{
	t_nb	*tmp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

void	nb_lstprint(t_nb *lst)
{
	while (lst)
	{
		ft_fprintf(1, "val:%i\n", lst->val);
		lst = lst->next;
	}
}
