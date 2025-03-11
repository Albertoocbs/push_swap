/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:51:56 by aoutumur          #+#    #+#             */
/*   Updated: 2025/03/10 17:24:00 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "ft_printf/ft_printf.h"

/*
Pushes the top element of src_stack to the top of dest_stack
*/
static void	push(t_list **src_stack, t_list **dest_stack)
{
	t_list	*tmp;

	if (!src_stack || !*src_stack)
		return ;
	tmp = *src_stack;
	*src_stack = (*src_stack)->next;
	tmp->next = *dest_stack;
	*dest_stack = tmp;
}

/*
push top element of stack b to the top of stack a
*/
void	push_pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

/*
push top element of stack a to the top of stack b
*/
void	push_pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
