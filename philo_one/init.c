/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 19:04:07 by kmin              #+#    #+#             */
/*   Updated: 2020/09/03 20:01:15 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		init_mutexes(t_mutex *mutexes, t_pd *pd)
{
	int i;

	i = 0;
	if (!(mutexes->m_forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * pd->num_of_philo)))
		return (-1);
	while (i < pd->num_of_philo)
	{
		pthread_mutex_init(&mutexes->m_forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&mutexes->m_write, NULL);
	pthread_mutex_init(&mutexes->m_died, NULL);
	return (0);
}

t_philo	*init_threads(t_pd *pd, t_mutex *mutexes)
{
	t_philo *ph;
	int		i;

	i = 0;
	if (!(ph = (t_philo *)malloc(sizeof(t_philo) * pd->num_of_philo)))
		return (NULL);
	while (i < pd->num_of_philo)
	{
		ph[i].philo_idx = i + 1;
		ph[i].pd = pd;
		ph[i].mutex = mutexes;
		ph[i].m_left_fork = &mutexes->m_forks[i];
		if (i - 1 < 0)
			ph[i].m_right_fork = &mutexes->m_forks[pd->num_of_philo];
		else
			ph[i].m_right_fork = &mutexes->m_forks[i - 1];
		i++;
	}
	return (ph);
}