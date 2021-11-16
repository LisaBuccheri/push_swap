/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:18:11 by lbuccher          #+#    #+#             */
/*   Updated: 2021/11/07 15:20:40 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ra(t_array *arr)
{
	int	i;
	int	len;
	int	stock;

	i = 0;
	len = arr->size_a - 1;
	stock = arr->a[i];
	arr->nb_move++;
	while (i < len)
	{
		arr->a[i] = arr->a[i + 1];
		i++;
		if (i == len)
			arr->a[i] = stock;
	}
	printf("ra");
}

void	rb(t_array *arr)
{
	int	i;
	int	len;
	int	stock;

	i = 0;
	len = arr->size_b - 1;
	stock = arr->b[i];
	arr->nb_move++;
	while (i < len)
	{
		arr->b[i] = arr->b[i + 1];
		i++;
		if (i == len)
			arr->b[i] = stock;
	}
	printf("rb");
}

void	rr(t_array *arr)
{
	ra(arr);
	rb(arr);
}
