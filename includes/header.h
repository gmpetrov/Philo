/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 20:17:14 by gpetrov           #+#    #+#             */
/*   Updated: 2014/05/07 17:01:20 by gpetrov          ###   ########.fr       */
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


/*
**	INCLUDES
*/

# include <mlx.h>
# include "libft.h"
# include "struct.h"

/*
**	PROTOTYPES
*/

t_data	*data_init(void);
t_win	*env_init(void);
t_img		*img_init(void);
void	eb_mlx(void);
int		eb_expose_hook(t_img *img);
int		eb_mlx_key_hook(int keycode);

#endif
