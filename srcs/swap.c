/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:51:41 by aoutumur          #+#    #+#             */
/*   Updated: 2025/03/13 13:48:08 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "ft_printf/ft_printf.h"

/*
swap the first two elements in the stack
The single pointer allows to access directly the first node
 & swap with the next one
*/
static void	swap(t_list *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->valeur;
	stack->valeur = stack->next->valeur;
	stack->next->valeur = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

void	swap_sa(t_list **stack_a)
{
	swap(*stack_a);
	write(1, "sa\n", 3);
}

void	swap_sb(t_list **stack_b)
{
	swap(*stack_b);
	write(1, "sb\n", 3);
}

void	swap_ss(t_list **stack_a, t_list **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	write(1, "ss\n", 3);
}
