/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:38:56 by cscelfo           #+#    #+#             */
/*   Updated: 2023/06/26 16:27:52 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_fractol.h"

void	ft_julia_init(t_data *data)
{
	data->coord.iter = 0;
	data->coord.z.re = data->x_min + (data->coord.px + data->move_x)
		* (data->x_max - data->x_min) / data->small_side;
	data->coord.z.im = data->y_max - (data->coord.py + data->move_y)
		* (data->y_max - data->y_min) / data->small_side;
	data->coord.z.re_sq = data->coord.z.re * data->coord.z.re;
	data->coord.z.im_sq = data->coord.z.im * data->coord.z.im;
}

void	*ft_julia(void *thread_d)
{
    t_thread *thread_data = (t_thread *)thread_d;
    t_data *data = &thread_data->ptr_data;
    pthread_mutex_t mutex;

    pthread_mutex_init(&mutex, NULL);
    data->coord.px = thread_data->x_start;
	while (data->coord.px < thread_data->x_end)
	{
		data->coord.py = 0;
		while (data->coord.py < data->small_side)
		{
			ft_julia_init(data);
			while (data->coord.z.re_sq + data->coord.z.im_sq < 4
				&& data->coord.iter < data->coord.max_iter)
			{
				data->coord.z.im = 2 * data->coord.z.re
					* data->coord.z.im + data->coord.julia.im;
				data->coord.z.re = data->coord.z.re_sq
					- data->coord.z.im_sq + data->coord.julia.re;
				data->coord.z.re_sq = data->coord.z.re * data->coord.z.re;
				data->coord.z.im_sq = data->coord.z.im * data->coord.z.im;
				data->coord.iter++;
			}
			pthread_mutex_lock(&mutex);
			double zn_abs = sqrt(data->coord.z.re_sq + data->coord.z.im_sq);
			double nu = log(log(zn_abs) / log(2)) / log(2);
			double smoothed_iter = data->coord.iter + 1 - nu;
			data->color = (int)((smoothed_iter * (data->color_jul * 10) / data->coord.max_iter)) * 8388730;
			ft_mlx_pixel_put(data, data->coord.px, data->coord.py, data->color);
			pthread_mutex_unlock(&mutex);
			data->coord.py++;
		}
		data->coord.px++;
	}
	pthread_mutex_destroy(&mutex);
	return (NULL);
}

void    ft_julia_decorator(t_data *data)
{
    pthread_t   threads_creator[NUM_THREADS];
    t_thread    thread_data[NUM_THREADS];
    int         i = -1;

    while (++i < NUM_THREADS)
    {
        thread_data[i].ptr_data = *data;
        thread_data[i].x_start = (i * data->small_side / NUM_THREADS);
        thread_data[i].x_end = (i + 1) * data->small_side / NUM_THREADS;
        pthread_create(&threads_creator[i], NULL, ft_julia, (void *)(&thread_data[i]));
    }
    i = -1;
    while (++i < NUM_THREADS)
        pthread_join(threads_creator[i], NULL);
}
