/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:35:20 by lbuccher          #+#    #+#             */
/*   Updated: 2021/11/26 13:28:40 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdio.h>

void	init_a(t_array *arr)
{
	int	i;
	int	j;

	i = -1;
	while (++i < arr->g_size)
	{
		j = -1;
		while (++j < arr->g_size)
		{
			if (arr->g_arr[j] == arr->a[i])
			{
				arr->a[i] = j;
				break ;
			}
		}
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
