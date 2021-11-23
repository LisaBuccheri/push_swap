/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:50:05 by lbuccher          #+#    #+#             */
/*   Updated: 2021/11/22 20:36:39 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	check_small(t_array *arr)
{
	int	i;
	int	nb;
	int	second;

	i = 0;
	nb = arr->a[i];
	second = nb;
	while (i < arr->size_a)
	{
		if (nb > arr->a[i])
			nb = arr->a[i];
		else if (second < arr->a[i])
			second = arr->a[i];
		i++;
	}
	i = 0;
	while (i < arr->size_a)
	{
		if (arr->a[i] > nb && second > arr->a[i])
			second = arr->a[i];
		i++;
	}
	return (nb);
}

int	check_second(t_array *arr)
{
	int	i;
	int	nb;
	int	second;

	i = 0;
	nb = arr->a[i];
	second = nb;
	while (i < arr->size_a)
	{
		if (nb > arr->a[i])
			nb = arr->a[i];
		else if (second < arr->a[i])
			second = arr->a[i];
		i++;
	}
	i = 0;
	while (i < arr->size_a)
	{
		if (arr->a[i] > nb && second > arr->a[i])
			second = arr->a[i];
		i++;
	}
	return (second);
}

void	sort(t_array *arr)
{
	int	i;
	int	j;
	int	small_int;
	int	second_small;

	while (arr->size_a != 2)
	{
		i = 0;
		j = 0;
		small_int = check_small(arr);
		second_small = check_second(arr);
		while (arr->a[i] != small_int)
			i++;
		while (small_int != arr->a[0])
		{
			if (second_small == arr->a[0] && arr->size_a > 3)
			{
				pb(arr);
				i -= 1;
			}
			if (i >= arr->size_a / 2)
				rra(arr);
			else
				ra(arr);
			j++;
		}
		if (j == i && arr->a[0] == small_int)
		{
			pb(arr);
			if (arr->b[1] > arr->b[0])
				sb(arr);
		}
		if (is_sort(arr->size_a, arr->a) == 1)
			break ;
	}
	if (arr->a[0] > arr->a[1])
		sa(arr);
	while (arr->size_b != 0)
		pa(arr);
}
