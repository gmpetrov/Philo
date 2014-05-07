/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_funct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/07 16:55:47 by gpetrov           #+#    #+#             */
/*   Updated: 2014/05/07 18:42:13 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "header.h"

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

void	eb_mlx(void)
{
	t_win		*env;
	t_img		*img;

	env = env_init();
	img = img_init();
	mlx_expose_hook(env->win, eb_expose_hook, img);
	mlx_key_hook(env->win, eb_mlx_key_hook, NULL);
	mlx_loop(env->mlx);
}

int		eb_mlx_key_hook(int keycode)
{
	if (keycode == KEY_ESC)
		ft_error("Merci pour le poisson.");
	return (0);
}

int		eb_expose_hook(t_img *img)
{
	t_win		*env;

	env = env_init();
	img->x = 50;
	// img->load_ptr = mlx_xpm_file_to_image(env->mlx, "srcs/philo3.xpm", &img->x, &img->y);
	img->load_ptr = choose_img("./srcs/philosophie.xpm", &img->x, &img->y);
	mlx_put_image_to_window(env->mlx, env->win, img->load_ptr, 200, 0);
	return (0);
}


