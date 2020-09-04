/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 13:59:03 by kmin              #+#    #+#             */
/*   Updated: 2020/09/04 13:55:33 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	input_args(t_pd *pd, const char **argv)
{
	pd->num_of_philo = (int)ft_atoi(argv[1]);
	pd->time_to_die = ft_atoi(argv[2]);
	pd->time_to_eat = ft_atoi(argv[3]) * 1000;
	pd->time_to_sleep = ft_atoi(argv[4]) * 1000;
	if (argv[5])
		pd->num_of_must_eat = (int)ft_atoi(argv[5]);
}
