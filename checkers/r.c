/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:18:11 by lbuccher          #+#    #+#             */
/*   Updated: 2021/12/02 22:48:16 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	r_a(t_array *arr)
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
}

void	r_b(t_array *arr)
{
	int	i;
	int	len;
	int	stock;

	i = 0;
	len = arr->size_b - 1;
	if (arr->size_b == 0)
		return ;
	stock = arr->b[i];
	arr->nb_move++;
	while (i < len)
	{
		arr->b[i] = arr->b[i + 1];
		i++;
		if (i == len)
			arr->b[i] = stock;
	}
}

void	r_r(t_array *arr)
{
	r_a(arr);
	r_b(arr);
	arr->nb_move--;
}
