/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 13:59:03 by kmin              #+#    #+#             */
/*   Updated: 2020/09/04 17:19:30 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

static int	check_args_validity(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int			input_args(t_pd *pd, const char **argv)
{
	int i;

	i = 1;
	while (argv[i])
	{
		if (!check_args_validity(argv[i]))
		{
			ft_putstr("Error! You should input numeric arguments!\n");
			return (-1);
		}
		i++;
	}
	pd->num_of_meals = 0;
	pd->state = ALIVE;
	pd->num_of_philo = (int)ft_atoi(argv[1]);
	pd->time_to_die = ft_atoi(argv[2]);
	pd->time_to_eat = ft_atoi(argv[3]) * 1000;
	pd->time_to_sleep = ft_atoi(argv[4]) * 1000;
	if (argv[5])
		pd->num_of_must_eat = (int)ft_atoi(argv[5]);
	return (0);
}
