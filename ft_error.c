/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:42:32 by lbuccher          #+#    #+#             */
/*   Updated: 2021/12/01 16:03:56 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_error(t_array *arr, int argc)
{
	if (ft_error_duplicate(arr) == 0)
		return (0);
	else if (argc == 1 || is_sort(arr->size_a, arr->a))
		return (0);
	return (1);
}

int	ft_error_int(int stat, int *arr)
{
	if (stat)
	{
		write(1, "Error\n", 6);
		free(arr);
		return (1);
	}
	return (0);
}

int	ft_error_duplicate(t_array *arr)
{
	if (is_duplicate(arr) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	ft_error_digit(int argc, char *argv[])
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (is_digit(argv[i]) == 0)
		{
			write(1, "Error\n", 6);
			return (0);
		}
	}
	return (1);
}