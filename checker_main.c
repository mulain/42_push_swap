/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 14:14:19 by wmardin           #+#    #+#             */
/*   Updated: 2022/08/06 09:09:23 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Double writes "Error" if push_swap is piped into checker without pipe
modification. This is because push_swap writes on the stderr (fd2).
To only get one "Error", combine outputs via 2>&1, e.g.:
ARG="1 3 2 4 2"; ./push_swap $ARG 2>&1 | ./checker $ARG
42 checker also behaves this way.
*/
int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*instruction;
	int		invalidcmd;

	invalidcmd = 0;
	if (argc < 3)
		return (1);
	stack_a = ft_makestack_a(argc, argv);
	if (!stack_a)
		return (ft_failstack_a());
	instruction = get_next_line(0);
	stack_b = NULL;
	while (instruction)
	{
		invalidcmd = ft_do(instruction, &stack_a, &stack_b);
		if (invalidcmd)
			return (ft_invalidcmd(&stack_a, &stack_b, instruction));
		free (instruction);
		instruction = get_next_line(0);
	}
	ft_finalcheck(stack_a, stack_b, argc);
	ft_freeall(&stack_a, &stack_b, instruction);
}

int	ft_failstack_a(void)
{
	write(2, "Error\n", 6);
	return (1);
}

void	ft_finalcheck(t_list *stack_a, t_list *stack_b, int argc)
{
	if (stack_a && !stack_b)
	{
		if (stack_a->rank == 1 && ft_lstlast(stack_a)->rank == argc - 1
			&& ft_checkifordered(&stack_a))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	else
		write(1, "KO\n", 3);
}

void	ft_freeall(t_list **stack_a, t_list **stack_b, char *instruction)
{
	if (instruction)
		free(instruction);
	if (*stack_a)
		ft_free_stack(stack_a);
	if (*stack_b)
		ft_free_stack(stack_b);
}
