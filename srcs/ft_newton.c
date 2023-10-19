/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:57:48 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/19 18:22:48 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_fractol.h"

static void	ft_newton_init(t_data *data)
{
	data->coord.iter = 0;
	data->newton = (data->x_min + (data->coord.px + data->move_x) * (data->x_max - data->x_min) / data->small_side) + (data->y_max - (data->coord.py + data->move_y) * (data->y_max - data->y_min) / data->small_side) * I;
}

static complex double df(complex double z)
{
	return 3 * cpow(z, 2);
}

static complex double f(complex double z)
{
	return cpow(z, 3) - 1.0;
}

static void	*ft_newton(void *thread_d)
{
	t_thread			*thread_data = (t_thread *)thread_d;
    t_data				*data = &thread_data->ptr_data;
    pthread_mutex_t		mutex;

    pthread_mutex_init(&mutex, NULL);
    data->coord.px = thread_data->x_start;
    while (data->coord.px < thread_data->x_end)
    {
        data->coord.py = 0;
        while (data->coord.py < data->small_side)
        {
			ft_newton_init(data);
            while (cabs(f(data->newton)) > 0.0001 && data->coord.iter < data->coord.max_iter)
            {
				data->coord.iter++;
				data->newton = data->newton - f(data->newton) / df(data->newton);
            }
            pthread_mutex_lock(&mutex);
            int color = 0x000FFF * data->coord.iter;
            ft_mlx_pixel_put(data, data->coord.px, data->coord.py, color);
            pthread_mutex_unlock(&mutex);
            data->coord.py++;
        }
        data->coord.px++;
    }
    pthread_mutex_destroy(&mutex);
    return (NULL);
}

void	ft_newton_decorator(t_data *data)
{
	pthread_t   threads_creator[NUM_THREADS];
    t_thread    thread_data[NUM_THREADS];
    int         i = -1;

    while (++i < NUM_THREADS)
    {
        thread_data[i].ptr_data = *data;
        thread_data[i].x_start = (i * data->small_side / NUM_THREADS);
        thread_data[i].x_end = (i + 1) * data->small_side / NUM_THREADS;
        pthread_create(&threads_creator[i], NULL, ft_newton, (void *)(&thread_data[i]));
    }
    i = -1;
    while (++i < NUM_THREADS)
        pthread_join(threads_creator[i], NULL);
}
