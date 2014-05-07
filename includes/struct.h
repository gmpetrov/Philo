/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/07 16:51:58 by gpetrov           #+#    #+#             */
/*   Updated: 2014/05/07 17:01:21 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_win
{
	void			*mlx;
	void			*win;
	struct s_img	*img;
}					t_win;

typedef struct		s_img
{
	void			*img;
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;
}					t_img;


typedef struct		s_data
{
	char			*scene_name;
	char			origin;
	char			dir;
	char			color;
	int				win_size_x;
	int				win_size_y;
}					t_data;

#endif
