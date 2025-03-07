/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutumur <aoutumur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:22:53 by aoutumur          #+#    #+#             */
/*   Updated: 2025/03/04 12:24:35 by aoutumur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long ft_atol(const char *s)
{
	long result;
	int sign;
	int i;

	result = 0;
	sign = 1;
	i = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
	i++;

	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
		sign = -1;
		i++;
	}
	while (s[i])
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	return (result * sign);
}
