/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 13:26:58 by kmin              #+#    #+#             */
/*   Updated: 2020/09/02 20:30:22 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

unsigned long	get_time(void)
{
	struct timeval	time;
	unsigned long	ret;

	gettimeofday(&time, NULL);
	ret = time.tv_usec + (time.tv_sec * 1000000);
	return (ret);
}

int		messages(const char *str, t_philo *ph)
{
	char			*tmp;
	char			*idx;
	unsigned long	current_time;

	current_time = get_time();
	tmp = ft_lltoa(current_time);
	idx = ft_lltoa(ph->philo_idx);
	pthread_mutex_lock(&ph->mutex->m_write);
	ft_putstr(tmp);
	ft_putstr(" ");
	ft_putstr(idx); 
	ft_putstr(str);
	pthread_mutex_unlock(&ph->mutex->m_write);
	free(tmp);
	free(idx);
	return (0);
}

int		grab_fork(t_philo *ph)
{
	pthread_mutex_lock(ph->m_left_fork);
	pthread_mutex_lock(ph->m_right_fork);
	messages(" has take a fork\n", ph);
	return (0);
}

void	eating(t_philo *ph)
{
	grab_fork(ph);
	usleep(ph->pd->time_to_eat);
	ph->last_meal += ph->pd->time_to_eat;
	pthread_mutex_unlock(ph->m_left_fork);
	pthread_mutex_unlock(ph->m_right_fork);
}

void	sleeping(t_philo *ph)
{
	usleep(ph->pd->time_to_sleep);
}

void	thinking(t_philo *ph)
{
	(void)ph;
	return ;
}

void	*print_do(void *tmp_ph)
{
	t_philo	*ph;

	ph = (t_philo *)tmp_ph;
	while (42)
	{
		eating(ph);
		sleeping(ph);
		thinking(ph);
	}
	return (NULL);
}

int		make_threads(t_philo **ph, t_pd *pd)
{
	int	i;

	i = 0;
	while (i < pd->num_of_philo)
	{
		(*ph)[i].last_meal = get_time();
		if (pthread_create(&(*ph)[i].thread, NULL, print_do, &(*ph)[i]) < 0)
		{
			ft_putstr("thread create error\n");
			return (-1);
		}
		i++;
	}
	i = 0;
	while (i < pd->num_of_philo)
	{
		pthread_join((*ph)[i].thread, NULL);
		i++;
	}
	return (0);
}

void	run(const char **argv)
{
	t_philo		*ph;
	t_mutex		mutexes;
	t_pd		pd;

	input_args(&pd, (const char **)argv);
	init_mutexes(&mutexes, &pd);
	ph = init_threads(&pd, &mutexes);
	make_threads(&ph, &pd);
	finish_threads(ph, &mutexes, &pd);
}

int		main(int argc, char **argv)
{
	if (argc < 5)
		ft_putstr("Error! You should input nessasary arguments!\n");
	else
		run((const char **)argv);
	return (0);
}