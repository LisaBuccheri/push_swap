/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:28:48 by lbuccher          #+#    #+#             */
/*   Updated: 2021/11/26 13:37:19 by lbuccher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_error(t_array *arr)
{
	if (is_sort(arr->size_a, arr->a) == 1)
		return (0);
	return (1);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	str_cmp(int argc, char *argv[])
{
	int	i;
	int	j;
	int	k;
	int	l;
	int	dup;

	i = 0;
	j = 0;
	dup = 0;
	// la fonction ne verifie pas tous les nombres elle avance en prennent le 1e et 2e puis le 2e et 3e
	while (++i < argc - 1)
	{
		k = i + 1;
		l = 0;
		while (argv[i][j] && argv[k][l])
		{
			if (argv[i][j] == argv[k][l])
				dup ++;
			j++;
			l++;
		}
		if (dup == ft_strlen(argv[i]))
			return (0);
		k++;
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

int	is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' && str[i + 1])
		{
			if (str[i + 1] < '0' || str[i + 1] > '9')
				return (0);
		}		
		else if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
