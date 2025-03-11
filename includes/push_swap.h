/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:52:10 by aoutumur          #+#    #+#             */
/*   Updated: 2025/03/10 17:36:33 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

/*structure globale qui regroupe les deux piles(stacks) et leur taille*/
typedef struct s_swap
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		a_size;
	int		b_size;
}	t_swap;

/*-------------Input_Check-------------*/
int	is_correct_input(char **args);

/*----------Stack Initialisation -----*/
t_list	*ft_new_list_node(int valeur);
void	ft_add_node_back(t_list **stack, t_list *new_node);
t_list	*fill_stack(char **args);
void	assign_index(t_list *stack);

/*------------Swap Functions---------*/
void	swap_sa(t_list **stack_a);
void	swap_sb(t_list **stack_b);
void	swap_ss(t_list **stack_a, t_list **stack_b);

/*------------Push Functions---------*/
void	push_pa(t_list **stack_a, t_list **stack_b);
void	push_pb(t_list **stack_a, t_list **stack_b);

/*----------Rotate Functions---------*/
void	rotate_ra(t_list **stack_a);
void	rotate_rb(t_list **stack_b);
void	rotate_rr(t_list **stack_a, t_list **stack_b);

/*--------Reverse Rotate Functions------*/
void	rev_rotate_rra(t_list **stack_a);
void	rev_rotate_rrb(t_list **stack_b);
void	rev_rotate_rrr(t_list **stack_a, t_list **stack_b);


/*--------Utils(Errors & MemFree) Functions-------*/
void	free_args(char **args);
void	free_stack(t_list *stack);
void	free_all_stacks(t_swap *tab);
void	exit_error(t_swap *tab, char **args);
void	check_and_exit(t_swap *tab, char **args, int argc);

/*-----------Sort Handler Functions-----------*/
int	check_sorted(t_list *stack);
void	sort_3nbr(t_list **stack);
void	sort_5nbr(t_list **stack_a, t_list **stack_b);
int	ft_list_size(t_list *stack);

/*-----------Sorting Algorithms sort.c-----------*/
void	sort_stack(t_swap *tab);
void	radix_sort(t_list **stack_a, t_list **stack_b);

#endif
