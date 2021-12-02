/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:28:48 by lbuccher          #+#    #+#             */
/*   Updated: 2021/12/01 18:22:39 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	is_duplicate(t_array *arr)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	while (++i < arr->size_a - 1)
	{
		j = i;
		temp = arr->a[i];
		while (++j < arr->size_a)
			if (temp == arr->a[j])
				return (0);
	}
	return (1);
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

int	is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' && str[i + 1])
		{
			if (str[i + 1] < '0' || str[i + 1] > '9')
				return (0);
		}		
		else if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
