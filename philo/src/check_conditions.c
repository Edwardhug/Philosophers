/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_conditions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgabet <lgabet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:29:36 by lgabet            #+#    #+#             */
/*   Updated: 2023/11/28 16:22:42 by lgabet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void check_dead_or_finished(t_main *var)
{
	// int	i;

	// i = 0;
	// while (i < var->number_of_philo)
	// {
	// 	if (var->philo[i]->number)
	// }
}

int	philo_must_continue(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->var->number_of_philo)
	{
		if (philo->var->philo[i].alive == false)
			return (0);	// may have some data race
		i++;
	}
	if (philo->number_of_meal == philo->var->total_eat)
		return (0);
	return (1);
}

int	is_no_numeric(char **av, int ac)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}