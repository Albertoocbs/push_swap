/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:51:29 by aoutumur          #+#    #+#             */
/*   Updated: 2025/03/10 17:24:01 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "ft_printf/ft_printf.h"

int	main(int argc, char **argv)
{
	char	**args;
	t_swap	*tab;

	if (argc < 2)
		return (0);
	tab = malloc(sizeof(t_swap));
	if (!tab)
		exit_error(NULL, NULL);
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = &argv[1];
	if (!is_correct_input(args))
		check_and_exit(tab, args, argc);
	tab->stack_a = fill_stack(args);
	if (!tab->stack_a)
		check_and_exit(tab, args, argc);
	tab->stack_b = NULL;
	assign_index(tab->stack_a);
	sort_stack(tab);
	free_all_stacks(tab);
	if (argc == 2)
		free_args(args);
	return (0);
}
