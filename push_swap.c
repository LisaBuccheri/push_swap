/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:18:25 by lbuccher          #+#    #+#             */
/*   Updated: 2021/11/22 20:57:44 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	*init_array(int argc, char *argv[], char array)
{
	int	*arr;
	int	i;

	arr = (int *)malloc((argc + 1) * sizeof(int));
	i = 0;
	if (array == 'a')
	{
		while (i < argc - 1)
		{
			arr[i] = ft_atoi(argv[i + 1]);
			i++;
		}
	}
	else if (array == 'b')
	{
		while (i < argc - 1)
		{
			arr[i] = 0;
			i++;
		}
	}
	return (arr);
}

int	invert_sort(t_array *arr, int *array)
{
	int	i;

	i = 0;
	while (i < arr->size_b - 1)
	{
		if (array[i] < array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_array	arr;
	int		i;
	int		*t;

	i = 0;
	arr.a = init_array(argc, argv, 'a');
	arr.size_a = argc - 1;
	arr.b = init_array(argc, argv, 'b');
	arr.size_b = 0;
	arr.nb_move = 0;
	arr.g_arr = init_array(argc, argv, 'a');
	arr.g_size = argc - 1;
	arr.g_arr = sort_tempo(arr.g_arr, arr.g_size);
	t = init_array(argc, argv, 'a');
	t = sort_tempo(t, arr.size_a);
	if (argc == 4)
		printf("nombre de move: %d\n", sort_three(&arr));
	else if (argc > 4 && argc < 50)
		sort(&arr);
	else
		radix_sort(&arr);
	printf("\nnumber of movement: %d\n", arr.nb_move);
	if (is_sort(arr.size_a, arr.a) == 1)
		printf("OK");
	else
		printf("KO!");
	return (0);
}
