/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 20:17:14 by gpetrov           #+#    #+#             */
/*   Updated: 2014/05/11 20:14:23 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

/*
**	MACRO FOR MLX
*/

# define WIDTH		1000
# define HEIGHT		500
# define KEY_ESC	65307
# define NAME		"Philo"

/*
**	MACRO FOR PHILO
*/

# define MAX_LIFE	10
# define EAT_T		3
# define REST_T		8
# define THINK_T	22
# define TIMEOUT	15
# define NB_PHILO	7
/*
**	INCLUDE
*/
# include <mlx.h>
# include <pthread.h>
# include "libft.h"
# include "struct.h"

/*
**	GLOBAL VARS
*/
int				p_fork[NB_PHILO];
t_philo			philosophe[NB_PHILO];
pthread_mutex_t	forks;
/*
**	PROTOTYPES
*/

void	fuck(void);
t_data	*data_init(void);
t_win	*env_init(void);
t_img	*img_init(void);
void	*eb_mlx(void *unuse);
int		eb_expose_hook(t_img *img);
int		eb_mlx_key_hook(int keycode);

/*
**	action.c
*/
void	*actions(void *data);
/*
**	print.c
*/
void	print_eat(t_philo *philo, int version);
void	print_think(t_philo *philo, int version);
void	print_rest(t_philo *philo, int version);
void	*life(void *data);

/*
** error.c
*/
void	ft_error(char *str);

#endif
