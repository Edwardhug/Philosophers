/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_conditions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgabet <lgabet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:29:36 by lgabet            #+#    #+#             */
/*   Updated: 2023/12/06 21:16:57 by lgabet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	are_all_full(t_main *var)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < var->number_of_philo)
	{
		pthread_mutex_lock(&var->global_mut);
		if (var->philo[i].number_of_meal == var->total_eat)
			count++;
		pthread_mutex_unlock(&var->global_mut);
		i++;
	}
	if (count == var->number_of_philo)
		return (1);
	return (0);
}

int	have_dead_philo(t_main *var)
{
	int	i;

	i = 0;
	while (i < var->number_of_philo)
	{
		pthread_mutex_lock(&var->global_mut);
		if ((get_actual_time() - var->philo[i].time_last_meal) > var->time_die)
		{
			pthread_mutex_unlock(&var->global_mut);
			print_info(&var->philo[i], "died");
			return (1);
		}
		pthread_mutex_unlock(&var->global_mut);
		i++;
	}
	return (0);
}

void	check_dead_or_finished(t_main *var)
{
	bool	b;

	b = true;
	while (b == true && var->number_of_philo != 1)
	{
		if (are_all_full(var) || have_dead_philo(var))
			b = false;
	}
}

int	philo_must_continue(t_philo *philo)
{
	pthread_mutex_lock(&philo->var->global_mut);
	if (philo->var->finished == false
		&& (philo->number_of_meal != philo->var->total_eat))
	{
		pthread_mutex_unlock(&philo->var->global_mut);
		return (1);
	}
	pthread_mutex_unlock(&philo->var->global_mut);
	return (0);
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
