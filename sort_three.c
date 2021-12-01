/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:05:48 by lbuccher          #+#    #+#             */
/*   Updated: 2021/12/01 16:06:52 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	sort_three(t_array *arr)
{
	int	i;
	int	nb;
	int	*a;

	i = 0;
	nb = 0;
	a = arr->a;
	while (is_sort(arr->size_a, arr->a) != 1)
	{
		if (a[2] < a[1] && a[2] < a[0])
			rra(arr);
		else if ((a[0] > a[1] && a[0] > a[2]) || (a[0] < a[1] && a[0] > a[2]))
			ra(arr);
		else if ((a[0] > a[1] && a[0] < a[2]) || (a[0] < a[1] && a[0] < a[2]))
			sa(arr);
		nb++;
		i++;
	}
	return (nb);
}
