/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:52:04 by aoutumur          #+#    #+#             */
/*   Updated: 2025/03/13 14:03:14 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "ft_printf/ft_printf.h"

/*free args function*/
void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

/* free stack function*/
void	free_stack(t_list *stack)
{
	t_list	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

void	free_all_stacks(t_swap *tab)
{
	if (tab)
	{
		if (tab->stack_a)
			free_stack(tab->stack_a);
		if (tab->stack_b)
			free_stack(tab->stack_b);
		free(tab);
	}
}

void	check_and_exit(t_swap *tab, char **args, int argc)
{
	if (argc == 2)
		exit_error(tab, args);
	else
		exit_error(tab, NULL);
}

/*exit_error function*/
void	exit_error(t_swap *tab, char **args)
{
	if (args)
		free_args(args);
	if (tab)
	{
		free_stack(tab->stack_a);
		free_stack(tab->stack_b);
		free(tab);
	}
	write(1, "Error\n", 6);
	exit(1);
}
