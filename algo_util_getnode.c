/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_util_getnode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:31:50 by wmardin           #+#    #+#             */
/*   Updated: 2022/11/12 21:04:30 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Returns the node with the highest rank in the stack.
*/
t_list	*ft_gethighnode(t_list **stack)
{
	t_list	*temp;
	t_list	*save;

	temp = *stack;
	save = temp;
	while (temp)
	{
		if (temp->rank > save->rank)
			save = temp;
		temp = temp->next;
	}
	return (save);
}

/*
Returns the node with the lowest rank in the stack.
*/
t_list	*ft_getlownode(t_list **stack)
{
	t_list	*temp;
	t_list	*save;

	temp = *stack;
	save = temp;
	while (temp)
	{
		if (temp->rank < save->rank)
			save = temp;
		temp = temp->next;
	}
	return (save);
}

/*
Returns the node that should be at the top of
stack_a so the node with rank <noderank> will be in the
correct order in stack_a after having been moved there.
*/
t_list	*ft_getinsertionnode(t_list **stack, int noderank)
{
	t_list	*temp;
	t_list	*save;
	t_list	*highnode;
	t_list	*lownode;

	temp = *stack;
	highnode = ft_gethighnode(stack);
	lownode = ft_getlownode(stack);
	if (noderank > highnode->rank || noderank < lownode->rank)
		return (lownode);
	while (noderank > temp->rank)
		temp = temp->next;
	save = temp;
	while (temp)
	{
		if (noderank < temp->rank && temp->rank < save->rank)
			save = temp;
		temp = temp->next;
	}
	return (save);
}
