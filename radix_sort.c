/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:35:20 by lbuccher          #+#    #+#             */
/*   Updated: 2021/11/22 20:23:45 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	init_a(t_array *arr)
{
	int	i;
	int	j;

	i = 0;
	while (i < arr->g_size)
	{
		j = 0;
		while (j < arr->g_size)
		{
			if (arr->g_arr[i] == arr->a[j])
				arr->a[j] = i;
			j++;
		}
		i++;
	}
}

int	max_binary(t_array *arr)
{
	int	max_binary;
	int	max_n;

	max_binary = 0;
	max_n = arr->size_a - 1;
	while (max_n != 1)
	{
		max_n /= 2;
		max_binary++;
	}
	return (++max_binary);
}

int	max_push(t_array *arr, int j)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (i < arr->size_a)
	{
		if ((arr->a[i] >> j) & 1)
			i++;
		else
		{
			nb++;
			i++;
		}
	}
	return (nb);
}

void	radix_sort(t_array *arr)
{
	int	max_b;
	int	actual_b;
	int	i;

	init_a(arr);
	max_b = max_binary(arr);
	actual_b = 0;
	while (actual_b < max_b)
	{
		i = 0;
		while (i < arr->g_size)
		{
			if ((arr->a[0] >> actual_b) & 1)
				ra(arr);
			else
				pb(arr);
			i++;
		}
		while (arr->size_b > 0)
			pa(arr);
		actual_b++;
	}
}
