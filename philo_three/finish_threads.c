/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 13:23:09 by kmin              #+#    #+#             */
/*   Updated: 2020/09/08 23:18:19 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

void		finish_semaphores(t_philo *ph, t_sem *sems)
{
	sem_unlink("forks");
	sem_unlink("write");
	sem_unlink("meal");
	sem_unlink("state");
	sem_unlink("state2");
	sem_close(sems->s_forks);
	sem_close(sems->s_write);
	sem_close(sems->s_meal);
	sem_close(sems->s_state);
	sem_close(sems->s_state2);
}

void	wait_and_exit(t_philo *ph)
{
	int	i;

	i = 0;
	waitpid(-1, NULL, 0);
	while (i < ph->pd->num_of_philo)
	{
		kill(ph->pid[i], SIGTERM);
		i++;
	}
	free(ph->pid);
}
