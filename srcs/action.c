/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/10 19:46:29 by gpetrov           #+#    #+#             */
/*   Updated: 2014/05/11 22:15:28 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		eat(t_philo *philo)
{
	philo->status = 'E';
	g_fork[philo->id] = 1;
	g_fork[(philo->id + 1) % (int)NB_PHILO] = 1;
	pthread_mutex_unlock(&g_forks);
	usleep((int)EAT_T * 1000000);
	philo->life = (int)MAX_LIFE;
	pthread_mutex_lock(&g_forks);
	g_fork[philo->id] = 0;
	g_fork[(philo->id + 1) % (int)NB_PHILO] = 0;
	pthread_mutex_unlock(&g_forks);
}

static void		think(t_philo *philo)
{
	philo->status = 'T';
	g_fork[philo->id] = 1;
	pthread_mutex_unlock(&g_forks);
	usleep((int)THINK_T * 1000000);
	while (philo->status != 'E')
	{
		pthread_mutex_lock(&g_forks);
		if (g_fork[(philo->id + 1) % (int)NB_PHILO] == 0)
			eat(philo);
		else
			pthread_mutex_unlock(&g_forks);
	}
}

static void		rest(t_philo *philo)
{
	pthread_mutex_unlock(&g_forks);
	if (philo->status == 'R')
		return ;
	philo->status = 'R';
	usleep((int)REST_T * 1000000);
}

static void		timeout(time_t *start)
{
	if (time(NULL) > *start + (int)TIMEOUT)
	{
		fuck();
		ft_putstr("Now, it is time... To DAAAAAAAANCE!!!\n");
		exit(0);
	}
}

void			*actions(void *data)
{
	t_philo	*philo;
	time_t	start;
	int		left;
	int		right;

	philo = (t_philo *)data;
	start = time(NULL);
	while (42)
	{
		timeout(&start);
		pthread_mutex_lock(&g_forks);
		left = g_fork[philo->id];
		right = g_fork[(philo->id + 1) % (int)NB_PHILO];
		if (left == 0 && right == 0 && philo->status != 'E')
			eat(philo);
		else if (left == 0 && right == 1 && philo->status == 'R')
			think(philo);
		else
			rest(philo);
	}
	return (NULL);
}
