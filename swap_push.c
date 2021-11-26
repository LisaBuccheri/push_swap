/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:38:50 by lbuccher          #+#    #+#             */
/*   Updated: 2021/11/24 17:16:40 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sa(t_array *arr)
{
	int	swap_n;

	arr->nb_move ++;
	if (arr->size_a > 1)
	{
		swap_n = arr->a[0];
		arr->a[0] = arr->a[1];
		arr->a[1] = swap_n;
	}
	write(1, "sa\n", 3);
}

void	sb(t_array *arr)
{
	int	swap_n;

	arr->nb_move++;
	if (arr->size_b > 1)
	{
		swap_n = arr->b[0];
		arr->b[0] = arr->b[1];
		arr->b[1] = swap_n;
	}
	write(1, "sb\n", 3);
}

void	ss(t_array *arr)
{
	sa(arr);
	sb(arr);
	arr->nb_move--;
}

void	pa(t_array *arr)
{
	int	i;
	int	len_a;

	i = -1;
	len_a = arr->size_a;
	arr->nb_move++;
	if (arr->size_b > 0)
	{
		while (len_a > 0)
		{
			arr->a[len_a] = arr->a[len_a - 1];
			len_a--;
		}
		len_a = arr->size_b;
		arr->a[0] = arr->b[0];
		while (++i < len_a)
		{
			arr->b[i] = arr->b[i + 1];
			if (i == len_a - 1)
				arr->b[i] = 0;
		}
	}
	arr->size_a++;
	arr->size_b--;
	write(1, "pa\n", 3);
}

void	pb(t_array *arr)
{
	int	i;
	int	len_a;

	i = -1;
	len_a = arr->size_b;
	arr->nb_move++;
	if (arr->size_a > 0)
	{
		while (len_a > 0)
		{
			arr->b[len_a] = arr->b[len_a - 1];
			len_a--;
		}
		len_a = arr->size_a;
		arr->b[0] = arr->a[0];
		while (++i < len_a - 1)
		{
			arr->a[i] = arr->a[i + 1];
			if (i == len_a - 1)
				arr->a[i] = 0;
		}
	}
	arr->size_b++;
	arr->size_a--;
	write(1, "pb\n", 3);
}
