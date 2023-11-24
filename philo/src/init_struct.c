/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgabet <lgabet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:16:49 by lgabet            #+#    #+#             */
/*   Updated: 2023/11/24 17:34:18 by lgabet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_struct(t_main *var, int ac, char **arg)
{
    var->number_of_philo = ft_atoi(arg[1]);
    var->time_die = ft_atoi(arg[2]);
    var->time_eat = ft_atoi(arg[3]);
    var->time_sleep = ft_atoi(arg[4]);
    if (ac ==  6)
        var->total_eat = ft_atoi(arg[5]);
    else
        var->total_eat = -1;
    var->philo = malloc(sizeof(t_philo) * var->number_of_philo);
    if (!var->philo)
        return (1);
    return (0);
}
