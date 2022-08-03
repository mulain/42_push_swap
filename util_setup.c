/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:56:59 by wmardin           #+#    #+#             */
/*   Updated: 2022/07/20 13:20:44 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isofintsize(char *argv)
{
	int		len;

	len = ft_strlen(argv);
	if (len > 11)
		return (0);
	if (argv[0] == '-')
	{
		if (len == 11)
		{
			if (ft_strncmp("-2147483648", argv, 69) < 0)
				return (0);
		}
		return (1);
	}
	if (len == 11)
		return (0);
	if (len == 10)
	{
		if (ft_strncmp("2147483647", argv, 420) < 0)
			return (0);
	}
	return (1);
}

int	ft_checkduplicate(int *ints, int argcm1)
{
	int		i;
	int		j;

	i = 0;
	while (i + 1 < argcm1)
	{
		j = i + 1;
		while (j < argcm1)
		{
			if (ints[i] == ints[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	*ft_makeintarray(int argc, char **argv)
{
	int		i;
	int		*ints;

	i = 1;
	ints = malloc((argc - 1) * sizeof(int));
	while (i < argc)
	{
		if (!ft_isnumberformat(argv[i]) || !ft_isofintsize(argv[i]))
		{
			free(ints);
			return (NULL);
		}
		ints[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	if (!ft_checkduplicate(ints, argc - 1))
	{
		free(ints);
		return (NULL);
	}
	return (ints);
}

t_list	*ft_makestack_a(int argc, char **argv)
{
	int		i;
	int		*ints;
	t_list	*stack_a;

	i = 0;
	stack_a = NULL;
	ints = ft_makeintarray(argc, argv);
	if (!ints)
		return (NULL);
	while (i < argc - 1)
	{
		ft_lstadd_back(&stack_a, ft_lstnew(ints[i]));
		i++;
	}
	ft_assignrank(&stack_a, argc);
	free(ints);
	return (stack_a);
}

void	ft_free_stack(t_list **stack)
{
	t_list	*temp1;
	t_list	*temp2;

	temp1 = *stack;
	while (temp1)
	{
		temp2 = temp1;
		temp1 = temp1->next;
		free(temp2);
	}
}
