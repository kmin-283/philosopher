/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 17:01:00 by kmin              #+#    #+#             */
/*   Updated: 2020/09/07 16:39:34 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_two.h"

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
				sem_wait(ph[i].sems->s_write);
				ft_putstr("All philosophers is full\n");
				sem_wait(ph->sems->s_state);
				ph[i].pd->state = FULL;
				sem_post(ph->sems->s_state);
				sem_post(ph[i].sems->s_write);
			}
			i++;
		}
	}
	return (NULL);
}

void	*is_die(void *tmp_ph)
{
	t_philo			*ph;
	unsigned long	current_time;

	ph = (t_philo *)tmp_ph;
	while (42 && ph->pd->state != DIED && ph->pd->state != FULL)
	{
		current_time = get_time();
		if (current_time - ph->last_meal > (unsigned long)ph->pd->time_to_die)
		{
			messages(" is died\n", ph);
			sem_wait(ph->sems->s_state);
			ph->pd->state = DIED;
			sem_post(ph->sems->s_state);
			break ;
		}
	}
	return (NULL);
}
