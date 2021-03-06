/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/07 16:51:58 by gpetrov           #+#    #+#             */
/*   Updated: 2014/05/11 23:20:43 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <pthread.h>

typedef struct		s_win
{
	void			*mlx;
	void			*win;
	struct s_img	*img;
}					t_win;

typedef struct		s_img
{
	void			*img;
	void			*load_ptr;
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;
	int				x;
	int				y;
}					t_img;

typedef struct		s_philo
{
	int				id;
	pthread_t		thread_philo;
	char			status;
	int				life;
	struct s_philo	*prev;
	struct s_philo	*next;
}					t_philo;

#endif
