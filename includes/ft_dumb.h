/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dumb.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:31:57 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/15 22:42:20 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DUMB_H
# define FT_DUMB_H

#include "libft.h"
#include "mlx.h"

#define PROGRAM_NAME		"ft_dumb"

#define YES_PRESSED_TXTR	"./textures/yes_pressed.xpm"
#define YES_TXTR			"./textures/yes.xpm"
#define NO_PRESSED_TXTR		"./textures/no_pressed.xpm"
#define NO_TXTR				"./textures/no.xpm"
#define I_KNEW_TXTR			"./textures/i_knew.xpm"
#define ARE_YOU_TXTR		"./textures/are_you.xpm"
#define NBR_TXTR			6
#define BUTTON_X			80
#define BUTTON_Y			40

#define	WIN_X				500
#define WIN_Y				500

#define DEFAULT_YES_X		70
#define DEFAULT_YES_Y		400
#define DEFAULT_NO_X		WIN_Y - (80 + 70)
#define DEFAULT_NO_Y		400

#define TIP_ON_TXT			"There is only one possible option ;)"
#define TIP_OFF				"Press F is you need help"

char	*txtr[NBR_TXTR] =	{YES_PRESSED_TXTR
						, YES_TXTR
						, NO_PRESSED_TXTR
						, NO_TXTR
						, I_KNEW_TXTR
						, ARE_YOU_TXTR};

# if defined(__APPLE__) && defined(__MACH__)
#  define KEY_T		3
#  define RED_CROSS	17
# else
#  define KEY_T		102
#  define RED_CROSS	33
# endif

enum {
	YES,
	YES_PRESSED,
	NO,
	NO_PRESSED,
	I_KNEW,
	ARE_YOU
};

typedef struct s_dumb {
	
	void	*mlx;
	void	*win;
	uint32_t	win_x;
	uint32_t	win_y;
	t_img	img;
	t_boolean	yes_pressed : 1;
	t_boolean	no_pressed : 1;
	t_boolean	is_done : 1;
	t_boolean	tip_on : 1;
	t_img		txtr[NBR_TXTR];
	uint32_t	yes_x;
	uint32_t	yes_y;
	uint32_t	no_x;
	uint32_t	no_y;
} t_dumb;

#endif