/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 12:40:54 by flhember          #+#    #+#             */
/*   Updated: 2019/10/22 16:05:07 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

static int	ft_choose_block_end(t_env **data, int i, int j)
{
	int		down;

	down = 0;
	while (i < (*data)->size_map_y)
	{
		while (j < (*data)->size_map_x)
		{
			if ((*data)->map[i][j] == (*data)->enemy
					|| (*data)->map[i][j] == (*data)->enemy_last)
				down++;
			j++;
		}
		j = 0;
		i++;
	}
	return (down);
}

static int	ft_choose_block(t_env **data, int up, int down)
{
	int		i;
	int		j;
	int		flag;

	i = 0;
	j = 0;
	flag = 0;
	while (!flag && i < (*data)->size_map_y)
	{
		while (!flag && j < (*data)->size_map_x)
		{
			if (i == (*data)->y_pl_touch && j == (*data)->x_pl_touch)
				flag = 1;
			if ((*data)->map[i][j] == (*data)->enemy
					|| (*data)->map[i][j] == (*data)->enemy_last)
				up++;
			j++;
		}
		j = 0;
		i++;
	}
	down = ft_choose_block_end(data, i, j);
	if (up >= down)
		return (1);
	return (-1);
}

int			ft_resolv(t_env **data)
{
	if (ft_check_touch(data, 0, 0) == 0)
	{
		if (ft_catch_him(data) == -1)
			return (-1);
	}
	else
	{
		if ((ft_choose_block(data, 0, 0)) == 1)
			ft_block_down(data, -1, 0, 0);
		else
			ft_block_up(data, 0, 0, 0);
	}
	return (0);
}
