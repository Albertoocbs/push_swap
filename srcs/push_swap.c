/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:51:47 by aoutumur          #+#    #+#             */
/*   Updated: 2025/03/07 11:58:06 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "ft_printf/ft_printf.h"

/*implement quick sort algo for greater numbers 100 and 500*/

void	sort_stack(t_swap *tab)
{
	int	size;

	size = ft_list_size(tab->stack_a);
	if (size <= 1 || check_sort(tab->stack_a))
		return ;
	else if (size == 2)
		swap_sa(tab->stack_a);
	else if (size == 3)
		sort_3nbr(tab);
	else if (size == 5)
		sort_5nbr(tab);
	else
		quick_sort(tab); // Or any other sorting algorithm
}
