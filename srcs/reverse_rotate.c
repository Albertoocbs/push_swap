/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:51:53 by aoutumur          #+#    #+#             */
/*   Updated: 2025/03/05 16:16:27 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "ft_printf/ft_printf.h"

/*
* The bottom element of the stack is sent to the top
before_last->next = NULL; isolates the last element, in other words we dont
point anymore to the last node but to null
so we "eliminate the last node and make the before_last the last node".
Then we make the last node point to the first node in the stack
and finally we make the last node the first node in the stack
which points to the first and the rest of the nodes
*/
static void	reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*before_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = *stack;
	before_last = NULL;
	while (last->next != NULL)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rev_rotate_rra(t_list **stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rev_rotate_rrb(t_list **stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rev_rotate_rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
