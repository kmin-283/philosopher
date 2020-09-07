/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doing.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:50:52 by kmin              #+#    #+#             */
/*   Updated: 2020/09/07 17:10:32 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_two.h"

int		grab_fork(t_philo *ph)
{
	if (ph->pd->state == DIED && ph->pd->state != FULL)
		return (-1);
	sem_wait(ph->sems->s_forks);
	sem_wait(ph->sems->s_forks);
	messages(" has take a fork\n", ph);
	return (0);
}

int		eating(t_philo *ph)
{
	if (ph->pd->state == DIED && ph->pd->state != FULL)
		return (-1);
	else
	{
		grab_fork(ph);
		ph->last_meal = get_time();
		messages(" is eating\n", ph);
		usleep(ph->pd->time_to_eat);
		sem_wait(ph->sems->s_num_of_meals);
		ph->pd->num_of_meals++;
		sem_post(ph->sems->s_num_of_meals);
		sem_post(ph->sems->s_forks);
		sem_post(ph->sems->s_forks);
	}
	return (0);
}

int		sleeping(t_philo *ph)
{
	if (ph->pd->state == DIED && ph->pd->state != FULL)
		return (-1);
	else
	{
		messages(" is sleeping\n", ph);
		usleep(ph->pd->time_to_sleep);
	}
	return (0);
}

int		thinking(t_philo *ph)
{
	if (ph->pd->state == DIED && ph->pd->state != FULL)
		return (-1);
	else
		messages(" is thinking\n", ph);
	return (0);
}
