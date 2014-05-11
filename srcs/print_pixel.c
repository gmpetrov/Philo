/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/11 21:30:22 by ebaudet           #+#    #+#             */
/*   Updated: 2014/05/11 21:51:45 by ebaudet          ###   ########.fr       */
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
	int		result;

	result = 0;
	if (life > (((int)MAX_LIFE * 80) / 100))
		result = color_norm(0x00, 0xFF, 0x00);
	else if (life > (((int)MAX_LIFE * 50) / 100))
		result = color_norm(0xD0, 0xFA, 0x58);
	else if (life > (((int)MAX_LIFE * 35) / 100))
		result = color_norm(0xF5, 0xDA, 0x81);
	else if (life > (((int)MAX_LIFE * 10) / 100))
		result = color_norm(0xFF, 0x80, 0x00);
	else
		result = color_norm(0xFE, 0x2E, 0x2E);
	return (result);
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

void	*choose_img(char *image, int *x, int *y)
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
