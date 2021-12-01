/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyoo <yoyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 18:42:28 by yoyoo             #+#    #+#             */
/*   Updated: 2021/12/01 18:00:48 by yoyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define FORK	1
# define EAT	2
# define SLEEP	3
# define THINK	4
# define DIE	5

typedef struct s_philo
{
	int				left_fork;
	int				right_fork;
	int				number;
	int				full;
	int				num_eat;
	pthread_t		thread;
	long long		last_eat_time;
	struct s_data	*data;
}				t_philo;

typedef struct s_data
{
	int				num_philo;
	long long		life_time;
	int				eat_time;
	int				sleep_time;
	int				num_must_eat;
	int				loop;
	int				full_philo;
	long long		start_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	t_philo			*philo;

}				t_data;
/* parsing */
int				parsing(t_data **data, int argc, char **argv);
/* thread */
void			run_thread(t_data *data);
void			take_fork(t_philo *philo);
void			all_free(t_data *data);
/* utils */
int				ft_isdigit(int c);
long long		ft_atoi(const char *str);
int				ft_malloc(void	**data, int size);
int				print_message(t_data *data, int philo_num, int type);
void			micro_usleep(long long wait_term);
long long		get_time(void);

#endif
