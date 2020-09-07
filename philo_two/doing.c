/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doing.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:50:52 by kmin              #+#    #+#             */
/*   Updated: 2020/09/07 20:37:45 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_two.h"

void	grab_fork(t_philo *ph)
{
	sem_wait(ph->sems->s_forks);
	sem_wait(ph->sems->s_forks);
	messages(" has take a fork\n", ph);
}

void	eating(t_philo *ph)
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

void	sleeping(t_philo *ph)
{
	messages(" is sleeping\n", ph);
	usleep(ph->pd->time_to_sleep);
}

void	thinking(t_philo *ph)
{
	messages(" is thinking\n", ph);
}
