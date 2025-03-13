/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:51:29 by aoutumur          #+#    #+#             */
/*   Updated: 2025/03/13 14:15:39 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "ft_printf/ft_printf.h"

t_swap	*init_tab(void)
{
	t_swap	*tab;

	tab = malloc(sizeof(t_swap));
	if (!tab)
		exit_error(NULL, NULL);
	tab->stack_a = NULL;
	tab->stack_b = NULL;
	return (tab);
}

char	**parse_args(int argc, char **argv, t_swap *tab)
{
	char	**args;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args || !args[0])
		{
			free(tab);
			if (args)
				free(args);
			write(1, "Error\n", 6);
			exit(1);
		}
	}
	else
		args = &argv[1];
	if (!is_correct_input(args))
		check_and_exit(tab, args, argc);
	return (args);
}

int	main(int argc, char **argv)
{
	char	**args;
	t_swap	*tab;

	if (argc < 2)
		return (0);
	tab = init_tab();
	args = parse_args(argc, argv, tab);
	tab->stack_a = fill_stack(args);
	if (!tab->stack_a)
		check_and_exit(tab, args, argc);
	assign_index(tab->stack_a);
	sort_stack(tab);
	free_all_stacks(tab);
	if (argc == 2)
		free_args(args);
	return (0);
}
