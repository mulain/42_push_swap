/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 20:30:25 by wmardin           #+#    #+#             */
/*   Updated: 2022/07/29 07:47:00 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_rotate_a(t_list **stack)
{
	ft_rotate(stack);
	write(1, "ra\n", 3);
}

void	ft_do_rotate_b(t_list **stack)
{
	ft_rotate(stack);
	write(1, "rb\n", 3);
}

void	ft_do_rotate_ab(t_list **stack_a, t_list **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	write(1, "rr\n", 3);
}
