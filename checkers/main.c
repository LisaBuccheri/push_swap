/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:37:28 by lbuccher          #+#    #+#             */
/*   Updated: 2021/12/01 20:19:03 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include "../push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	//if (!s1)
	//	return (0);
	while (s1 && s1[i] == s2[i])
		i++;
	if (i - 1  == ft_strlen(s1))
		return (1);
	printf("s1: %zu \t i: %zu\n", ft_strlen(s1), i);
	return (0);
}

void	check_sort(t_array *arr)
{
	if (is_sort(arr->size_a, arr->a) == 1 && arr->size_b == 0)
		write(1, "OK\n", 3);
	else if (is_sort(arr->size_a, arr->a) == 0 || arr->size_b != 0)
		write(1, "KO\n", 3);
	ft_free(arr);
	exit(0);
}

void	compare_op(char *str, t_array *arr)
{
	if (ft_strcmp(str, "sa\n"))
		sa(arr);
	else if (ft_strcmp(str, "sb\n"))
		sb(arr);
	else if (ft_strcmp(str, "ss\n"))
		ss(arr);
	else if (ft_strcmp(str, "pa\n"))
		pa(arr);
	else if (ft_strcmp(str, "pb\n"))
		pb(arr);
	else if (ft_strcmp(str, "ra\n"))
		ra(arr);
	else if (ft_strcmp(str, "rb\n"))
		rb(arr);
	else if (ft_strcmp(str, "rr\n"))
		rr(arr);
	else if (ft_strcmp(str, "rra\n"))
		rra(arr);
	else if (ft_strcmp(str, "rrb\n"))
		rrb(arr);
	else if (ft_strcmp(str, "rrr\n"))
		rrr(arr);
	else if (ft_strcmp(str, ""))
		check_sort(arr);
	else
	{
		write(1, "Error\n", 6);
		exit(0);
	}
}

int	main(int argc, char *argv[])
{
	int		i;
	char	*op;
	t_array	arr;

	i = 0;
	if (ft_error_digit(argc, argv) == 0)
		return (ft_free(&arr));
	init_struct(argc, argv, &arr);
	if (ft_error(&arr, argc, 0) == 0)
		return (ft_free(&arr));
	//op = get_next_line(1);
	while (1)
	{
		op = get_next_line(1);
		compare_op(op, &arr);
	}
	ft_free(&arr);
	//return (0);
}
