/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_call.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyoo <yoyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:59:19 by yoyoo             #+#    #+#             */
/*   Updated: 2021/12/01 17:59:21 by yoyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_malloc(void	**data, int size)
{
	*data = malloc(size);
	if (*data == NULL)
	{
		printf("malloc error\n");
		return (1);
	}
	return (0);
}
