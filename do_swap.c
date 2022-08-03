/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:43:59 by wmardin           #+#    #+#             */
/*   Updated: 2022/07/29 07:47:03 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_swap_a(t_list **stack)
{
	ft_swap(stack);
	write(1, "sa\n", 3);
}

void	ft_do_swap_b(t_list **stack)
{
	ft_swap(stack);
	write(1, "sb\n", 3);
}

void	ft_do_swap_ab(t_list **stack_a, t_list **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	write(1, "ss\n", 3);
}
