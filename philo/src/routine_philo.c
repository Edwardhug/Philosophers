/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgabet <lgabet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:37:12 by lgabet            #+#    #+#             */
/*   Updated: 2023/11/28 13:45:19 by lgabet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void *routine_philo(void *arg)
{
    t_philo *philo = (t_philo *)arg;
	philo->time_start = get_actual_time();
	pthread_mutex_lock(&philo->var->write_mut);
	printf("%lld %d is thinking\n", (get_actual_time() - philo->time_start), philo->number);
	pthread_mutex_unlock(&philo->var->write_mut);
	return (0);
}