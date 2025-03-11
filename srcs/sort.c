/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:51:47 by aoutumur          #+#    #+#             */
/*   Updated: 2025/03/11 12:28:40 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "ft_printf/ft_printf.h"

static int	get_max_bits(t_list *stack)
{
	int		max;
	int		max_bits ;
	t_list	*tmp;

	tmp = stack;
	max = 0;
	max_bits = 0;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	size = ft_list_size(*stack_a);
	max_bits = get_max_bits(*stack_a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		size = ft_list_size(*stack_a);
		while (j < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 1)
				rotate_ra(stack_a);
			else
				push_pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			push_pa(stack_a, stack_b);
		i++;
	}
}

void	sort_stack(t_swap *tab)
{
	int	size;

	size = ft_list_size(tab->stack_a);
	if (size <= 1 || check_sorted(tab->stack_a))
		return ;
	else if (size == 2)
		swap_sa(&tab->stack_a);
	else if (size == 3)
		sort_3nbr(&tab->stack_a);
	else if (size == 4)
		sort_4nbr(&tab->stack_a, &tab->stack_b);
	else if (size == 5)
		sort_5nbr(&tab->stack_a, &tab->stack_b);
	else
		radix_sort(&tab->stack_a, &tab->stack_b);
}
