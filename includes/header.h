/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 20:17:14 by gpetrov           #+#    #+#             */
/*   Updated: 2014/05/11 21:55:05 by ebaudet          ###   ########.fr       */
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

# define MAX_LIFE	5
# define EAT_T		2
# define REST_T		3
# define THINK_T	3
# define TIMEOUT	60
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

void			fuck(void);
t_data			*data_init(void);
t_win			*env_init(void);
t_img			*img_init(void);
void			*eb_mlx(void *unuse);
int				eb_expose_hook(t_img *img);
int				eb_mlx_key_hook(int keycode);

/*
**	action.c
*/
void			*actions(void *data);
/*
**	print.c
*/
void			print_eat(t_philo *philo, int version);
void			print_think(t_philo *philo, int version);
void			print_rest(t_philo *philo, int version);
void			*life(void *data);

/*
**	error.c
*/
void			ft_error(char *str);

/*
**	print_pixel.c
*/
int				color_norm(int red, int green, int blue);
int				color_life(int life);
void			eb_put_pixel_to_img(t_img *img, int x, int y, int color);
void			*choose_img(char *image, int *x, int *y);

/*
**	mlx_funct.c
*/
void			*eb_mlx(void *unuse);
int				eb_mlx_key_hook(int keycode);
int				eb_expose_hook(t_img *img);
int				eb_loop_hook(t_img *img);
void			eb_clean_map(t_img *img);

/*
**	print_philosophe.c
*/
void			eb_table(t_img *img, int width, int height);
void			wich_philo(t_win *env, int i, int x, int y);
void			show_philo(t_win *env, t_img *img);

#endif
