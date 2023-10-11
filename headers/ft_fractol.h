/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:41:49 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/11 12:38:51 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include <math.h>
# include "../projects/headers_2/ft_first_layer.h"
# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdio.h>
# include <stdbool.h>
# include <pthread.h>

# define WIN_WIDTH 1080
# define WIN_HEIGHT 1080
# define MAX_ITER_MAN 500
# define MAX_ITER_BURN 10000
# define MAX_ITER_JUL 2147483647
# define MLX_ERROR -1
# define ZOOM_IN_FACTOR 0.9
# define ZOOM_OUT_FACTOR 1.1
# define NUM_THREADS 50

typedef struct s_complex
{
	double	re;
	double	re_sq;
	double	im;
	double	im_sq;
}	t_complex;

typedef struct s_coords
{
	int			px;
	int			py;
	t_complex	z;
	t_complex	c;
	t_complex	julia;
	int			iter;
	int			max_iter;
}	t_coords;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		*fractal;
	int			small_side;
	int			color;
	int			color_man;
	int			color_jul;
	int			color_burn;
	int			launch;
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	double		move_x;
	double		move_y;
	long double	mouse_x;
	long double	mouse_y;
	double		fe;
	double		smoothed_value;
	t_coords	coord;
	t_img		img;
}	t_data;

typedef struct s_thread
{
	t_data		ptr_data;
	int			x_start;
	int			x_end;
}	t_thread;

/*args check*/
int		ft_valid_args(t_data *data, int argc, char **argv);
int		ft_julia_args(t_data *data, char **argv);
void	ft_error_msg(void);
/*init functions*/
int		ft_init(t_data *data);
int		ft_hooks_init(t_data *data);
void	ft_draw_handler(t_data *data);
/*destroy function*/
int		ft_destroy_fractal(t_data *data);
/*hooks handler functions*/
int		ft_mouse_handler(int keycode, int px, int py, t_data *data);
int		ft_key_handler(int keycode, t_data *data);
void	ft_reset_fractal(t_data *data);
/*zoom functions*/
void	ft_zoom_in(t_data *data, int px, int py);	
void	ft_zoom_out(t_data *data, int px, int py);
/*draw functions*/
void	ft_set_fractal_data(t_data *data);
void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_draw(t_data *data);
/*Mandelbrot functions*/
void	ft_mandelbrot_init(t_data *data);
void	*ft_mandelbrot(void *thread_data);
void    ft_mandelbrot_decorator(t_data *data);
/*Julia functions*/
void	ft_julia_init(t_data *data);
void	*ft_julia(void *thread_data);
void    ft_julia_decorator(t_data *data);
/*Burning Ship functions*/
void	ft_burning_ship_init(t_data *data);
void	*ft_burning_ship(void *thread_data);
void    ft_burningship_decorator(t_data *data);

#endif
