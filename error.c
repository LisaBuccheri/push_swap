/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:28:48 by lbuccher          #+#    #+#             */
/*   Updated: 2021/11/22 20:30:32 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	is_twice(int argc, t_array *arr)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (arr->a[i] == arr->a[j])
				return (printf("%s\n", "Error"));
			j++;
		}
		i++;
	}
	return (printf("%s\n", "OK"));
}

int	is_sort(int size, int *array)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (array[i] > array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	is_digit(t_array *arr)
{
	int	i;

	i = 0;
	while (i < arr->size_a)
	{
		if (arr->a[i] < 48 || arr->a[i] > 57)
			return (0);
		i++;
	}
	return (1);
}
