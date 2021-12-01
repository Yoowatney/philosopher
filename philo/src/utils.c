/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyoo <yoyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 14:25:17 by yoyoo             #+#    #+#             */
/*   Updated: 2021/12/01 17:59:03 by yoyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long long	ft_atoi(const char *str)
{
	int			sign;
	long long	i;

	sign = 1;
	i = 0;
	while (*str == ' ' || *str == '\n' || *str == '\f'
		|| *str == '\t' || *str == '\r' || *str == '\v')
		str++;
	if (*str == '-')
	{
		str++;
		sign *= -1;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		i *= 10;
		i += (sign) * ((*(str++) - '0'));
	}
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000000) + (time.tv_usec));
}

int	print_message(t_data *data, int philo_num, int type)
{
	char	*str;

	if (type == FORK)
		str = "has taken a fork";
	else if (type == EAT)
		str = "is eating";
	else if (type == SLEEP)
		str = "is sleep";
	else if (type == THINK)
		str = "is thinking";
	else if (type == DIE)
		str = "died";
	if (data->loop)
	{
		pthread_mutex_lock(&data->print);
		printf("%lld %d %s\n", (get_time() - data->start_time) / 1000,
			philo_num, str);
		if (type < DIE)
			pthread_mutex_unlock(&data->print);
	}
	return (0);
}

void	micro_usleep(long long time)
{
	while (get_time() <= time)
		usleep(100);
}
