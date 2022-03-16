/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:47:48 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/16 09:19:29 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dumb.h"

t_dumb	s = {.win_x = WIN_X, .win_y = WIN_Y, .yes_x = DEFAULT_YES_X, .yes_y = DEFAULT_YES_Y, .no_x = DEFAULT_NO_X, .no_y = DEFAULT_NO_Y};

void
	open_texture(void)
{
	for (int i = 0; i < NBR_TXTR; i++) {
		s.txtr[i].ptr = mlx_xpm_file_to_image(s.mlx, txtr[i], &s.txtr[i].x, &s.txtr[i].y);
		if (!s.txtr[i].ptr)
			__exit(EXIT_FAILURE);
		s.txtr[i].addr = mlx_get_data_addr(s.txtr[i].ptr, &s.txtr[i].bpp, &s.txtr[i].size_line, &s.txtr[i].endian);
		if (!s.txtr[i].addr)
			__exit(EXIT_FAILURE);
	}
}

int
	engine(void)
{
	mlx_put_image_to_window(s.mlx, s.win, s.txtr[((s.is_done) ? I_KNEW : ARE_YOU)].ptr, 0, 0);
	if (!s.is_done)
	{
		mlx_put_image_to_window(s.mlx, s.win,s.txtr[((s.yes_pressed) ? YES_PRESSED : YES)].ptr, s.yes_x, s.yes_y);
		mlx_put_image_to_window(s.mlx, s.win,s.txtr[((s.no_pressed) ? NO_PRESSED : NO)].ptr, s.no_x, s.no_y);
		mlx_string_put(s.mlx, s.win, 10, 20, 0xFFFFFF, ((s.tip_on) ? TIP_ON_TXT : TIP_OFF));
	}
	// if (s.yes_pressed == 2)
	// 	s.is_done = 1;
	return (__SUCCESS);
}

t_boolean
	is_in_square(int c_x, int c_y, int sqrt_x, int sqrt_y)
{
	int	bottom_x = sqrt_x + BUTTON_X;
	int bottom_y = sqrt_y + BUTTON_Y;

	if (c_x < sqrt_x || c_x > bottom_x || c_y < sqrt_y || c_y > bottom_y)
		return (0);
	return (1);
}

void
	move_no(void)
{
	s.no_x = __random(WIN_X - BUTTON_X);
	s.no_y = __random(WIN_Y - BUTTON_Y);
}

int
	mouse_handler(int key)
{
	int x;
	int y;
	
	if (key != 1)
		return (1);
	mlx_mouse_get_pos(s.win, &x, &y);
	if (is_in_square(x, y, s.yes_x, s.yes_y))
	{
		s.yes_pressed = 1;
	}
	else if (is_in_square(x, y, s.no_x, s.no_y))
	{
		s.no_pressed = 1;
	}
	return (0);
}

int
	mouse_release(int key)
{
	int x;
	int y;

	if (key != 1)
		return (1);
	mlx_mouse_get_pos(s.win, &x, &y);
	if (is_in_square(x, y, s.yes_x, s.yes_y))
	{
		s.yes_pressed = 0;
		s.is_done = 1;
	}
	else if (is_in_square(x, y, s.no_x, s.no_y))
	{
		s.no_pressed = 0;
		move_no();
	}
	else
		s.yes_pressed = 0; s.no_pressed = 0;
	return (0);
}

int
	key_handler(int key)
{
	if (key == KEY_T)
		s.tip_on = 1;
	return (0);
}

int
	quit(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}

int
	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	s.mlx = mlx_init();
	if (s.mlx == NULL)
		return (EXIT_SUCCESS);
	open_texture();
	s.win = mlx_new_window(s.mlx, WIN_X, WIN_Y, PROGRAM_NAME);
	s.img.ptr = mlx_new_image(s.mlx, WIN_X, WIN_Y);
	s.img.addr = mlx_get_data_addr(s.img.ptr, &s.img.bpp, &s.img.size_line, &s.img.endian);
	// mlx_mouse_hook(s.win, mouse_handler, NULL);
	mlx_hook(s.win, RED_CROSS, (0L), quit, NULL);
	mlx_hook(s.win, 4, (0L), mouse_handler, NULL);
	mlx_hook(s.win, 5, (0L), mouse_release, NULL);
	mlx_key_hook(s.win, key_handler, NULL);
	mlx_loop_hook(s.mlx, engine, NULL);
	mlx_loop(s.mlx);
}
	
