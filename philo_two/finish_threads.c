/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 13:23:09 by kmin              #+#    #+#             */
/*   Updated: 2020/09/07 15:26:26 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_two.h"

void		finish_threads(t_philo *ph, t_sem *sems, t_pd *pd)
{
	sem_unlink("forks");
	sem_unlink("write");
	sem_unlink("state");
	if (pd->num_of_must_eat != -1)
	{
		sem_unlink("total_meals");
		sem_close(sems->s_num_of_meals);
	}
	sem_close(sems->s_forks);
	sem_close(sems->s_write);
	sem_close(sems->s_state);
	free(ph);
}
