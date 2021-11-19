/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:35:20 by lbuccher          #+#    #+#             */
/*   Updated: 2021/11/19 17:42:06 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	init_a(t_array *arr)
{
	int	i;
	int	j;
/*
	i = 0;
	while (i < arr->size_a)
	{
		write (1, "\narray A: ", 10);
		ft_putnbr(arr->a[i++]);
	}*/
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
	int nb;

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
	int	nb_to_push;
	int	nb_max_push;
	int	i;

	init_a(arr);
	max_b = max_binary(arr);
	actual_b = 0;
	while (actual_b < max_b)
	{
		nb_max_push = max_push(arr, actual_b);
		//printf("max push: %d\n", nb_max_push); 
		nb_to_push = 0;
		while (i < arr->g_size)//(nb_to_push < nb_max_push) mattre avec g size decle le soucis mais ne l arrange pas
		{
			if ((arr->a[0] >> actual_b) & 1)
			{
				printf("ra num: %d\n", arr->a[0]);
				ra(arr);
			}
			else
			{
				pb(arr);
				nb_to_push++;
			}
			i++;
			//write (1, "\nA[0]:  ", 8);
			//ft_putnbr(arr->a[0]);
		}
		i = 0;
	/*	while (i < arr->size_b)
		{
			write (1, "\narray B: ", 10);
			ft_putnbr(arr->b[i++]);
		}*/
		while (arr->size_b > 0)
			pa(arr);
		actual_b++;
	/*	i = 0;
		while (i < arr->size_a)
		{
			write (1, "\narr Aa: ", 10);
			ft_putnbr(arr->a[i++]);
		}*/
	}
}
