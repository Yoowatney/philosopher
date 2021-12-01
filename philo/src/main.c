/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyoo <yoyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 18:43:35 by yoyoo             #+#    #+#             */
/*   Updated: 2021/12/01 19:54:03 by yoyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_arg(int argc, char **argv)
{
	int	i;
	int	j;

	i = 2;
	if (argc != 5 && argc != 6)
	{
		printf("Input Error\n");
		return (1);
	}
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
			{
				printf("Input Error\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_free(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		pthread_mutex_destroy(&data->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&data->print);
	all_free(data);
}

int	validate(t_data *data)
{
	if (data->num_philo >= 200)
	{
		all_free(data);
		printf("Too many philo\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = NULL;
	if (check_arg(argc, argv))
		return (1);
	if (parsing(&data, argc, argv) || validate(data))
	{
		return (1);
	}
	if (run_thread(data))
	{
		printf("thread error\n");
		return (1);
	}
	ft_free(data);
	return (0);
}
