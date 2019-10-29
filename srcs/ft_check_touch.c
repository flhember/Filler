/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_touch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:38:47 by flhember          #+#    #+#             */
/*   Updated: 2019/10/22 15:59:00 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

static int	ft_look_around_corner(t_env **data, int i, int j)
{
	if (j > 0 && i > 0)
	{
		if (((*data)->map[i - 1][j - 1] == (*data)->enemy)
				|| ((*data)->map[i - 1][j - 1] == (*data)->enemy_last))
			return (1);
	}
	if (i < (*data)->size_map_y - 1 && j > 0)
		if (((*data)->map[i + 1][j - 1] == (*data)->enemy)
				|| ((*data)->map[i + 1][j - 1] == (*data)->enemy_last))
			return (1);
	if (i > 0 && j < (*data)->size_map_x - 1)
		if (((*data)->map[i - 1][j + 1] == (*data)->enemy)
				|| ((*data)->map[i - 1][j + 1] == (*data)->enemy_last))
			return (1);
	if (i < (*data)->size_map_y - 1 && j < (*data)->size_map_x - 1)
		if (((*data)->map[i + 1][j + 1] == (*data)->enemy)
				|| ((*data)->map[i + 1][j + 1] == (*data)->enemy_last))
			return (1);
	return (0);
}

static int	ft_look_around(t_env **data, int i, int j)
{
	if (j > 0)
		if (((*data)->map[i][j - 1] == (*data)->enemy)
				|| ((*data)->map[i][j - 1] == (*data)->enemy_last))
			return (1);
	if (j < (*data)->size_map_x - 1)
		if (((*data)->map[i][j + 1] == (*data)->enemy)
				|| ((*data)->map[i][j + 1] == (*data)->enemy_last))
			return (1);
	if (i > 0)
		if (((*data)->map[i - 1][j] == (*data)->enemy)
				|| ((*data)->map[i - 1][j] == (*data)->enemy_last))
			return (1);
	if (i < (*data)->size_map_y - 1)
		if (((*data)->map[i + 1][j] == (*data)->enemy)
				|| ((*data)->map[i + 1][j] == (*data)->enemy_last))
			return (1);
	if (ft_look_around_corner(data, i, j) == 1)
		return (1);
	return (0);
}

int			ft_check_touch(t_env **data, int i, int j)
{
	while ((*data)->map[i])
	{
		while ((*data)->map[i][j])
		{
			if (((*data)->map[i][j] == (*data)->player)
					|| ((*data)->map[i][j] == (*data)->player_last))
				if (ft_look_around(data, i, j) == 1)
				{
					(*data)->y_pl_touch = i;
					(*data)->x_pl_touch = j;
					return (1);
				}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
