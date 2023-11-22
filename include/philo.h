/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgabet <lgabet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:08:33 by lgabet            #+#    #+#             */
/*   Updated: 2023/11/22 17:02:03 by lgabet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

int	is_no_numeric(char **av);

typedef struct	s_philo
{
	int				number;
	pthread_mutex_t *right_fork;
	pthread_mutex_t *left_fork;
}				t_philo;

typedef struct s_main
{
	long		time_start;
	int			time_sleep;
	int			time_die;
	int			time_eat;
	int			total_eat;
	t_philo		*philo;
}				t_main;

#endif