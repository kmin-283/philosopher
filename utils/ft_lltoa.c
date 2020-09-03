/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 21:33:11 by kmin              #+#    #+#             */
/*   Updated: 2020/09/02 17:56:02 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static	size_t	ft_check_digit(long long n)
{
	size_t				i;
	unsigned long long	tmp_n;

	i = 0;
	if (n == 0)
		i = 1;
	if (n < 0)
	{
		tmp_n = -n;
		i++;
	}
	else
		tmp_n = n;
	while (tmp_n)
	{
		i++;
		tmp_n /= 10;
	}
	return (i);
}

char			*ft_lltoa(long long n)
{
	char				*ptr;
	char				*dicimal;
	size_t				len;
	unsigned long long	temp;
	unsigned int		i;

	dicimal = "0123456789";
	len = ft_check_digit(n);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (ptr)
	{
		temp = n < 0 ? -n : n;
		ptr[0] = '-';
		if (n < 0)
			i = 1;
		ptr[len] = '\0';
		while (len-- > i)
		{
			ptr[len] = dicimal[temp % 10];
			temp /= 10;
		}
	}
	return (ptr);
}
