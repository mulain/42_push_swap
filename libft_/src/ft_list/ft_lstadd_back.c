/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:31:23 by wmardin           #+#    #+#             */
/*   Updated: 2022/06/10 23:02:59 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
lst: The address of a pointer to the first link of a list.
new: The address of a pointer to the node to be added to the list.
return: none.
Adds the node ’new’ at the end of the list.

	if (!*lst)			list is empty
		*lst = new;		node new is the only node in the list now
	else
		(ft_lstlast(*lst))->next = new;		list is populated so the old
											last node now points to new
*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	if (!*lst)
		*lst = new;
	else
		(ft_lstlast(*lst))->next = new;
}
