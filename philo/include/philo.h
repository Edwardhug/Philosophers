/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgabet <lgabet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:08:33 by lgabet            #+#    #+#             */
/*   Updated: 2024/02/05 15:03:25 by lgabet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdbool.h>

typedef struct s_main	t_main;

typedef struct s_philo
{
	int				number;
	int				number_of_meal;
	long long		time_start;
	long long		time_last_meal;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	t_main			*var;
}				t_philo;

typedef struct s_main
{
	int				number_of_philo;
	int				time_sleep;
	int				time_die;
	int				time_eat;
	int				total_eat;
	bool			finished;
	pthread_mutex_t	write_mut;
	pthread_mutex_t	global_mut;
	pthread_mutex_t	*fork;
	pthread_t		*thread;
	t_philo			*philo;
}				t_main;

int			is_no_numeric(char **av, int ac);
int			init_struct(t_main *var, int ac, char **arg);
int			ft_atoi(const char *s);
long long	get_actual_time(void);
int			init_threads(t_main *var);
void		*routine_philo(void *arg);
int			philo_must_continue(t_philo *philo);
void		check_dead_or_finished(t_main *var);
void		print_info(t_philo *philo, char *str);
void		only_one_philo(t_philo *philo);

#endif