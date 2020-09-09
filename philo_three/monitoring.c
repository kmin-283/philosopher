/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 17:01:00 by kmin              #+#    #+#             */
/*   Updated: 2020/09/09 14:55:09 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

void	*convert_state_in_parent(void *tmp_ph)
{
	t_philo *ph;

	ph = (t_philo *)tmp_ph;
	sem_wait(ph->sems->s_state_main);
	ph->pd->state = DIED;
	return (NULL);
}

void	*convert_state_in_child(void *tmp_ph)
{
	t_philo *ph;

	ph = (t_philo *)tmp_ph;
	sem_wait(ph->sems->s_state_philo);
	ph->pd->state = DIED;
	sem_post(ph->sems->s_state_philo);
	return (NULL);
}

void	*is_full(void *tmp_ph)
{
	t_philo	*ph;
	int		cnt;

	ph = (t_philo *)tmp_ph;
	cnt = 0;
	while (42 && ph->pd->state != DIED && ph->pd->state != FULL)
	{
		sem_wait(ph->sems->s_meal);
		cnt++;
		if (cnt == (ph->pd->num_of_philo * ph->pd->num_of_must_eat))
		{
			ph->pd->state = FULL;
			sem_post(ph->sems->s_state_main);
			sem_post(ph->sems->s_state_philo);
			usleep(FOR_PHILOS_ORDERING + 50);
			sem_wait(ph->sems->s_write);
			ft_putstr("All philosophers is full\n");
			sem_post(ph->sems->s_write);
			break ;
		}
	}
	return (NULL);
}

void	*is_die(void *tmp_ph)
{
	t_philo	*ph;

	ph = (t_philo *)tmp_ph;
	while (42 && ph->pd->state != DIED && ph->pd->state != FULL)
	{
		if (get_time() - ph->last_meal > ph->pd->time_to_die)
		{
			messages(" is died\n", ph);
			ph->pd->state = DIED;
			sem_post(ph->sems->s_state_main);
			sem_post(ph->sems->s_state_philo);
			sem_post(ph->sems->s_meal);
			break ;
		}
	}
	return (NULL);
}
