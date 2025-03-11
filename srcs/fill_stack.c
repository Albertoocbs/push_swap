/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:52:00 by aoutumur          #+#    #+#             */
/*   Updated: 2025/03/10 17:24:02 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "ft_printf/ft_printf.h"

/*creates a new node with that integer as its valeur*/
t_list	*ft_new_list_node(int valeur)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		exit_error(NULL, NULL);
	list->valeur = valeur;
	list->index = 0;
	list->next = NULL;
	return (list);
}

/*Adds the newly created node to the end of the list stack
using the previously defined function.*/
void	ft_add_node_back(t_list **stack, t_list *new_node)
{
	t_list	*tmp;

	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
}

/*
fill_stack rempli la pile A avec les nombres validés
 va convertir le tableau de chaînes en une liste chaînée de type t_list,
 en respectant l'ordre (le 1er nombre doit correspondre au sommet de la pile).
returns stack, which is a pointer to the head of the lnkd list
representing the stack */
t_list	*fill_stack(char **args)
{
	t_list	*stack;
	t_list	*new_node;
	int		i;

	i = 0;
	stack = NULL;
	while (args[i])
	{
		new_node = ft_new_list_node(ft_atoi(args[i]));
		if (!new_node)
		{
			free_stack(stack);
			return (NULL);
		}
		ft_add_node_back(&stack, new_node);
		i++;
	}
	return (stack);
}

void	assign_index(t_list *stack)
{
	t_list	*current;
	t_list	*temp;

	current = stack;
	while (current)
	{
		current->index = 0;
		temp = stack;
		while (temp)
		{
			if (current->valeur > temp->valeur)
				current->index++;
			temp = temp->next;
		}
		current = current->next;
	}
}
