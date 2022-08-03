/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_revrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 20:54:59 by wmardin           #+#    #+#             */
/*   Updated: 2022/07/29 07:46:56 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_revrotate_a(t_list **stack)
{
	ft_revrotate(stack);
	write(1, "rra\n", 4);
}

void	ft_do_revrotate_b(t_list **stack)
{
	ft_revrotate(stack);
	write(1, "rrb\n", 4);
}

void	ft_do_revrotate_ab(t_list **stack_a, t_list **stack_b)
{
	ft_revrotate(stack_a);
	ft_revrotate(stack_b);
	write(1, "rrr\n", 4);
}
