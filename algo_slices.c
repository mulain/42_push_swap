/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_slices.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:47:21 by wmardin           #+#    #+#             */
/*   Updated: 2022/08/03 10:09:30 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Stack_a is divided into slices depending on its size. Only the lowest elements
from stack_a - whose ranks are within the slice size - are pushed to stack_b.
Empirically, the best solution appears to be to add a slice starting from
n = 64 stack elements, then adding a slice every time n doubles.
E.g.: n = 128 to 255 -> 2 slices; n = 256 to 511 -> 3 slices, etc.
The last slice can be larger than the others (up to slices - 1), because
dividing in ints. The extra nodes land in the last slice.
*/
void	ft_algo_slices(t_list **stack_a, t_list **stack_b, int stacksize)
{
	int		slices;
	int		slicesize;
	int		i;

	i = 1;
	slices = ft_getslices(stacksize);
	slicesize = stacksize / slices;
	while (slices > 1)
	{
		ft_pushslice(stack_a, stack_b, stacksize, slicesize * i);
		i++;
		slices--;
	}
	while (ft_lstsize(*stack_a) > 3)
	{
		ft_do_push_b(stack_a, stack_b);
	}
	if (!ft_checkifordered(stack_a))
		ft_do_swap_a(stack_a);
	ft_returntoa(stack_a, stack_b);
}

int	ft_getslices(int stacksize)
{
	int		i;
	int		slices;

	i = 2;
	slices = 1;
	while (64 * i <= stacksize)
	{
		i *= 2;
		slices++;
	}
	return (slices);
}

void	ft_pushslice(t_list **stack_a, t_list **stack_b,
	int stacksize, int slice_i)
{
	while (ft_lstsize(*stack_a) > stacksize - slice_i)
	{
		if ((*stack_a)->rank <= slice_i)
			ft_do_push_b(stack_a, stack_b);
		else
			ft_do_rotate_a(stack_a);
	}
}

/*
Returns the nodes to stack_a.
Selects the node with the least actions necessary to be pushed
to a. Takes combo moves into account.
*/
void	ft_returntoa(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	t_list	*target_a;
	t_list	*target_b;

	while (*stack_b)
	{
		temp = *stack_b;
		target_b = temp;
		while (temp)
		{
			if (ft_calc_actions(stack_a, stack_b, temp)
				< ft_calc_actions(stack_a, stack_b, target_b))
				target_b = temp;
			temp = temp->next;
		}
		target_a = ft_getinsertionnode(stack_a, target_b->rank);
		while (*stack_a != target_a || *stack_b != target_b)
			ft_selectanddo(stack_a, stack_b,
				ft_getrotatedir(stack_a, target_a->rank),
				ft_getrotatedir(stack_b, target_b->rank));
		ft_do_push_a(stack_a, stack_b);
	}
}

void	ft_selectanddo(t_list **stack_a, t_list **stack_b,
	int rotate_a, int rotate_b)
{
	if (rotate_a == 1 && rotate_b == 1)
		ft_do_rotate_ab(stack_a, stack_b);
	else if (rotate_a == 2 && rotate_b == 2)
		ft_do_revrotate_ab(stack_a, stack_b);
	else
	{
		if (rotate_a == 1)
			ft_do_rotate_a(stack_a);
		if (rotate_a == 2)
			ft_do_revrotate_a(stack_a);
		if (rotate_b == 1)
			ft_do_rotate_b(stack_b);
		if (rotate_b == 2)
			ft_do_revrotate_b(stack_b);
	}
}
