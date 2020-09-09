/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 17:01:00 by kmin              #+#    #+#             */
/*   Updated: 2020/09/09 14:16:52 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

void	*is_full(void *tmp_ph)
{
	t_philo	*ph;
	int		i;

	ph = (t_philo *)tmp_ph;
	while (42 && ph[0].pd->state != FULL && ph[0].pd->state != DIED)
	{
		i = 0;
		while (i < ph[0].pd->num_of_philo && ph[0].pd->state != FULL &&
		ph[0].pd->state != DIED)
		{
			if (ph[i].pd->num_of_meals ==
			(ph[0].pd->num_of_philo * ph[0].pd->num_of_must_eat))
			{
				pthread_mutex_lock(&ph[i].mutex->m_write);
				ft_putstr("All philosophers is full\n");
				pthread_mutex_lock(&ph->mutex->m_state);
				ph[i].pd->state = FULL;
				pthread_mutex_unlock(&ph->mutex->m_state);
				pthread_mutex_unlock(&ph[i].mutex->m_write);
			}
			i++;
		}
	}
	return (NULL);
}

void	*is_die(void *tmp_ph)
{
	t_philo			*ph;

	ph = (t_philo *)tmp_ph;
	while (42 && ph->pd->state != DIED && ph->pd->state != FULL)
	{
		if (get_time() - ph->last_meal > ph->pd->time_to_die)
		{
			messages(" is died\n", ph);
			pthread_mutex_lock(&ph->mutex->m_state);
			ph->pd->state = DIED;
			pthread_mutex_unlock(&ph->mutex->m_state);
			break ;
		}
	}
	return (NULL);
}
