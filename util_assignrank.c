/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_assignrank.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 11:32:52 by wmardin           #+#    #+#             */
/*   Updated: 2022/08/03 09:59:12 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Returns the first node in a stack whose rank has not yet
been modified. This corresponds to rank = -1, because rank is
initialized to -1 in ft_lst_new.
*/
t_list	*ft_getfirstunranked(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	while (temp)
	{
		if (temp->rank == -1)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

/*
Assigns ranks based on the ascending values of node content.
i is initialized to 1 and not 0 because the last node is
not reached during the while loop and therefore shouldn't
be included in the the while's condition count.
*/
void	ft_assignrank(t_list **stack, int argc)
{
	int		i;
	t_list	*temp;
	t_list	*currentranked;

	i = 1;
	while (i < argc - 1)
	{
		currentranked = ft_getfirstunranked(stack);
		currentranked->rank = i;
		temp = currentranked->next;
		while (temp)
		{
			if (temp->rank == -1 && currentranked->content > temp->content)
			{
				temp->rank = i;
				currentranked->rank = -1;
				currentranked = temp;
			}
			temp = temp->next;
		}
	i++;
	}
	ft_getfirstunranked(stack)->rank = i;
}
