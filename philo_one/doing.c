/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doing.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:50:52 by kmin              #+#    #+#             */
/*   Updated: 2020/09/07 20:34:56 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

void	grab_fork(t_philo *ph)
{
	pthread_mutex_lock(ph->m_right_fork);
	pthread_mutex_lock(ph->m_left_fork);
	messages(" has take a fork\n", ph);
}

void	eating(t_philo *ph)
{
	grab_fork(ph);
	ph->last_meal = get_time();
	messages(" is eating\n", ph);
	usleep(ph->pd->time_to_eat);
	pthread_mutex_lock(&ph->mutex->m_num_of_meals);
	ph->pd->num_of_meals++;
	pthread_mutex_unlock(&ph->mutex->m_num_of_meals);
	pthread_mutex_unlock(ph->m_left_fork);
	pthread_mutex_unlock(ph->m_right_fork);
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
