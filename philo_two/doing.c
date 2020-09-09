/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doing.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:50:52 by kmin              #+#    #+#             */
/*   Updated: 2020/09/09 13:54:56 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_two.h"

void	eating(t_philo *ph)
{
	sem_wait(ph->sems->s_forks);
	messages(" has take a fork\n", ph);
	messages(" is eating\n", ph);
	ph->last_meal = get_time();
	usleep(ph->pd->time_to_eat);
	sem_wait(ph->sems->s_meal);
	ph->pd->num_of_meals++;
	sem_post(ph->sems->s_meal);
	sem_post(ph->sems->s_forks);
}
