/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 20:09:52 by gpetrov           #+#    #+#             */
/*   Updated: 2014/05/10 19:16:18 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"

int				p_fork[NB_PHILO];
t_philo			philosophe[NB_PHILO];
pthread_mutex_t	forks;

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



void	eat(t_philo *philo)
{
	philo->status = 'E';
	p_fork[philo->id] = 1;
	p_fork[(philo->id + 1) % NB_PHILO] = 1;
	pthread_mutex_unlock(&forks);

	print_eat(philo, 1);
	
	usleep(EAT_T * 1000000);
	philo->life = MAX_LIFE;
	
	printf("Philosophe %d finished eating and has %d life points\n", philo->id, philo->life);
	
	pthread_mutex_lock(&forks);
	p_fork[philo->id] = 0;
	p_fork[(philo->id + 1) % NB_PHILO] = 0;
	pthread_mutex_unlock(&forks);
}

void	think(t_philo *philo)
{
	philo->status = 'T';
	p_fork[philo->id] = 1;
	pthread_mutex_unlock(&forks);

	printf("Philosophe %d is thinking\n", philo->id);

	usleep(THINK_T * 1000000);
	philo->life -= THINK_T;
	if (philo->life <= 0)
	{
		pthread_mutex_unlock(&forks);
		printf("Philosophe %d is dead\n- THE END -\n", philo->id);
		exit(0);
	}
	printf("Philosophe %d finished thinkig and has %d life points\n", philo->id, philo->life);
	while (philo->status != 'E')
	{
		pthread_mutex_lock(&forks);
		if (p_fork[(philo->id + 1) % NB_PHILO] == 0)
			eat(philo);
		else
			pthread_mutex_unlock(&forks);
	}
}

void	rest(t_philo *philo)
{
	pthread_mutex_unlock(&forks);
	if (philo->status == 'R')
		return ;
	philo->status = 'R';
	printf("Philosophe  %d is resting\n", philo->id);
	usleep(REST_T * 1000000);
	philo->life -= REST_T;
	printf("Philosophe %d finished resting and has %d Life points\n", philo->id, philo->life);
}

void	*actions(void *data)
{
	t_philo	*philo;
	time_t	start;
	int		left;
	int		right;

	philo = (t_philo *)data;
	start = time(NULL);
	while (42)
	{	
		if (time(NULL) > start + TIMEOUT)
		{
			ft_putstr("Now, it is time... To DAAAAAAAANCE!!!\n");
			exit(0);
		}
		pthread_mutex_lock(&forks);
		left = p_fork[philo->id];
		right = p_fork[(philo->id + 1) % NB_PHILO];
		if (left == 0 && right == 0 && philo->status != 'E')
			eat(philo);
		else if (left == 0 && right == 1 && philo->status == 'R')
			think(philo);
		else
			rest(philo);
	}
	return (NULL);
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
		pthread_create(&(philosophe[i].thread_philo), NULL, actions, &(philosophe[i]));
		i++;
	}
}

void	philo(t_data *data)
{
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
}

int		main(void)
{
	t_data	data;

	ft_putstr("ZBRA?\n");
	philo(&data);
	eb_mlx();
	return (0);
}
