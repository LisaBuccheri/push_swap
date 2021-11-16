/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:31:25 by lbuccher          #+#    #+#             */
/*   Updated: 2021/11/16 19:31:38 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef	struct	type_array
{
	int	*a;
	int	*b;
	int	*g_arr;
	int	size_a;
	int	size_b;
	int	g_size;
	int	nb_move;
}		t_array;

int		ft_atoi(const char *str);
int		is_twice(int argc, int *a);
int		*init_array(int argc, char *argv[], char arr);

void	ft_putchar(char c);
void	ft_putnbr(int n);
void	sa(t_array *arr);
void	sb(t_array *arr);
void	ss(t_array *arr);
void	pa(t_array *arr);
void	pb(t_array *arr);
void	ra(t_array *arr);
void	rb(t_array *arr);
void	rr(t_array *arr);
void	rra(t_array *arr);
void	rrb(t_array *arr);
void	rrr(t_array *arr);

void	sort(t_array *arr);
void	sort2(int *t, t_array *arr);
int		**get_pieces(t_array *arr);
int		*reinit_tempo(int *tempo, int arr_size, t_array *arr);
int		*sort_tempo(int *tempo, t_array *arr);
int		check_small(t_array *arr);
int		check_second(t_array *arr);
int		is_sort(t_array *arr, int *array);
int		invert_sort(t_array *arr, int *array);
int		three_nb(t_array *arr);

#endif