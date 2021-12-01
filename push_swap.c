/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:18:25 by lbuccher          #+#    #+#             */
/*   Updated: 2021/12/01 16:05:42 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	*sort_tempo(int *tempo, int size)
{
	int	t;
	int	i;

	t = 0;
	while (is_sort(size, tempo) != 1)
	{
		i = 0;
		while (i < size - 1)
		{
			if (tempo[i] > tempo[i + 1])
			{
				t = tempo[i];
				tempo[i] = tempo[i + 1];
				tempo[i + 1] = t;
			}
			i++;
		}
	}
	return (tempo);
}

int	*init_array(int argc, char *argv[], char array)
{
	int	*arr;
	int	i;
	int	stat;

	arr = (int *)malloc((argc + 1) * sizeof(int));
	i = -1;
	if (array == 'a')
	{
		while (++i < argc - 1)
		{
			stat = 0;
			arr[i] = ft_atoi(argv[i + 1], &stat);
			if (ft_error_int(stat, arr))
				return (NULL);
		}
	}
	else if (array == 'b')
	{
		while (++i < argc - 1)
			arr[i] = 0;
	}
	return (arr);
}

int	init_struct(int argc, char **argv, t_array *arr)
{
	arr->a = init_array(argc, argv, 'a');
	if (!arr->a)
		return (ft_free(arr));
	arr->size_a = argc - 1;
	arr->b = init_array(argc, argv, 'b');
	if (!arr->b)
		return (ft_free(arr));
	arr->size_b = 0;
	arr->nb_move = 0;
	arr->g_arr = init_array(argc, argv, 'a');
	arr->g_size = argc - 1;
	arr->g_arr = sort_tempo(arr->g_arr, arr->g_size);
	return (0);
}

int	ft_free(t_array *arr)
{
	if (arr->a)
		free(arr->a);
	if (arr->b)
		free(arr->b);
	if (arr->g_arr)
		free(arr->g_arr);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_array	arr;

	if (ft_error_digit(argc, argv) == 0)
		return (ft_free(&arr));
	init_struct(argc, argv, &arr);
	if (ft_error(&arr, argc) == 0)
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
