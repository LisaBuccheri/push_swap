/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 09:08:18 by lbuccher          #+#    #+#             */
/*   Updated: 2021/11/16 20:32:55 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 #include "push_swap.h"

int	*sort_tempo(int *tempo, t_array *arr)
{
	int	t;
	int	i;

	t = 0;
	while (is_sort(arr, tempo) != 1)
	{
		i = 0;
		while (i < arr->size_a - 1) 
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
	/*
	i = 0;
	while (i < arr->size_a)
	{
		write (1, "\narray t: ", 10);
		ft_putnbr(tempo[i++]);
	}	printf("nb tempo: %d\n", i);*/
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
	i = 0;
	while (i < 12)
	{
		write (1, "\narray B: ", 10);
		ft_putnbr(arr->b[i++]);
	}
	free(tempo);
	return (t);
}

void	sort2(int *t, t_array *arr)
{
	int	a_index;
	int	mid;
	int	i;

	a_index = 0;
	mid = 0;
	i = 0;
	while (mid < arr->size_a / 2)
		mid++;
	printf("MID: %d", mid);
	while (a_index < mid && arr->size_a != 2)
	{
		if (arr->a[0] < t[mid])
		{
			printf("\t A: 0-> %d\n", arr->a[0]);
			printf("\t T: M-> %d\n", t[mid]);
			pb(arr);
			a_index++;
		}
		else if (arr->a[arr->size_a - 1] < t[mid])
		{
			printf("%d", arr->a[arr->size_a - 1]);
			rra(arr);
			pb(arr);
			a_index++;
		}
		else if (a_index < mid)
		{
			printf("%d", arr->a[0]);
			while (arr->a[0] >= t[mid])
			{
				printf("%d", t[mid]);
				ra(arr);
			}
			if (arr->a[0] < t[mid])
			{
				pb(arr);
				a_index++;
			}
		}
	}
	if (is_sort(arr, arr->a) != 1 && arr->size_a != 2)
	{
		t = reinit_tempo(t, arr->size_b, arr);
		t = sort_tempo(t, arr);
		sort2(t, arr);
	}
	if (arr->a[0] > arr->a[1])
		sa(arr);
	if (invert_sort(arr, arr->b) == 1 && is_sort(arr, arr->a) == 1)
	{
		printf("\nhere%d\n", is_sort(arr, arr->a));
		while (arr->size_b != 0)
			pa(arr);
		return ;
	}
	//arr->g_arr = sort_tempo(t, arr);
/*	while (arr->size_b > 0)
	{
		if (arr->b[0] == arr->g_arr[arr->g_size - arr->size_a])
			printf("HERE");
	}*/
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
