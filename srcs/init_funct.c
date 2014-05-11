/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_funct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/07 16:57:24 by gpetrov           #+#    #+#             */
/*   Updated: 2014/05/11 18:47:23 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_data		*data_init(void)
{
	static t_data	*data = NULL;

	if (data == NULL)
	{
		if (!(data = (t_data *)malloc(sizeof(t_data))))
			ft_error("erreur malloc");
	}
	return (data);
}

t_win		*env_init(void)
{
	static t_win	*win = NULL;

	if (win == NULL)
	{
		if (!(win = (t_win *)malloc(sizeof(t_win))))
			ft_error("erreur malloc");
		win->mlx = mlx_init();
		win->win = mlx_new_window(win->mlx, WIDTH, HEIGHT
			, NAME);
		win->img = img_init();
	}
	return (win);
}

t_img		*img_init(void)
{
	t_win	*win;
	t_img	*img;

	win = env_init();
	img = (t_img *)malloc(sizeof(t_img));
	img->img = mlx_new_image(win->mlx, WIDTH, HEIGHT);
	img->data = mlx_get_data_addr(img->img, &img->bpp, &img->size_line
		, &img->endian);
	return (img);
}
