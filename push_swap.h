/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:58:14 by wmardin           #+#    #+#             */
/*   Updated: 2022/08/04 22:52:08 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include "libft/include/libft.h"

//main
void	ft_finalrotation(t_list **stack);

//helperfunctions
void	ft_printstack(t_list **stack, char *stackname);

//util_setup
int		*ft_makeintarray(int argc, char **argv);
int		ft_checkduplicate(int *ints, int argc);
int		ft_isofintsize(char *argv);
t_list	*ft_makestack_a(int argc, char **argv);
void	ft_free_stack(t_list **stack);

//util_assignrank
void	ft_assignrank(t_list **stack_a, int argc);
t_list	*ft_getfirstunranked(t_list **stack);

//algo_util_check
int		ft_checkifordered(t_list **stack);
int		ft_generalorder(t_list *node1, t_list *node2, t_list **stack);

//algo_slices
void	ft_algo_slices(t_list **stack_a, t_list **stack_b, int len_stack);
int		ft_getslices(int stacksize);
void	ft_pushslice(t_list **stack_a, t_list **stack_b,
			int len_stack, int slice_i);
void	ft_returntoa(t_list **stack_a, t_list **stack_b);
void	ft_selectanddo(t_list **stack_a, t_list **stack_b,
			int rotate_a, int rotate_b);

//algo_util_get
int		ft_getnodeposition(t_list *node, t_list **stack);
int		ft_getnoderankposition(int rank, t_list **stack);
int		ft_getrotatedir(t_list **stack, int noderank);

//algo_util_getnode
t_list	*ft_gethighnode(t_list **stack);
t_list	*ft_getlownode(t_list **stack);
t_list	*ft_getinsertionnode(t_list **stack, int noderank);

//algo_util_calc
int		ft_calc_actions(t_list **stack_a, t_list **stack_b, t_list *nodefromb);
int		ft_calc_movetotop(t_list **stack, t_list *node);

//checker_main
int		ft_failstack_a(void);
void	ft_finalcheck(t_list *stack_a, t_list *stack_b, int argc);
void	ft_freeall(t_list **stack_a, t_list **stack_b, char *instruction);

//checker_util
int		ft_do(char *instruction, t_list **stack_a, t_list **stack_b);
int		ft_do1(char *instruction, t_list **stack_a, t_list **stack_b);
int		ft_do2(char *instruction, t_list **stack_a, t_list **stack_b);
int		ft_invalidcmd(t_list **stack_a, t_list **stack_b, char *instruction);

//util_operations
void	ft_swap(t_list **stack);
void	ft_push(t_list **stack_from, t_list **stack_to);
void	ft_rotate(t_list **stack);
void	ft_revrotate(t_list **stack);

//do* files
void	ft_do_swap_a(t_list **stack);
void	ft_do_swap_b(t_list **stack);
void	ft_do_swap_ab(t_list **stack_a, t_list **stack_b);

void	ft_do_push_a(t_list **stack_a, t_list **stack_b);
void	ft_do_push_b(t_list **stack_a, t_list **stack_b);

void	ft_do_rotate_a(t_list **stack);
void	ft_do_rotate_b(t_list **stack);
void	ft_do_rotate_ab(t_list **stack_a, t_list **stack_b);

void	ft_do_revrotate_a(t_list **stack);
void	ft_do_revrotate_b(t_list **stack);
void	ft_do_revrotate_ab(t_list **stack_a, t_list **stack_b);

#endif