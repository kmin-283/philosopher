/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 14:09:20 by kmin              #+#    #+#             */
/*   Updated: 2020/09/07 19:14:31 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <unistd.h>
# include <stdlib.h>

void	ft_putstr(const char *str);
int		ft_strlen(const char *str);
int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);
void	ft_putnbr_fd(unsigned long n, int fd);

#endif