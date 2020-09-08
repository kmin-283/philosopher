/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doing.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:50:52 by kmin              #+#    #+#             */
/*   Updated: 2020/09/08 23:43:27 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

void	grab_fork(t_philo *ph)
{
	
}

void	eating(t_philo *ph)
{
	sem_wait(ph->sems->s_forks);
	sem_wait(ph->sems->s_forks);
	messages(" has take a fork\n", ph);
	ph->last_meal = get_time();
	messages(" is eating\n", ph);
	usleep(ph->pd->time_to_eat);
	sem_post(ph->sems->s_meal);
	ph->pd->num_of_meals++;
	sem_post(ph->sems->s_forks);
	sem_post(ph->sems->s_forks);
}

void	sleeping(t_philo *ph)
{

}

void	thinking(t_philo *ph)
{
	
}
