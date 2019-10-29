/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_catch_him.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:31:59 by flhember          #+#    #+#             */
/*   Updated: 2019/10/22 16:05:33 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

static int	ft_up_or_down(t_env **data)
{
	int		i;
	int		j;

	i = 0;
	while (i < (*data)->size_map_y)
	{
		j = 0;
		while (j < (*data)->size_map_x)
		{
			if (((*data)->map[i][j] == (*data)->enemy_last)
					|| ((*data)->map[i][j] == (*data)->enemy))
				return (-1);
			if (((*data)->map[i][j] == (*data)->player_last)
					|| ((*data)->map[i][j] == (*data)->player))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int			ft_catch_him(t_env **data)
{
	(*data)->up_down = ft_up_or_down(data);
	if ((*data)->up_down == -1)
	{
		if (ft_catch_up(data, 0, 0, 0) == 1)
			return (-1);
	}
	if ((*data)->up_down == 1)
	{
		if (ft_catch_down(data, 0, 0, 0) == 1)
			return (-1);
	}
	if ((*data)->put_piece == 1)
	{
		(*data)->y_final = ((*data)->y_pl_last
				- (*data)->piece_y_first) - (*data)->y_befor_p;
		(*data)->x_final = (*data)->x_pl_last - (*data)->piece_x_first;
	}
	return (1);
}
