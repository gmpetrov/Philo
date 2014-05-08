/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 20:09:52 by gpetrov           #+#    #+#             */
/*   Updated: 2014/05/08 18:13:35 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
	while(42)
	{
		ft_putnbr(tmp->id);
		write(1, "\n", 1);
		usleep(100000);
		if (tmp->id == 7)
			write(1, "\n", 1);
		tmp = tmp->next;
	}
}

void	philo(t_data *data)
{
	t_philo	*philo;
	int		i;

	(void)data;
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
}

int		main(void)
{
	/*t_data	data;*/

	ft_putstr("ZBRA?\n");
	/*philo(&data);*/
	eb_mlx();
	return (0);
}
