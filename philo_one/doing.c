/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doing.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:50:52 by kmin              #+#    #+#             */
/*   Updated: 2020/09/09 14:14:19 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

void	eating(t_philo *ph)
{
	pthread_mutex_lock(ph->m_right_fork);
	pthread_mutex_lock(ph->m_left_fork);
	messages(" has take a fork\n", ph);
	ph->last_meal = get_time();
	messages(" is eating\n", ph);
	usleep(ph->pd->time_to_eat);
	pthread_mutex_lock(&ph->mutex->m_num_of_meals);
	ph->pd->num_of_meals++;
	pthread_mutex_unlock(&ph->mutex->m_num_of_meals);
	pthread_mutex_unlock(ph->m_left_fork);
	pthread_mutex_unlock(ph->m_right_fork);
}
