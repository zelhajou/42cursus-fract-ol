/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 01:05:50 by zelhajou          #+#    #+#             */
/*   Updated: 2023/12/31 16:34:40 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <math.h>
# include <mlx.h>
# include <limits.h>
# include <stdbool.h>

// Window
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 800

// keys
# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP 126
# define KEY_DOWN 125
// Mouse
# define MOUSE_LEFT_CLICK 1
# define MOUSE_RIGHT_CLICK 2
# define MOUSE_MIDDLE_CLICK 3
# define ZOOM_IN_KEY 4
# define ZOOM_OUT_KEY 5

typedef struct s_complex
{
	double	real;
	double	imaginary;
}	t_complex;

typedef struct s_image
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_fractal_config
{
	char	type;
	double	julia_x;
	double	julia_y;
}	t_fractal_config;

typedef struct s_fractol
{
	// Window and image info
	void				*mlx_connextion;
	void				*mlx_window;
	t_image				image;
	// complex numbers
	t_complex			cst;
	t_complex			pixel;
	// Fractal specific parameters
	int					max_iterations;
	double				zoom;
	t_point				offset;
	int					fractal_choice;
	t_fractal_config	fractal_config;
}	t_fractol;

// fractol configuration
void	ft_display_message(void);
void	ft_init_fractal(t_fractol *fractol, int argc, char *argv[]);

// Graphics
void	ft_setup_window(t_fractol *fractol);
void	ft_init_window(t_fractol *fractol);
void	ft_initialize_image(t_fractol *fractol);
int		ft_close_window(t_fractol *fractol);

// Coloring and Drawing
int		ft_determine_color(int iterations, int max_iterations);
void	ft_put_pixel_to_image(t_fractol *fractol, int x, int y, int color);
double	ft_scale_coordinate_x(t_fractol *fractol, int x);
double	ft_scale_coordinate_y(t_fractol *fractol, int y);
void	ft_draw_fractal_pixel(t_fractol *fractol, int x, int y);

// Rendring and fractal sets
int		ft_render_fractal(t_fractol *fractol);
void	ft_setup_fractal_params(t_fractol *fractol);
int		ft_iterate_fractal(t_complex z, t_complex c, int max_iterations);
int		ft_calculate_mandelbrot(t_fractol *fractol, int max_iterations);
int		ft_calculate_julia(t_fractol *fractol, int max_iterations);

// Events
void	ft_setup_hooks(t_fractol *fractol);
int		ft_handle_keypress(int key, t_fractol *fractol);
int		ft_handle_mouse(int button, int x, int y, t_fractol *fractol);
int		ft_handle_mouse_move(int x, int y, t_fractol *fractol);

// libft
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *s);
double	ft_process_fractional_part(const char *str);
double	ft_atof(const char *str);
bool	ft_is_digit(char c);

// utils
bool	ft_validate_atof_input(const char *str);
void	ft_init_fractal(t_fractol *fractol, int argc, char *argv[]);
void	ft_initialize_fractal(t_fractol *fractol);
void	ft_handle_julia_parameters(int argc, char *argv[], t_fractol *fractol);
void	ft_validate_arguments(int argc, char *argv[], t_fractol *fractol);
void	ft_display_message(void);

#endif
