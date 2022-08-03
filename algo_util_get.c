/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_util_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 21:10:34 by wmardin           #+#    #+#             */
/*   Updated: 2022/08/03 09:55:06 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Returns the position of the node in the stack.
The first node is defined as node 1, not node 0.
*/
int	ft_getnodeposition(t_list *node, t_list **stack)
{
	t_list	*temp;
	int		counter;

	counter = 1;
	temp = *stack;
	while (temp != node)
	{
		temp = temp->next;
		counter++;
	}
	return (counter);
}

/*
Returns the position of the node with the passed rank in the stack.
The first node is defined as node 1, not node 0.
*/
int	ft_getnoderankposition(int rank, t_list **stack)
{
	t_list	*temp;
	int		counter;

	counter = 1;
	temp = *stack;
	while (temp->rank != rank)
	{
		temp = temp->next;
		counter++;
	}
	return (counter);
}

/*
0 -> don't rotate
1 -> rotate
2 -> revrotate
*/
int	ft_getrotatedir(t_list **stack, int noderank)
{
	t_list	*temp;
	int		counter;

	counter = 0;
	temp = *stack;
	if ((*stack)->rank == noderank)
		return (0);
	while (temp->rank != noderank)
	{
		counter++;
		temp = temp->next;
	}
	if (counter <= ft_lstsize(*stack) - counter)
		return (1);
	return (2);
}
