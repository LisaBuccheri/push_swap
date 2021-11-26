/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:18:25 by lbuccher          #+#    #+#             */
/*   Updated: 2021/11/26 13:37:21 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdio.h>

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

void	init_struct(int argc, char **argv, t_array *arr)
{
	arr->a = init_array(argc, argv, 'a');
	arr->size_a = argc - 1;
	arr->b = init_array(argc, argv, 'b');
	arr->size_b = 0;
	arr->nb_move = 0;
	arr->g_arr = init_array(argc, argv, 'a');
	arr->g_size = argc - 1;
	arr->g_arr = sort_tempo(arr->g_arr, arr->g_size);
}

void	ft_free(t_array *arr)
{
	if (arr->a)
		free(arr->a);
	if (arr->b)
		free(arr->b);
	if (arr->g_arr)
		free(arr->g_arr);
}

int	main(int argc, char *argv[])
{
	t_array	arr;
	int		i;

	i = 0;
	while (++i < argc)
	{
		if (is_digit(argv[i]) == 0 || str_cmp(argc, argv) == 0)
		{
			ft_free(&arr);
			return (write(1, "Error\n", 6));
		}
	}
/*	if (str_cmp(argc, argv) == 0)
	{
			ft_free(&arr);
			return (write(1, "Error\n", 6));
	}	*/
	init_struct(argc, argv, &arr);
	if (argc == 1 || is_sort(arr.size_a, arr.a))
		return (0);
	if (argc == 3 && argv[2] > argv[3])
		sa(&arr);
	else if (argc > 3 && argc < 7)
		sort_little(argc - 1, &arr);
	else
		radix_sort(&arr);
	ft_free(&arr);
	return (0);
}
