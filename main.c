/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:38:36 by lbuccher          #+#    #+#             */
/*   Updated: 2021/12/06 17:31:59 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_array	arr;
	int		init;

	if (ft_error_digit(argc, argv) == 0)
		return (0);
	init = init_struct(argc, argv, &arr);
	if (init == 0)
		exit(0);
	if (ft_error(&arr, argc, 1) == 0)
		return (ft_free(&arr));
	else if (argc == 3 && argv[2] > argv[3])
		sa(&arr);
	else if (argc > 3 && argc < 7)
		sort_little(argc - 1, &arr);
	else
		radix_sort(&arr);
	ft_free(&arr);
	return (0);
}
