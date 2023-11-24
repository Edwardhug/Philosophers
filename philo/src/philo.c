/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgabet <lgabet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:10:40 by lgabet            #+#    #+#             */
/*   Updated: 2023/11/24 18:06:38 by lgabet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void free_all(t_main *var)
{
	free(var->philo);
}

int	main(int ac, char **av)
{
	t_main	var;

	if ((ac != 5 && ac != 6) || is_no_numeric(av, ac))
		return (printf("Error with parameters\n"), 1);
	if (init_struct(&var, ac, av))
		return (printf("Malloc error during init\n"), 1);
	free_all(&var);
	return(0);
}