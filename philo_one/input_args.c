/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 13:59:03 by kmin              #+#    #+#             */
/*   Updated: 2020/09/02 17:09:20 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

long	input_arg(const char *input)
{
	long	ret;
	
	ret = ft_atoi(input);
	return (ret);
}

void	input_args(t_pd *pd, const char **argv)
{
	pd->num_of_philo = (int)input_arg(argv[1]);
	pd->time_to_die = input_arg(argv[2]);
	pd->time_to_eat = input_arg(argv[3]);
	pd->time_to_sleep = input_arg(argv[4]);
	if (argv[5])
		pd->num_of_must_eat = (int)input_arg(argv[5]);
	g_forks += pd->num_of_philo;
}
