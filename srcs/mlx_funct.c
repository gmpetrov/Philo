/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_funct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/07 16:55:47 by gpetrov           #+#    #+#             */
/*   Updated: 2014/05/10 23:40:48 by ebaudet          ###   ########.fr       */
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
	if (life > 80)
		return (color_norm(0, 255, 0));
	else if (life > 50)
		return (color_norm(0xD0, 0xFA, 0x58));
	else if (life > 35)
		return (color_norm(0xF5, 0xDA, 0x81));
	else if (life > 10)
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
	mlx_loop_hook(env->win, eb_loop_hook, NULL);

	mlx_loop(env->mlx);
	return (NULL);
}

int		eb_mlx_key_hook(int keycode)
{
	if (keycode == KEY_ESC)
		ft_error("Merci pour le poisson.");
	return (0);
}

void	wich_philo(t_win *env, int i)
{
	mlx_string_put(env->mlx, env->win, 0 + i * 100, 20, color_norm(0, 255, 255), "philosophe");
	mlx_string_put(env->mlx, env->win, 70 + i * 100, 20, color_norm(0, 255, 255), ft_itoa(i));
	mlx_string_put(env->mlx, env->win, 0 + i * 100, 40, color_norm(200, 200, 200), "etat :");
	if (philosophe[i].status == 'E')
		mlx_string_put(env->mlx, env->win, 50 + i * 100, 40, color_norm(0, 255, 255), "EAT");
	else if (philosophe[i].status == 'T')
		mlx_string_put(env->mlx, env->win, 50 + i * 100, 40, color_norm(0, 255, 255), "THINK");
	else if (philosophe[i].status == 'R')
		mlx_string_put(env->mlx, env->win, 50 + i * 100, 40, color_norm(0, 255, 255), "REST");
	else
		mlx_string_put(env->mlx, env->win, 50 + i * 100, 40, color_norm(0, 255, 255), "don't know");
	mlx_string_put(env->mlx, env->win, 0 + i * 100, 60, color_norm(200, 200, 200), "life :");
	mlx_string_put(env->mlx, env->win, 50 + i * 100, 60, color_life(philosophe[i].life),
		ft_itoa(philosophe[i].life));
}

void	show_philo(t_win *env, t_img *img)
{
	/*mlx_clear_window(env->mlx, env->win);*/
	/*eb_clean_map(img);
	if (img->load_ptr)
		mlx_destroy_image(env->mlx, img->load_ptr);*/
	/*img->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	img->data = mlx_get_data_addr(img->img, &img->bpp, &img->size_line
		, &img->endian);*/
	/*img->load_ptr = choose_img("./images/philosophe.xpm", &img->x, &img->y);*/


	int		i;

	i = 0;
	while (i < NB_PHILO)
	{
		wich_philo(env, i);
		i++;
	}



	/*mlx_string_put(env->mlx, env->win, 0, 20, color_norm(0, 255, 255), "philosophe");
	mlx_string_put(env->mlx, env->win, 0, 40, color_norm(200, 200, 200), "etat :");
	if (philosophe[0].status == 'E')
		mlx_string_put(env->mlx, env->win, 50, 40, color_norm(0, 255, 255), "EAT");
	else if (philosophe[0].status == 'T')
		mlx_string_put(env->mlx, env->win, 50, 40, color_norm(0, 255, 255), "THINK");
	else if (philosophe[0].status == 'R')
		mlx_string_put(env->mlx, env->win, 50, 40, color_norm(0, 255, 255), "REST");
	else
		mlx_string_put(env->mlx, env->win, 50, 40, color_norm(0, 255, 255), "don't know");
	mlx_string_put(env->mlx, env->win, 0, 60, color_norm(200, 200, 200), "life :");
	mlx_string_put(env->mlx, env->win, 50, 60, color_life(philosophe[0].life),
		ft_itoa(philosophe[0].life));*/


	/*mlx_put_image_to_window(env->mlx, env->win, img->load_ptr, 200, 0);*/
	usleep(50000);
	/*mlx_destroy_image(env->win, img->img);*/
	show_philo(env, img);
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


