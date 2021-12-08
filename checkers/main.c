/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:45:05 by lbuccher          #+#    #+#             */
/*   Updated: 2021/12/07 14:59:33 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include "../push_swap.h"

int	ft_strcmp(char *s1, char *s2, int len)
{
	size_t	i;

	i = 0;
	if (s1[0] == '\n' && s2[0] == '\n')
		return (1);
	while (s1 && s1[i] == s2[i] && i < (size_t)len)
		i++;
	if (i - 1 == ft_strlen(s1))
		return (1);
	return (0);
}

void	check_sort(char *str, t_array *arr)
{
	if (is_sort(arr->size_a, arr->a) == 1 && arr->size_b == 0)
		write(1, "OK\n", 3);
	else if (is_sort(arr->size_a, arr->a) == 0 || arr->size_b != 0)
		write(1, "KO\n", 3);
	ft_free(arr);
	if (str)
		free(str);
	exit(0);
}

void	compare_op2(char *str, t_array *arr)
{
	if (ft_strcmp(str, "\n", 2))
		check_sort(str, arr);
	else
	{
		write(2, "Error\n", 6);
		ft_free(arr);
		free(str);
		exit(0);
	}
}

void	compare_op(char *str, t_array *arr)
{
	if (ft_strcmp(str, "sa\n", 4))
		s_a(arr);
	else if (ft_strcmp(str, "sb\n", 4))
		s_b(arr);
	else if (ft_strcmp(str, "ss\n", 4))
		s_s(arr);
	else if (ft_strcmp(str, "pa\n", 4))
		p_a(arr);
	else if (ft_strcmp(str, "pb\n", 4))
		p_b(arr);
	else if (ft_strcmp(str, "ra\n", 4))
		r_a(arr);
	else if (ft_strcmp(str, "rb\n", 4))
		r_b(arr);
	else if (ft_strcmp(str, "rr\n", 4))
		r_r(arr);
	else if (ft_strcmp(str, "rra\n", 5))
		r_ra(arr);
	else if (ft_strcmp(str, "rrb\n", 5))
		r_rb(arr);
	else if (ft_strcmp(str, "rrr\n", 5))
		r_rr(arr);
	else
		compare_op2(str, arr);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		init;
	char	*op;
	t_array	arr;

	i = 0;
	if (ft_error_digit(argc, argv) == 0)
		return (0);
	init = init_struct(argc, argv, &arr);
	if (init == 0)
		exit (0);
	if (ft_error(&arr, argc, 0) == 0)
		return (ft_free(&arr));
	op = get_next_line(0);
	while (op)
	{
		compare_op(op, &arr);
		free(op);
		op = get_next_line(0);
	}
	if (!op)
		check_sort(NULL, &arr);
	free(op);
	ft_free(&arr);
	return (0);
}
