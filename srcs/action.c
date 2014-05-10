/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/10 19:46:29 by gpetrov           #+#    #+#             */
/*   Updated: 2014/05/10 22:01:16 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		eat(t_philo *philo)
{
	philo->status = 'E';
	p_fork[philo->id] = 1;
	p_fork[(philo->id + 1) % NB_PHILO] = 1;
	pthread_mutex_unlock(&forks);

	print_eat(philo, 1);
	
	usleep(EAT_T * 1000000);
	philo->life = MAX_LIFE;
	
	print_eat(philo, 2);	
	pthread_mutex_lock(&forks);
	p_fork[philo->id] = 0;
	p_fork[(philo->id + 1) % NB_PHILO] = 0;
	pthread_mutex_unlock(&forks);
}

static void		think(t_philo *philo)
{
	philo->status = 'T';
	p_fork[philo->id] = 1;
	pthread_mutex_unlock(&forks);
	print_think(philo, 1);
	usleep(THINK_T * 1000000);
	print_think(philo, 2);
	while (philo->status != 'E')
	{	
		pthread_mutex_lock(&forks);
		if (p_fork[(philo->id + 1) % NB_PHILO] == 0)
			eat(philo);
		else
			pthread_mutex_unlock(&forks);
	}
}

static void		rest(t_philo *philo)
{
	pthread_mutex_unlock(&forks);
	if (philo->status == 'R')
		return ;
	philo->status = 'R';
	print_rest(philo, 1);
	usleep(REST_T * 1000000);
	print_rest(philo, 2);
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
		if (time(NULL) > start + TIMEOUT)
		{
			fuck();
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


