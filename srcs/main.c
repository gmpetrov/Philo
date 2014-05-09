/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 20:09:52 by gpetrov           #+#    #+#             */
/*   Updated: 2014/05/10 00:10:59 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"

int				p_fork[NB_PHILO];
t_philo			philosophe[NB_PHILO];
pthread_mutex_t	mute = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t	forks[NB_PHILO];

void	*actions(void *data)
{
	t_philo	*philo;
	time_t	start;

	philo = (t_philo *)data;
	start = time(NULL);
	(void)philo;
	while (42)
	{
		/* TEST TIMEOUT */
		if (time(NULL) > start + TIMEOUT)
		{
			ft_putstr("Now, it is time... To DAAAAAAAANCE!!!\n");
			exit(0);
		}
	}

	return (NULL);
}

void	init(void)
{
	int	i;

	i = 0;
	while (i < NB_PHILO)
	{
		philosophe[i].id = i;
		philosophe[i].life = MAX_LIFE; 
		philosophe[i].status = 'R';
		p_fork[i] = 0;	
		pthread_mutex_init(&(forks[i]), NULL);
		pthread_create(&(philosophe[i].thread_philo), NULL, actions, &(philosophe[i]));
		i++;
	}
}

void	philo(t_data *data)
{
	/*t_philo	*philo;*/
	int		i;

	i = 0;
	(void)data;
	ft_putstr("Init Threads\n");
	init();
	while (i < NB_PHILO)
	{
		pthread_join(philosophe[i].thread_philo, NULL);
		i++;
	}
	ft_putstr("End Threads\n");
	/*
	philo = (t_philo *)malloc(sizeof(t_philo));
	philo->id = 1;
	philo->life = MAX_LIFE;
	i = 2;
	while (i <=  7)
	{
		philo = create_philo(philo, i);
		i++;
	}
	philo = make_it_circular(philo);
	test(philo);
	ft_putstr("Salut ca va ?\n");
	*/
}

int		main(void)
{
	t_data	data;

	ft_putstr("ZBRA?\n");
	philo(&data);
	eb_mlx();
	return (0);
}
