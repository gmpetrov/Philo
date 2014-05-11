/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_funct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/07 16:55:47 by gpetrov           #+#    #+#             */
/*   Updated: 2014/05/11 23:37:29 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"
#include "header.h"

void	*eb_mlx(void *unuse)
{
	t_win		*env;
	t_img		*img;

	(void)unuse;
	env = env_init();
	img = img_init();
	mlx_key_hook(env->win, eb_mlx_key_hook, NULL);
	mlx_expose_hook(env->win, eb_expose_hook, img);
	mlx_loop_hook(env->mlx, eb_loop_hook, img);
	mlx_loop(env->mlx);
	return (NULL);
}

int		eb_mlx_key_hook(int keycode)
{
	t_win	*env;
	t_img	*img;

	if (keycode == KEY_ESC)
	{
		img = img_init();
		env = env_init();
		if (img->img)
			mlx_destroy_image(env->mlx, img->img);
		free(img);
		free(env);
		ft_error("Merci pour le poisson.");
	}
	return (0);
}

int		eb_expose_hook(t_img *img)
{
	t_win		*env;

	env = env_init();
	img->x = 50;
	show_philo(env, img);
	return (0);
}

int		eb_loop_hook(t_img *img)
{
	eb_expose_hook(img);
	return (0);
}

void	eb_clean_map(t_img *img)
{
	int		x;
	int		y;

	x = 0;
	while (x <= WIDTH)
	{
		y = 0;
		while (y <= HEIGHT)
		{
			eb_put_pixel_to_img(img, x, y, 0x000000);
			y++;
		}
		x++;
	}
}
