/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 20:09:52 by gpetrov           #+#    #+#             */
/*   Updated: 2014/05/11 21:57:08 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"

void	fuck(void)
{
	int	i;

	i = 0;
	while (i < NB_PHILO)
	{
		pthread_join(philosophe[i].thread_philo, NULL);
		i++;
	}
}

void	init(void)
{
	int	i;

	i = 0;
	pthread_mutex_init(&(forks), NULL);
	while (i < NB_PHILO)
	{
		philosophe[i].id = i;
		philosophe[i].life = MAX_LIFE;
		philosophe[i].status = 'R';
		p_fork[i] = 0;
		p_fork[i] = 0;
		pthread_create(&(philosophe[i].thread_philo),
				NULL, actions, &(philosophe[i]));
		i++;
	}
}

void	philo(void)
{
	init();
	fuck();
}

void	*life(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (42)
	{
		usleep(1000000);
		pthread_mutex_lock(&forks);
		if (philo->status != 'E')
			philo->life -= 1;
		if (philo->life <= 0)
		{
			philo->status = 'D';
			fuck();
			ft_putstr("A philosophe is dead\n");
			return (NULL);
		}
		pthread_mutex_unlock(&forks);
	}
}

int		main(void)
{
	pthread_t	thread_graphique;
	pthread_t	thread_life[NB_PHILO];
	int			i;

	i = 0;
	while (i < NB_PHILO)
	{
		pthread_create(&(thread_life[i]), NULL, life, &(philosophe[i]));
		i++;
	}
	pthread_create(&thread_graphique, NULL, eb_mlx, NULL);
	philo();
	return (0);
}
