/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_funct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/07 16:55:47 by gpetrov           #+#    #+#             */
/*   Updated: 2014/05/11 21:05:23 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "header.h"

int		color_norm(int red, int green, int blue)
{
	int		color;

	red = (red > 0xFF ? 0xFF : red);
	green = (green > 0xFF ? 0xFF : green);
	blue = (blue > 0xFF ? 0xFF : blue);
	red = (red < 0x00 ? 0x00 : red);
	green = (green < 0x00 ? 0x00 : green);
	blue = (blue < 0x00 ? 0x00 : blue);
	color = (red << 16) + (green << 8) + blue;
	return (color);
}

int		color_life(int life)
{
	if (life > (MAX_LIFE * 80 / 100))
		return (color_norm(0, 255, 0));
	else if (life > (MAX_LIFE * 50 / 100))
		return (color_norm(0xD0, 0xFA, 0x58));
	else if (life > (MAX_LIFE * 35 / 100))
		return (color_norm(0xF5, 0xDA, 0x81));
	else if (life > (MAX_LIFE * 10 / 100))
		return (color_norm(0xFF, 0x80, 0x00));
	else
		return (color_norm(0xFE, 0x2E, 0x2E));
}

void		*choose_img(char *image, int *x, int *y)
{
	t_win		*env;
	void		*result;

	env = env_init();
	if ((result = mlx_xpm_file_to_image(env->mlx,
				image, x, y)) == NULL)
	{
		ft_putstr("mauvais chemin d'image : ");
		ft_error(image);
	}
	return (result);
}

int		eb_loop_hook(t_img *img)
{
	eb_expose_hook(img);
	return (0);
}

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
	if (keycode == KEY_ESC)
		ft_error("Merci pour le poisson.");
	return (0);
}

void	wich_philo(t_win *env, int i, int x, int y)
{
	mlx_string_put(env->mlx, env->win, 0 + x, 20 + y, color_norm(0, 255, 255), "philosophe");
	mlx_string_put(env->mlx, env->win, 70 + x, 20 + y, color_norm(0, 255, 255), ft_itoa(i + 1));
	mlx_string_put(env->mlx, env->win, 0 + x, 40 + y, color_norm(200, 200, 200), "etat :");
	if (philosophe[i].status == 'E')
		mlx_string_put(env->mlx, env->win, 50 + x, 40 + y, color_norm(0, 255, 0), "EAT");
	else if (philosophe[i].status == 'T')
		mlx_string_put(env->mlx, env->win, 50 + x, 40 + y, color_norm(0, 255, 255), "THINK");
	else if (philosophe[i].status == 'R')
		mlx_string_put(env->mlx, env->win, 50 + x, 40 + y, color_norm(0, 255, 255), "REST");
	else if (philosophe[i].status == 'D')
		mlx_string_put(env->mlx, env->win, 50 + x, 40 + y, color_norm(255, 0, 0), "DEAD");
	else
		mlx_string_put(env->mlx, env->win, 50 + x, 40 + y, color_norm(0, 255, 255), "don't know");
	mlx_string_put(env->mlx, env->win, 0 + x, 60 + y, color_norm(200, 200, 200), "life :");
	mlx_string_put(env->mlx, env->win, 50 + x, 60 + y, color_life(philosophe[i].life),
		ft_itoa(philosophe[i].life));
}

void	eb_put_pixel_to_img(t_img *img, int x, int y, int color)
{
	unsigned int	mgcv;
	int				i;
	t_win			*env;

	env = env_init();
	mgcv = mlx_get_color_value(env->mlx, color);
	i = x * 4 + y * img->size_line;
	img->data[i] = (mgcv & 0xFF);
	img->data[i + 1] = (mgcv & 0xFF00) >> 8;
	img->data[i + 2] = (mgcv & 0xFF0000) >> 16;
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

void	show_philo(t_win *env, t_img *img)
{
	if (img->img)
		mlx_destroy_image(env->mlx, img->img);
	img->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	img->data = mlx_get_data_addr(img->img, &img->bpp, &img->size_line
		, &img->endian);
	eb_clean_map(img);
	eb_table(img, 700, 400);
	/*img->load_ptr = choose_img("./images/philosophe.xpm", &img->x, &img->y);*/
	mlx_put_image_to_window(env->mlx, env->win, img->img, 0, 0);
	wich_philo(env, 0, 70, 250);
	wich_philo(env, 1, 300, 70);
	wich_philo(env, 2, 500, 70);
	wich_philo(env, 3, 720, 150);
	wich_philo(env, 4, 720, 300);
	wich_philo(env, 5, 500, 400);
	wich_philo(env, 6, 300, 400);
}

int		eb_expose_hook(t_img *img)
{
	t_win		*env;

	env = env_init();
	img->x = 50;
	// img->load_ptr = mlx_xpm_file_to_image(env->mlx, "srcs/philo3.xpm", &img->x, &img->y);
	show_philo(env, img);
	/*mlx_destroy_image(env->win, img->img);*/
	return (0);
}


