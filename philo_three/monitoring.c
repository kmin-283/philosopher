/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 17:01:00 by kmin              #+#    #+#             */
/*   Updated: 2020/09/08 23:49:38 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

void	*which_state(void *tmp_ph)
{
	t_philo *ph;

	ph = (t_philo *)tmp_ph;
	sem_wait(ph->sems->s_state);
	ph->pd->state = DIED;
	return (NULL);
}

void	*which_state2(void *tmp_ph)
{
	t_philo *ph;

	ph = (t_philo *)tmp_ph;
	sem_wait(ph->sems->s_state2);
	ph->pd->state = DIED;
	sem_post(ph->sems->s_state2);
	return (NULL);
}

void	*is_full(void *tmp_ph)
{
	t_philo	*ph;
	int		cnt;

	ph = (t_philo *)tmp_ph;
	cnt = 0;
	while (42 && ph->pd->state != DIED)
	{
		sem_wait(ph->sems->s_meal);
		cnt++;
		if (cnt == (ph->pd->num_of_philo * ph->pd->num_of_must_eat))
		{
			usleep(FOR_PHILOS_ORDERING + 50);
			sem_wait(ph->sems->s_write);
			ft_putstr("All philosophers is full\n");
			ph->pd->state = DIED;
			sem_post(ph->sems->s_state);
			sem_post(ph->sems->s_state2);
			sem_post(ph->sems->s_write);
		}
	}
	return (NULL);
}

void	*is_die(void *tmp_ph)
{
	t_philo	*ph;

	ph = (t_philo *)tmp_ph;
	while (42 && ph->pd->state != DIED)
	{
		if (get_time() - ph->last_meal > ph->pd->time_to_die)
		{
			messages(" is died\n", ph);
			ph->pd->state = DIED;
			sem_post(ph->sems->s_state);
			sem_post(ph->sems->s_state2);
		}
	}
	return (NULL);
}
