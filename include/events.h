/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 22:22:26 by zelhajou          #+#    #+#             */
/*   Updated: 2023/12/23 15:02:42 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
#define EVENTS_H

#include "graphics.h"

//keys
#define KEY_ESC 53
#define KEY_LEFT 123
#define KEY_RIGHT 124
#define KEY_UP 126
#define KEY_DOWN 125
// Mouse
#define MOUSE_LEFT_CLICK 1
#define MOUSE_RIGHT_CLICK 2
#define MOUSE_MIDDLE_CLICK 3
#define ZOOM_IN_KEY 4
#define ZOOM_OUT_KEY 5

int ft_handle_keypress(int key, t_gfx_env *env);
int	ft_handle_mouse(int button, int x, int y, t_gfx_env *env);
void ft_setup_hooks(t_gfx_env *env);

#endif