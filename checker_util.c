/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 08:57:09 by wmardin           #+#    #+#             */
/*   Updated: 2022/08/04 21:35:18 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_invalidcmd(t_list **stack_a, t_list **stack_b, char *instruction)
{
	write(2, "Error: invalid cmd\n", 19);
	ft_freeall(stack_a, stack_b, instruction);
	return (1);
}

/*
Check for and perform operations:
	-	swap
	-	push
*/
int	ft_do(char *instruction, t_list **stack_a, t_list **stack_b)
{
	if (ft_strncmp(instruction, "sa\n", 4) == 0)
		ft_swap(stack_a);
	else if (ft_strncmp(instruction, "sb\n", 4) == 0)
		ft_swap(stack_b);
	else if (ft_strncmp(instruction, "ss\n", 4) == 0)
	{
		ft_swap(stack_a);
		ft_swap(stack_b);
	}
	else if (ft_strncmp(instruction, "pa\n", 4) == 0)
		ft_push(stack_b, stack_a);
	else if (ft_strncmp(instruction, "pb\n", 4) == 0)
		ft_push(stack_a, stack_b);
	else
		return (ft_do1(instruction, stack_a, stack_b));
	return (0);
}

/*
Check for and perform operations:
	-	rotate
*/
int	ft_do1(char *instruction, t_list **stack_a, t_list **stack_b)
{
	if (ft_strncmp(instruction, "ra\n", 4) == 0)
		ft_rotate(stack_a);
	else if (ft_strncmp(instruction, "rb\n", 4) == 0)
		ft_rotate(stack_b);
	else if (ft_strncmp(instruction, "rr\n", 4) == 0)
	{
		ft_rotate(stack_a);
		ft_rotate(stack_b);
	}
	else
		return (ft_do2(instruction, stack_a, stack_b));
	return (0);
}

/*
Check for and perform operations:
	-	rotate
If no operation was found: return invalid cmd error.
*/
int	ft_do2(char *instruction, t_list **stack_a, t_list **stack_b)
{
	if (ft_strncmp(instruction, "rra\n", 5) == 0)
		ft_revrotate(stack_a);
	else if (ft_strncmp(instruction, "rrb\n", 5) == 0)
		ft_revrotate(stack_b);
	else if (ft_strncmp(instruction, "rrr\n", 5) == 0)
	{
		ft_revrotate(stack_a);
		ft_revrotate(stack_b);
	}
	else
		return (1);
	return (0);
}
