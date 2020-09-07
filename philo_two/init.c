/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 19:04:07 by kmin              #+#    #+#             */
/*   Updated: 2020/09/07 17:15:27 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_two.h"

int		init_sems(t_sem *sems, t_pd *pd)
{
	if ((sems->s_forks = sem_open("forks", O_CREAT, 0644, pd->num_of_philo)) == SEM_FAILED)
		return (-1);
	if ((sems->s_write = sem_open("write", O_CREAT, 0644, WRITABLE)) == SEM_FAILED)
		return (-1);
	if ((sems->s_state = sem_open("state", O_CREAT, 0644, NORMAL)) == SEM_FAILED)
		return (-1);
	if ((sems->s_num_of_meals = sem_open("total_meals", O_CREAT, 0644, 1)) == SEM_FAILED)
		return (-1);
	return (0);
}

t_philo	*init_threads(t_pd *pd, t_sem *sems)
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
		ph[i].sems = sems;
		ph[i].program_start = get_time();
		ph[i].last_meal = ph[i].program_start;
		i++;
	}
	return (ph);
}
