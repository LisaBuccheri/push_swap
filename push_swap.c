/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:18:25 by lbuccher          #+#    #+#             */
/*   Updated: 2021/11/19 17:38:16 by lbuccher         ###   ########.fr       */
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

int	is_twice(int argc, int *a)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (a[i] == a[j])
				return (printf("%s\n", "Error"));
			j++;
		}
		i++;
	}
	return (printf("%s\n", "OK"));
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

int	is_sort(int size, int *array)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (array[i] > array[i + 1])
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
	else
		radix_sort(&arr);		//sort(&arr);		//sort2(t, &arr);
	while (i < argc - 1)
	{
		write (1, "\narray A: ", 10);
		ft_putnbr(arr.a[i++]);
	}
	i = 0;
	while (i < argc - 1)
	{
		write (1, "\narray B: ", 10);
		ft_putnbr(arr.b[i++]);
	}
	printf("\nnumber of movement: %d\n", arr.nb_move);
	return (0);
}
