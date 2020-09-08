/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 13:26:58 by kmin              #+#    #+#             */
/*   Updated: 2020/09/08 23:34:18 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000L + time.tv_usec / 1000L);
}

int		messages(const char *str, t_philo *ph)
{
	long	current_time;

	sem_wait(ph->sems->s_write);
	current_time = get_time();
	if (ph->pd->state != DIED)
	{
		ft_putnbr_fd(current_time - ph->program_start, 1);
		ft_putstr("ms idx ");
		ft_putnbr_fd(ph->philo_idx, 1);
		ft_putstr(str);
	}
	sem_post(ph->sems->s_write);
	return (0);
}

void	print_do(t_philo *ph)
{
	pthread_t	died;
	pthread_t	state;

	pthread_create(&died, NULL, is_die, (void *)ph);
	pthread_create(&state, NULL, which_state2, (void *)ph);
	pthread_detach(died);
	pthread_detach(state);
	while (42 && ph->pd->state != DIED)
	{
		eating(ph);
		messages(" is sleeping\n", ph);
		usleep(ph->pd->time_to_sleep);
		messages(" is thinking\n", ph);
	}
}

int		make_process(t_philo *ph, t_pd *pd)
{
	pthread_t	full;
	pthread_t	state;
	int			i;

	i = 0;
	while (i < pd->num_of_philo)
	{
		if ((ph->pid[i] = fork()) == -1)
		{
			ft_putstr("Error in make child process\n");
			return (-1);
		}
		if (ph->pid[i++] == 0)
		{
			ph->philo_idx = i;
			print_do(ph);
			exit(0);
		}
		usleep(FOR_PHILOS_ORDERING);
	}
	pthread_create(&full, NULL, is_full, (void *)ph);
	pthread_create(&state, NULL, which_state, (void *)ph);
	pthread_detach(full);
	pthread_detach(state);
	wait_and_exit(ph);
	return (0);
}

int		main(int argc, char **argv)
{
	t_philo		ph;
	t_sem		sems;
	t_pd		pd;

	if (argc < 5)
		ft_putstr("Error! You should enter at least 4 arguments!\n");
	else
	{
		if (input_args(&pd, (const char **)argv) == -1)
			return (0);
		if (init_sems(&sems, &pd) == -1)
			return (0);
		init_struct(&ph, &pd, &sems);
		make_process(&ph, &pd);
		finish_semaphores(&ph, &sems);
	}
	return (0);
}
