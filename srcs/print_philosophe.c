/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philosophe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/11 21:28:42 by ebaudet           #+#    #+#             */
/*   Updated: 2014/05/11 22:20:29 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"
#include "header.h"

void	eb_table(t_img *img, int width, int height)
{
	int		x;
	int		y;

	x = 200;
	while (x <= width)
	{
		y = 150;
		while (y <= height)
		{
			eb_put_pixel_to_img(img, x, y, 0x777777);
			y++;
		}
		x++;
	}
}

void	wich_philo(t_win *env, int i, int x, int y)
{
	mlx_string_put(env->mlx, env->win, 0 + x, 20 + y, color_norm(0, 255, 255),
		"philosophe");
	mlx_string_put(env->mlx, env->win, 70 + x, 20 + y, color_norm(0, 255, 255),
		ft_itoa(i + 1));
	mlx_string_put(env->mlx, env->win, 0 + x, 40 + y, color_norm(200, 200, 200),
		"etat :");
	if (g_philosophe[i].status == 'E')
		mlx_string_put(env->mlx, env->win, 50 + x, 40 + y,
			color_norm(0, 255, 0), "EAT");
	else if (g_philosophe[i].status == 'T')
		mlx_string_put(env->mlx, env->win, 50 + x, 40 + y,
			color_norm(0, 255, 255), "THINK");
	else if (g_philosophe[i].status == 'R')
		mlx_string_put(env->mlx, env->win, 50 + x, 40 + y,
			color_norm(0, 255, 255), "REST");
	else if (g_philosophe[i].status == 'D')
		mlx_string_put(env->mlx, env->win, 50 + x, 40 + y,
			color_norm(255, 0, 0), "DEAD");
	else
		mlx_string_put(env->mlx, env->win, 50 + x, 40 + y,
			color_norm(0, 255, 255), "don't know");
	mlx_string_put(env->mlx, env->win, 0 + x, 60 + y,
		color_norm(200, 200, 200), "life :");
	mlx_string_put(env->mlx, env->win, 50 + x, 60 + y,
		color_life(g_philosophe[i].life), ft_itoa(g_philosophe[i].life));
}

void	show_philo(t_win *env, t_img *img)
{
	if (img->img)
		mlx_destroy_image(env->mlx, img->img);
	img->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	img->data = mlx_get_data_addr(img->img, &img->bpp, &img->size_line
		, &img->endian);
	eb_clean_map(img);
	eb_table(img, 700, 400);
	mlx_put_image_to_window(env->mlx, env->win, img->img, 0, 0);
	wich_philo(env, 0, 70, 250);
	wich_philo(env, 1, 300, 70);
	wich_philo(env, 2, 500, 70);
	wich_philo(env, 3, 720, 150);
	wich_philo(env, 4, 720, 300);
	wich_philo(env, 5, 500, 400);
	wich_philo(env, 6, 300, 400);
}
