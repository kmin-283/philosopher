/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doing.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:50:52 by kmin              #+#    #+#             */
/*   Updated: 2020/09/04 15:05:05 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		grab_fork(t_philo *ph)
{
	if (g_state == DIED)
		return (-1);
	pthread_mutex_lock(ph->m_right_fork);
	pthread_mutex_lock(ph->m_left_fork);
	messages(" has take a fork\n", ph);
	return (0);
}

int		eating(t_philo *ph)
{
	if (g_state == DIED)
		return (-1);
	else
	{
		grab_fork(ph);
		ph->last_meal = get_time();
		messages(" is eating\n", ph);
		usleep(ph->pd->time_to_eat);
		pthread_mutex_unlock(ph->m_left_fork);
		pthread_mutex_unlock(ph->m_right_fork);
	}
	return (0);
}

int		sleeping(t_philo *ph)
{
	if (g_state == DIED)
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
	if (g_state == DIED)
		return (-1);
	else
		messages(" is thinking\n", ph);
	return (0);
}

void	*is_die(void *tmp_ph)
{
	t_philo			*ph;
	unsigned long	current_time;

	ph = (t_philo *)tmp_ph;
	while (42 && g_state != DIED)
	{
		current_time = get_time();
		if (current_time - ph->last_meal > (unsigned long)ph->pd->time_to_die)
		{
			messages(" is died\n", ph);
			g_state = DIED;
			break ;
		}
	}
	return (NULL);
}
