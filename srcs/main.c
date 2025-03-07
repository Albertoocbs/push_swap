/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:51:29 by aoutumur          #+#    #+#             */
/*   Updated: 2025/03/07 11:54:19 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "ft_printf/ft_printf.h"

void	check_and_exit(t_swap *tab, char **args, int argc)
{
	if (argc == 2)
		exit_error(tab, args);
	else
		exit_error(tab, NULL);
}

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
	/*assign_index(tab->stack_a);*/
	sort_stack (&tab->stack_a);
	free_stack(tab->stack_a);
	free_stack(tab->stack_b);
	if (argc == 2)
		free_args(args);
	free(tab);
	return (0);
}

/*
int main(int argc, char **argv)
{
	char	**args;
	t_swap	*tab; // en utilisant un pointeur vers ma structure je peux passer
		celle-la en argument a mes fonctions sans avoir besoin de la retourner

    // Si aucun argument n'est passé, on quitte le programme.
	if (argc < 2)
		return (0);
	tab = malloc(sizeof(t_swap));
	if (!tab)
		exit_error();
    // Si un seul argument est passé, il peut contenir plusieurs nombres.
	if (argc == 2)
		args = ft_split(argv[1], ' ');
    // Sinon, chaque argument est déjà un nombre
	else
		args = &argv[1]; // pointer sur le premier nombre du tableau

    // Vérifie que tous les éléments sont valides
	if (!is_correct_input(args))
		exit_error();

    // Remplir la pile A avec les valeurs converties à partir de args.
    // fill_stack doit créer une liste chaînée (t_list *) avec les entiers et
    // mettre à jour swap.a_size.
	tab->stack_a = fill_stack(args); // Convertit args en une pile d'entiers.
	if (!tab->stack_a)
		exit_error();
	tab->stack_b = NULL;

    // Assignation des index à chaque élément
	assign_index(tab->stack_a);

    // Lancer l'algorithme de tri.
	sort(&tab->stack_a, &tab->stack_b);

    // Libération de la mémoire (piles, tableau args , etc.)
	free_stack(tab->stack_a);
	free_stack(tab->stack_b);
	if (argc == 2)
		free_args(args);
	return (0);
}
*/
