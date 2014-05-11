/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/10 19:35:16 by gpetrov           #+#    #+#             */
/*   Updated: 2014/05/11 22:23:32 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft.h"

void	print_eat(t_philo *philo, int version)
{
	if (version == 1)
	{
		write(1, "Philosophe ", ft_strlen("Philosophe "));
		ft_putnbr(philo->id);
		write(1, " is eating\n", ft_strlen(" is eating\n"));
	}
	else
	{
		write(1, "Philosophe ", ft_strlen("Philosophe "));
		ft_putnbr(philo->id);
		write(1, " finished eating and has ",
				ft_strlen(" finished eating and has "));
		ft_putnbr(philo->life);
		write(1, " life points\n", ft_strlen(" life points\n"));
	}
}

void	print_think(t_philo *philo, int version)
{
	if (version == 1)
	{
		write(1, "Philosophe ", ft_strlen("Philosophe "));
		ft_putnbr(philo->id);
		write(1, " is thinking\n", ft_strlen(" is thinking\n"));
	}
	else
	{
		write(1, "Philosophe ", ft_strlen("Philosophe "));
		ft_putnbr(philo->id);
		write(1, " finished eating and has ",
			ft_strlen(" finished eating and has "));
		ft_putnbr(philo->life);
		write(1, " life points\n", 1);
	}
}

void	print_rest(t_philo *philo, int version)
{
	if (version == 1)
	{
		write(1, "Philosophe ", ft_strlen("Philosophe "));
		ft_putnbr(philo->id);
		write(1, " is resting\n", ft_strlen(" is resting\n"));
	}
	else
	{
		write(1, "Philosophe ", ft_strlen("Philosophe "));
		ft_putnbr(philo->id);
		write(1, " finished resting and has ",
				ft_strlen(" finished resting and has "));
		ft_putnbr(philo->life);
		write(1, " life points\n", ft_strlen(" life points\n"));
	}
}
