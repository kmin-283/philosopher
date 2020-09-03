/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 13:27:18 by kmin              #+#    #+#             */
/*   Updated: 2020/09/02 20:56:20 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include "utils.h"

typedef struct		s_mutexes
{
	pthread_mutex_t	*m_forks;
	pthread_mutex_t	m_write;
}					t_mutex;

typedef struct		s_philo_data
{
	int		num_of_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	int		num_of_must_eat;
}					t_pd;

typedef struct			s_philo
{
	pthread_t			thread;
	pthread_mutex_t		*m_left_fork;
	pthread_mutex_t		*m_right_fork;
	t_mutex				*mutex;
	t_pd				*pd;
	int					philo_idx;
	unsigned long		last_meal;
}						t_philo;

/*
**					input_args.c
*/
long		input_arg(const char *input);
void		input_args(t_pd *pd, const char **argv);
/*
**					init.c
*/
t_philo		*init_threads(t_pd *pd, t_mutex *mutexes);
int			init_mutexes(t_mutex *mutexes, t_pd *pd);
/*
**					finish_threads.c
*/
void		finish_threads(t_philo *ph, t_mutex *mutexes, t_pd *pd);

#endif