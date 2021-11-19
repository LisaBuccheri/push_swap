/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 09:08:18 by lbuccher          #+#    #+#             */
/*   Updated: 2021/11/19 09:39:58 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 #include "push_swap.h"

int	*sort_tempo(int *tempo, int size)
{
	int	t;
	int	i;

	t = 0;
	while (is_sort(size, tempo) != 1)
	{
		i = 0;
		while (i < size - 1) 
		{
			if (tempo[i] > tempo[i + 1])
			{
				t = tempo[i];
				tempo[i] = tempo[i + 1];
				tempo[i + 1] = t;
			}
			i++;
		}
	}
	return (tempo);
}

int	*reinit_tempo(int *tempo, int arr_size, t_array *arr)
{
	int	*t;
	int	i;

	t = (int *)malloc((arr_size) * sizeof(int));
	i = 0;
	while (i < arr_size)
	{
		t[i] = arr->a[i];
		i++;
	}	
	free(tempo);
	return (t);
}

void	sort2(int *t, t_array *arr)
{
	int	a_index;
	int	mid;
	//int	i;
	int	j;

	a_index = 0;
	mid = 0;
	while (mid < arr->size_a / 2)
		mid++;
	while (a_index < mid && arr->size_a != 2)
	{
		if (arr->a[0] < t[mid])
		{
			pb(arr);
			a_index++;
		}
		else if (arr->a[arr->size_a - 1] < t[mid])
		{
			rra(arr);
			pb(arr);
			a_index++;
		}
		else if (a_index < mid)
		{
			j = 0; 
			if (arr->a[0] >= t[mid] && j < arr->size_a && a_index < mid)
			{
				ra(arr);
				j++;
			}
			if (arr->a[0] < t[mid])
			{
				pb(arr);
				a_index++;
			}
		}
	}
	if (is_sort(arr->size_a, arr->a) != 1 && arr->size_a != 2)
	{
		t = reinit_tempo(t, arr->size_a, arr);
		t = sort_tempo(t, arr->size_a);
		sort2(t, arr);
	}
	if (arr->a[0] > arr->a[1])
		sa(arr);
	if (invert_sort(arr, arr->b) == 1 && is_sort(arr->size_a, arr->a) == 1)
	{
		while (arr->size_b != 0)
			pa(arr);
		return ;
	}
	arr->g_arr = sort_tempo(arr->g_arr, arr->g_size);
	while (arr->size_b > 0)
	{
		while (arr->b[0] != arr->g_arr[arr->size_b - 1])
			rb(arr);
		if (arr->b[0] == arr->g_arr[arr->size_b - 1])
			pa(arr);
	}
}
/*
int	**get_pieces(t_array *arr)
{
	int	**pieces;
	int	a_size;
	int	p_size;
	int	i;

	i = -1;
	p_size = 0;
	a_size = arr->size_a;
	while (a_size / 2 > 0)
	{
		a_size /= 2;
		p_size++;
	}
	pieces = (int **)malloc(p_size * sizeof(int *));
	a_size = arr->size_a;
	while (++i < p_size)
	{
		a_size /= 2;
		pieces[i] = malloc(a_size * sizeof(int));
	}
	return (pieces);
}*/
