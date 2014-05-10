/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 20:17:14 by gpetrov           #+#    #+#             */
/*   Updated: 2014/05/10 19:21:17 by ebaudet          ###   ########.fr       */
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

# define MAX_LIFE	4
# define EAT_T		2
# define REST_T		2
# define THINK_T	2
# define TIMEOUT	60
# define NB_PHILO	7
/*
**	INCLUDES
*/

# include <mlx.h>
# include <pthread.h>
# include "libft.h"
# include "struct.h"

/*
**	PROTOTYPES
*/

t_data	*data_init(void);
t_win	*env_init(void);
t_img	*img_init(void);
void	*eb_mlx(void *unuse);
int		eb_expose_hook(t_img *img);
int		eb_mlx_key_hook(int keycode);

/*
** error.c
*/
void	ft_error(char *str);

#endif
