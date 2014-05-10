/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_funct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/07 16:55:47 by gpetrov           #+#    #+#             */
/*   Updated: 2014/05/10 20:45:07 by ebaudet          ###   ########.fr       */
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

void	*eb_mlx(void *unuse)
{
	t_win		*env;
	t_img		*img;

	(void)unuse;
	env = env_init();
	img = img_init();
	mlx_expose_hook(env->win, eb_expose_hook, img);
	mlx_key_hook(env->win, eb_mlx_key_hook, NULL);
	mlx_loop(env->mlx);
	return (NULL);
}

int		eb_mlx_key_hook(int keycode)
{
	if (keycode == KEY_ESC)
		ft_error("Merci pour le poisson.");
	return (0);
}

void	show_philo(t_win *env, t_img *img)
{
	img->load_ptr = choose_img("./images/philosophe.xpm", &img->x, &img->y);
	mlx_string_put(env->mlx, env->win, 0, 20, color_norm(0, 255, 255), "philosophe");
	mlx_string_put(env->mlx, env->win, 0, 40, color_norm(200, 200, 200), "etat :");
	mlx_string_put(env->mlx, env->win, 50, 40, color_norm(0, 255, 255), "EAT");
	mlx_string_put(env->mlx, env->win, 0, 60, color_norm(200, 200, 200), "life :");
	mlx_string_put(env->mlx, env->win, 50, 60, color_life(100), "100");
	mlx_string_put(env->mlx, env->win, 50, 70, color_life(80), "80");
	mlx_string_put(env->mlx, env->win, 50, 80, color_life(50), "50");
	mlx_string_put(env->mlx, env->win, 50, 90, color_life(35), "35");
	mlx_string_put(env->mlx, env->win, 50, 100, color_life(10), "10");

}

int		eb_expose_hook(t_img *img)
{
	t_win		*env;

	env = env_init();
	img->x = 50;
	// img->load_ptr = mlx_xpm_file_to_image(env->mlx, "srcs/philo3.xpm", &img->x, &img->y);
	show_philo(env, img);
	mlx_put_image_to_window(env->mlx, env->win, img->load_ptr, 200, 0);
	return (0);
}


