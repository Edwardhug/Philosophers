/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgabet <lgabet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:08:33 by lgabet            #+#    #+#             */
/*   Updated: 2023/11/27 13:35:08 by lgabet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct	s_philo
{
	int				number;
	pthread_mutex_t right_fork;
	// pthread_mutex_t *left_fork;
}				t_philo;

typedef struct s_main
{
	int			number_of_philo;
	long long	time_start;
	int			time_sleep;
	int			time_die;
	int			time_eat;
	int			total_eat;
	pthread_t	*thread;
	t_philo		*philo;
}				t_main;

int		is_no_numeric(char **av, int ac);
int		init_struct(t_main *var, int ac, char **arg);
int		ft_atoi(const char *s);
int 	get_actual_time();
void	init_threads(t_main *var);

#endif