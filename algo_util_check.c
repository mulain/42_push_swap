/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_util_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:50:54 by wmardin           #+#    #+#             */
/*   Updated: 2022/08/03 09:44:49 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Only checks for order in the stack, not for completion.
A list with nodes of rank 1, 3, 9 would be true.
*/
int	ft_checkifordered(t_list **stack)
{
	t_list	*temp;
	t_list	*node2;
	t_list	*highnode;
	t_list	*lownode;

	highnode = ft_gethighnode(stack);
	lownode = ft_getlownode(stack);
	temp = *stack;
	while (temp)
	{
		if (temp->next)
			node2 = temp->next;
		else
			node2 = *stack;
		if (temp == highnode)
		{
			if (node2 != lownode)
				return (0);
		}
		else if (temp->rank > node2->rank)
			return (0);
		temp = temp->next;
	}
	return (1);
}

/*
Checks whether node 1 should generally - not necessarily directly -
precede node 2.
the first and last nodes are in the correct order
in regard to each other - whether the stack wraps.
Defines variables to make the condition more readable. 
*/
int	ft_generalorder(t_list *node1, t_list *node2, t_list **stack)
{
	t_list	*highnode;
	t_list	*lownode;

	highnode = ft_gethighnode(stack);
	lownode = ft_getlownode(stack);
	if (node1 == lownode && node2 == highnode) //knudling
		return (0);
	if (node1->rank < node2->rank
		|| (node1 == highnode && node2 == lownode))
		return (1);
	return (0);
}
