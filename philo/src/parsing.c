/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyoo <yoyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:29:31 by yoyoo             #+#    #+#             */
/*   Updated: 2021/12/01 17:58:21 by yoyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	init_fork(t_data **data)
{
	int	i;

	i = 0;
	while (i < (*data)->num_philo)
	{
		if (pthread_mutex_init(&(*data)->fork[i], NULL))
			return (1);
		i++;
	}
	(*data)->loop = 1;
	return (0);
}

void	assign_fork(t_data **data)
{
	int	i;

	i = 0;
	while (i < (*data)->num_philo)
	{
		(*data)->philo[i].left_fork = i;
		(*data)->philo[i].right_fork = (i + 1) % ((*data)->num_philo);
		(*data)->philo[i].number = i;
		(*data)->philo[i].full = 0;
		(*data)->philo[i].num_eat = 0;
		(*data)->philo[i].data = *data;
		i++;
	}
}

int	parsing(t_data **data, int argc, char **argv)
{
	if (ft_malloc((void **)data, sizeof(t_data)) == 1)
		return (1);
	(*data)->num_philo = ft_atoi(argv[1]);
	(*data)->life_time = ft_atoi(argv[2]) * 1000;
	(*data)->eat_time = ft_atoi(argv[3]) * 1000;
	(*data)->sleep_time = ft_atoi(argv[4]) * 1000;
	(*data)->num_must_eat = -1;
	(*data)->full_philo = 0;
	if (argc == 6)
		(*data)->num_must_eat = ft_atoi(argv[5]);
	if (ft_malloc((void **)&((*data)->philo), sizeof(t_philo)
			* (*data)->num_philo) == 1)
		return (1);
	assign_fork(data);
	if (ft_malloc((void **)&((*data)->fork), sizeof(pthread_mutex_t)
			* (*data)->num_philo) == 1)
		return (1);
	if (init_fork(data) || pthread_mutex_init(&(*data)->print, NULL))
	{
		all_free(*data);
		printf("mutex init error\n");
		return (1);
	}
	return (0);
}
