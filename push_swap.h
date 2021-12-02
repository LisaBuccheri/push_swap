/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:31:25 by lbuccher          #+#    #+#             */
/*   Updated: 2021/12/01 18:38:52 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

typedef struct type_array
{
	int	*a;
	int	*b;
	int	*g_arr;
	int	size_a;
	int	size_b;
	int	g_size;
	int	nb_move;
}		t_array;

int		ft_atoi(const char *str, int *stat);
int		*init_array(int argc, char *argv[], char arr);
int		is_sort(int size, int *array);
int		is_digit(char *str);
int		str_cmp(int argc, char *argv[]);
int		is_duplicate(t_array *arr);

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
void	sort_four(int i, int small_int, t_array *arr);
void	sort_five(int i, int small_int, int second_small, t_array *arr);

void	init_a(t_array *arr);
int		init_struct(int argc, char **argv, t_array *arr);
void	radix_sort(t_array *arr);
void	sort_little(int nb, t_array *arr);

int		ft_error(t_array *arr, int argc, int status);
int		ft_error_digit(int argc, char *argv[]);
int		ft_error_duplicate(t_array *arr);
int		ft_error_int(int stat, int *arr);
int		ft_free(t_array *arr);
int		max_binary(t_array *arr);

int		*sort_tempo(int *tempo, int size);
int		sort_three(t_array *arr);
int		check_small(t_array *arr);
int		check_second(t_array *arr);

#endif
