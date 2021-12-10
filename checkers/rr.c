/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:18:22 by lbuccher          #+#    #+#             */
/*   Updated: 2021/12/02 22:48:28 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	r_ra(t_array *arr)
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
}

void	r_rb(t_array *arr)
{
	int	i;
	int	len;
	int	stock;

	i = 0;
	len = arr->size_b - 1;
	if (arr->size_b == 0)
		return ;
	stock = arr->b[len];
	arr->nb_move++;
	while (i < len)
	{
		arr->b[len] = arr->b[len - 1];
		len--;
		if (i == len)
			arr->b[i] = stock;
	}
}

void	r_rr(t_array *arr)
{
	r_ra(arr);
	r_rb(arr);
	arr->nb_move--;
}
