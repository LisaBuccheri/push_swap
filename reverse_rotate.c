/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:18:22 by lbuccher          #+#    #+#             */
/*   Updated: 2021/11/24 17:52:48 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rra(t_array *arr)
{
	int	i;
	int	len;
	int	stock;

	i = 0;
	len = arr->size_a - 1;
	stock = arr->a[len];
	arr->nb_move++;
	while (i < len)
	{
		arr->a[len] = arr->a[len - 1];
		len--;
		if (i == len)
			arr->a[i] = stock;
	}
	write(1, "rra\n", 4);
}

void	rrb(t_array *arr)
{
	int	i;
	int	len;
	int	stock;

	i = 0;
	len = arr->size_b - 1;
	stock = arr->b[len];
	arr->nb_move++;
	while (i < len)
	{
		arr->b[len] = arr->b[len - 1];
		len--;
		if (i == len)
			arr->b[i] = stock;
	}
	write(1, "rrb\n", 4);
}

void	rrr(t_array *arr)
{
	rra(arr);
	rrb(arr);
	arr->nb_move--;
}
