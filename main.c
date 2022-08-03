/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:04:38 by wmardin           #+#    #+#             */
/*   Updated: 2022/08/03 09:31:57 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 3)
		return (1);
	stack_a = ft_makestack_a(argc, argv);
	if (!stack_a)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stack_b = NULL;
	ft_algo_slices(&stack_a, &stack_b, argc - 1);
	ft_finalrotation(&stack_a);
	ft_free_stack(&stack_a);
}

void	ft_finalrotation(t_list **stack)
{
	if (ft_getrotatedir(stack, 1) == 1)
	{
		while ((*stack)->rank != 1)
			ft_do_rotate_a(stack);
	}
	else if (ft_getrotatedir(stack, 1) == 2)
	{
		while ((*stack)->rank != 1)
			ft_do_revrotate_a(stack);
	}
}
