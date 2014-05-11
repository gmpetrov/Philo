/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 22:31:24 by gpetrov           #+#    #+#             */
/*   Updated: 2014/05/11 22:23:21 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft.h"

t_philo	*create_philo(t_philo *philo, int i)
{
	t_philo	*new;
	t_philo	*tmp;

	new = (t_philo *)malloc(sizeof(t_philo));
	new->life = MAX_LIFE;
	new->id = i;
	new->prev = NULL;
	new->next = NULL;
	philo->prev = new;
	tmp = philo;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
	return (philo);
}

t_philo	*make_it_circular(t_philo *philo)
{
	t_philo	*tmp;

	tmp = philo;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = philo;
	return (philo);
}

void	test(t_philo *philo)
{
	t_philo *tmp;

	tmp = philo;
	while (42)
	{
		ft_putnbr(tmp->id);
		write(1, "\n", 1);
		usleep(100000);
		if (tmp->id == 7)
			write(1, "\n", 1);
		tmp = tmp->next;
	}
}
