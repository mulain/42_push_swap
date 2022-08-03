/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helperfunctions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 07:58:12 by wmardin           #+#    #+#             */
/*   Updated: 2022/08/02 09:01:59 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printstack(t_list **stack, char *stackname)
{
	t_list	*temp;
	int		i;
	int		i_max;

	temp = *stack;
	i = 5;
	i_max = i - 1;
	while (i--)
		ft_printf("-");
	ft_printf("Stack %s", stackname);
	while (i++ < i_max)
		ft_printf("-");
	ft_printf("\n");
	while (temp)
	{
		ft_printf("%i\n", temp->rank);
		temp = temp->next;
	}
	while (i--)
		ft_printf("-");
	ft_printf(" End %s ", stackname);
	while (i++ < i_max)
		ft_printf("-");
	ft_printf("\n");
}
