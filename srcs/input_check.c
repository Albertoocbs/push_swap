/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:22:06 by aoutumur          #+#    #+#             */
/*   Updated: 2025/03/10 17:24:01 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "ft_printf/ft_printf.h"

/* 	is_number:
*   Checks if the argument is a number. +1 1 and -1 are all valid numbers.
	if not a number return 0
*   Return: 1 if the argument is a number, 0 if not.
*/
static int	is_number(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

/* 	has_duplicates:
*   Checks if the argument list has duplicate numbers.
*   Return: 1 if a duplicate is found, 0 if there are none.
*/
static int	has_duplicates(char **args)
{
	int	i;
	int	j;
	int	numi;
	int	numj;

	i = 0;
	while (args[i])
	{
		numi = ft_atoi(args[i]);
		j = i + 1;
		while (args[j])
		{
			numj = ft_atoi(args[j]);
			if (numi == numj)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/* 	is_correct_input:
*   Checks if the given arguments are all numbers, without duplicates
*	& within INT_MIN, INT_MAX
*   Return: 1 if the arguments are valid, 0 if not.
*/
int	is_correct_input(char **args)
{
	int		i;
	long	num;

	i = 0;
	while (args[i])
	{
		if (!is_number(args[i]))
			return (0);
		num = ft_atol(args[i]);
		if (num < INT_MIN || num > INT_MAX)
			exit_error(NULL, NULL);
		i++;
	}
	if (has_duplicates(args))
		return (0);
	return (1);
}
