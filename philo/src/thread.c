/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyoo <yoyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:45:19 by yoyoo             #+#    #+#             */
/*   Updated: 2021/12/01 18:05:46 by yoyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork[philo->left_fork]);
	print_message(philo->data, philo->number + 1, FORK);
	pthread_mutex_lock(&philo->data->fork[philo->right_fork]);
	print_message(philo->data, philo->number + 1, FORK);
}

void	eating(t_philo *philo)
{
	philo->last_eat_time = get_time();
	print_message(philo->data, philo->number + 1, EAT);
	micro_usleep(philo->data->eat_time + get_time());
	pthread_mutex_unlock(&philo->data->fork[philo->left_fork]);
	pthread_mutex_unlock(&philo->data->fork[philo->right_fork]);
	if (philo->data->num_must_eat)
		philo->num_eat++;
}

void	*philo_routine(void *philo_num)
{
	t_philo	*philo;

	philo = (t_philo *)philo_num;
	while (philo->data->loop)
	{
		take_fork(philo);
		eating(philo);
		print_message(philo->data, philo->number + 1, SLEEP);
		micro_usleep(philo->data->sleep_time + get_time());
		print_message(philo->data, philo->number + 1, THINK);
	}
	return (NULL);
}

void	monitor(t_data *data)
{
	int	i;

	i = 0;
	while (data->loop)
	{
		if (i == data->num_philo)
			i = 0;
		if (get_time() - data->philo[i].last_eat_time >= data->life_time)
		{
			print_message(data, data->philo[i].number + 1, DIE), data->loop = 0;
			return ;
		}
		if (data->num_must_eat != -1 && data->philo[i].full == 0)
		{
			if (data->philo[i].num_eat == data->num_must_eat)
				data->philo[i].full = 1, data->full_philo++;
		}
		if (data->full_philo == data->num_philo)
		{
			pthread_mutex_lock(&data->print);
			printf("All of philo done to eat\n"), data->loop = 0;
		}
		i++, usleep(130);
	}
}

void	run_thread(t_data *data)
{
	int	i;

	i = 0;
	data->start_time = get_time();
	while (i < data->num_philo)
	{
		data->philo[i].last_eat_time = get_time();
		pthread_create(&data->philo[i].thread, NULL,
			philo_routine, (void *)&data->philo[i]);
		pthread_detach(data->philo[i].thread);
		i++;
		usleep(50);
	}
	monitor(data);
}
