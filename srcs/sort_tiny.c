/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:21:46 by aoutumur          #+#    #+#             */
/*   Updated: 2025/03/13 13:48:07 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "ft_printf/ft_printf.h"

int	ft_list_size(t_list *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

/*
	If stack is empty or only has one element returns 1, nothing to sort.
	Loop through stack_a and compare them. If value greater than next one,
	then return 0 cause is not sorted and move to next element.
	If loop completes without issues, means that is sorted, then return 1
*/
int	check_sorted(t_list *stack)
{
	if (stack == NULL || stack->next == NULL)
		return (1);
	while (stack && stack->next)
	{
		if (stack->valeur > stack->next->valeur)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/* Sorting function for cases with 3 elements in max 2 mouvements:
	Case 1 : [1, 2, 3] (already sorted)
	Case 2 : [2, 1, 3] sa
	Case 3 : [1, 3, 2] sa & ra
	Case 4 : [2, 3, 1] rra
	Case 5 : [3, 1, 2] ra
	Case 6 : [3, 2, 1] sa et rra
*/
void	sort_3nbr(t_list **stack)
{
	int	num1;
	int	num2;
	int	num3;

	num1 = (*stack)->valeur;
	num2 = (*stack)->next->valeur;
	num3 = (*stack)->next->next->valeur;
	if (ft_list_size(*stack) < 3 || check_sorted(*stack))
		return ;
	else if (num1 > num2 && num1 < num3)
		swap_sa(stack);
	else if (num1 < num2 && num2 > num3 && num1 < num3)
	{
		swap_sa(stack);
		rotate_ra(stack);
	}
	else if (num1 < num2 && num2 > num3 && num1 > num3)
		rev_rotate_rra(stack);
	else if (num1 > num2 && num2 < num3 && num1 > num3)
		rotate_ra(stack);
	else if (num1 > num2 && num2 > num3)
	{
		swap_sa(stack);
		rev_rotate_rra(stack);
	}
}

void	sort_4nbr(t_list **stack_a, t_list **stack_b)
{
	if (check_sorted(*stack_a))
		return ;
	while (ft_list_size(*stack_a) > 3)
	{
		if ((*stack_a)->index == 0)
			push_pb(stack_a, stack_b);
		else
			rotate_ra(stack_a);
	}
	sort_3nbr(stack_a);
	push_pa(stack_a, stack_b);
}

/*
Check if is sorted calling check_sorted function
if index is one of the two smallest then push to stack_b, otherwise,
rotate until we push both, then when stack_a has just 3 elements call sort_3nbr
and then push back from stac_b to stack_a the indexes min2 and min1
*/
void	sort_5nbr(t_list **stack_a, t_list **stack_b)
{
	if (check_sorted(*stack_a))
		return ;
	while (ft_list_size(*stack_a) > 3)
	{
		if ((*stack_a)->index == 0 || (*stack_a)->index == 1)
			push_pb(stack_a, stack_b);
		else
			rotate_ra(stack_a);
	}
	sort_3nbr(stack_a);
	if ((*stack_b)->index < (*stack_b)->next->index)
		swap_sb(stack_b);
	push_pa(stack_a, stack_b);
	push_pa(stack_a, stack_b);
}
