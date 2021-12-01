/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyoo <yoyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 18:43:35 by yoyoo             #+#    #+#             */
/*   Updated: 2021/12/01 17:57:02 by yoyoo            ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = NULL;
	if (check_arg(argc, argv))
		return (1);
	if (parsing(&data, argc, argv))
		return (1);
	run_thread(data);
	ft_free(data);
	return (0);
}
