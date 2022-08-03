/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:11:04 by wmardin           #+#    #+#             */
/*   Updated: 2022/07/29 07:46:14 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **stack)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	if (ft_lstsize(*stack) < 2)
		return ;
	node1 = *stack;
	node2 = node1->next;
	node3 = node2->next;
	*stack = node2;
	node2->next = node1;
	node1->next = node3;
}

void	ft_push(t_list **stack_from, t_list **stack_to)
{
	t_list	*node1;
	t_list	*node2;

	if (!*stack_from)
		return ;
	node1 = *stack_from;
	node2 = node1->next;
	ft_lstadd_front(stack_to, node1);
	*stack_from = node2;
}

void	ft_rotate(t_list **stack)
{
	t_list	*node1;
	t_list	*node2;

	node1 = *stack;
	node2 = node1->next;
	ft_lstadd_back(stack, node1);
	node1->next = NULL;
	*stack = node2;
}

void	ft_revrotate(t_list **stack)
{
	t_list	*nodebeforelast;

	nodebeforelast = *stack;
	while (nodebeforelast->next->next)
		nodebeforelast = nodebeforelast->next;
	ft_lstadd_front(stack, ft_lstlast(*stack));
	nodebeforelast->next = NULL;
}
