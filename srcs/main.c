/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 20:09:52 by gpetrov           #+#    #+#             */
/*   Updated: 2014/05/11 22:09:50 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	fuck(void)
{
	int	i;

	i = 0;
	while (i < NB_PHILO)
	{
		pthread_join(g_philosophe[i].thread_philo, NULL);
		i++;
	}
}

void	init(void)
{
	int	i;

	i = 0;
	pthread_mutex_init(&(g_forks), NULL);
	while (i < NB_PHILO)
	{
		g_philosophe[i].id = i;
		g_philosophe[i].life = MAX_LIFE;
		g_philosophe[i].status = 'R';
		g_fork[i] = 0;
		g_fork[i] = 0;
		pthread_create(&(g_philosophe[i].thread_philo),
				NULL, actions, &(g_philosophe[i]));
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
		pthread_mutex_lock(&g_forks);
		if (philo->status != 'E')
			philo->life -= 1;
		if (philo->life <= 0)
		{
			philo->status = 'D';
			fuck();
			ft_putstr("A philosophe is dead\n");
			return (NULL);
		}
		pthread_mutex_unlock(&g_forks);
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
		pthread_create(&(thread_life[i]), NULL, life, &(g_philosophe[i]));
		i++;
	}
	pthread_create(&thread_graphique, NULL, eb_mlx, NULL);
	philo();
	return (0);
}
