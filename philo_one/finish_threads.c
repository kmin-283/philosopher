/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 13:23:09 by kmin              #+#    #+#             */
/*   Updated: 2020/09/04 21:08:28 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

void		finish_threads(t_philo *ph, t_mutex *mutexes, t_pd *pd)
{
	int i;

	i = 0;
	while (i < pd->num_of_philo)
	{
		pthread_mutex_destroy(&(mutexes->m_forks)[i]);
		i++;
	}
	pthread_mutex_destroy(&(mutexes->m_write));
	pthread_mutex_destroy(&(mutexes->m_state));
	pthread_mutex_destroy(&(mutexes->m_num_of_meals));
	free(ph);
	free(mutexes->m_forks);
}
