/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:50:05 by lbuccher          #+#    #+#             */
/*   Updated: 2021/11/24 17:54:32 by lbuccher         ###   ########.fr       */
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

void	sort_four(int i, int small_int, t_array *arr)
{
	while (arr->a[i] != small_int)
		i++;
	while (small_int != arr->a[0])
	{
		if (i >= arr->size_a / 2)
			rra(arr);
		else
			ra(arr);
	}
	if (arr->a[0] == small_int)
		pb(arr);
}

void	sort_five(int i, int small_int, int second_small, t_array *arr)
{
	while (arr->a[i] != small_int)
		i++;
	while (small_int != arr->a[0])
	{
		if (i >= arr->size_a / 2)
			rra(arr);
		else
			ra(arr);
	}
	if (arr->a[0] == small_int)
		pb(arr);
	i = 0;
	while (arr->a[i] != small_int)
		i++;
	while (second_small != arr->a[0])
	{
		if (i >= arr->size_a / 2)
			rra(arr);
		else
			ra(arr);
	}
	if (arr->a[0] == second_small)
		pb(arr);
}

void	sort_little(int nb, t_array *arr)
{
	int	i;
	int	small_int;
	int	second_small;

	i = 0;
	small_int = check_small(arr);
	second_small = check_second(arr);
	if (nb >= 3 && nb <= 5)
	{
		if (nb == 4)
			sort_four(i, small_int, arr);
		else if (nb == 5)
			sort_five(i, small_int, second_small, arr);
		sort_three(arr);
		while (arr->size_b > 0)
			pa(arr);
	}
}
