/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:37:28 by lbuccher          #+#    #+#             */
/*   Updated: 2021/12/02 22:44:29 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include "../push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	if (s1[0] == '\n' && s2[0] == '\n')
		return (1);
	while (s1 && s1[i] == s2[i])
		i++;
	if (i - 1 == ft_strlen(s1))
		return (1);
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

void	compare_op2(char *str, t_array *arr)
{
	if (ft_strcmp(str, "\n"))
		check_sort(arr);
	else
	{
		write(1, "Error\n", 6);
		exit(0);
	}
}

void	compare_op(char *str, t_array *arr)
{
	if (ft_strcmp(str, "sa\n"))
		s_a(arr);
	else if (ft_strcmp(str, "sb\n"))
		s_b(arr);
	else if (ft_strcmp(str, "ss\n"))
		s_s(arr);
	else if (ft_strcmp(str, "pa\n"))
		p_a(arr);
	else if (ft_strcmp(str, "pb\n"))
		p_b(arr);
	else if (ft_strcmp(str, "ra\n"))
		r_a(arr);
	else if (ft_strcmp(str, "rb\n"))
		r_b(arr);
	else if (ft_strcmp(str, "rr\n"))
		r_r(arr);
	else if (ft_strcmp(str, "rra\n"))
		r_ra(arr);
	else if (ft_strcmp(str, "rrb\n"))
		r_rb(arr);
	else if (ft_strcmp(str, "rrr\n"))
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
	init = 1;
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
		op = get_next_line(0);
	}
	if (!op)
		check_sort(&arr);
	ft_free(&arr);
	return (0);
}
