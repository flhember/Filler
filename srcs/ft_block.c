/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_block.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 16:50:17 by flhember          #+#    #+#             */
/*   Updated: 2019/10/22 16:09:23 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

static void	ft_calc_coor(t_env **data)
{
	if ((*data)->put_piece == 1)
	{
		(*data)->y_final = (*data)->y_pl_last
			- (*data)->piece_y_first - (*data)->y_befor_p;
		(*data)->x_final = (*data)->x_pl_last - (*data)->piece_x_first;
	}
}

static void	ft_block_down_incr(t_env **data)
{
	(*data)->x_pl_touch++;
	if ((*data)->x_pl_touch >= (*data)->size_map_x)
	{
		(*data)->x_pl_touch = 0;
		(*data)->y_pl_touch++;
	}
}

int			ft_block_down(t_env **data, int i, int j, int stop)
{
	stop = 0;
	while (stop == 0)
	{
		i = 0;
		j = 0;
		(*data)->y_pl_last = (*data)->y_pl_touch;
		(*data)->x_pl_last = (*data)->x_pl_touch;
		while (stop == 0 && i < (*data)->new_size_y_p)
		{
			ft_find_coor_piece_down(data, i, j);
			stop = ft_put_piece(data);
			j++;
			if (j >= (*data)->size_piece_x)
			{
				j = 0;
				i++;
			}
		}
		ft_block_down_incr(data);
		if (ft_check_touch(data, (*data)->y_pl_touch, (*data)->x_pl_touch) == 0)
			stop = ft_catch_him(data);
	}
	ft_calc_coor(data);
	return (stop);
}

static void	ft_block_up_incr(t_env **data)
{
	(*data)->x_pl_touch++;
	if ((*data)->x_pl_touch >= (*data)->size_map_x)
	{
		(*data)->y_pl_touch++;
		(*data)->x_pl_touch = 0;
	}
}

int			ft_block_up(t_env **data, int i, int j, int stop)
{
	stop = 0;
	while (stop == 0)
	{
		i = (*data)->new_size_y_p - 1;
		j = (*data)->size_piece_x - 1;
		(*data)->y_pl_last = (*data)->y_pl_touch;
		(*data)->x_pl_last = (*data)->x_pl_touch;
		while (stop == 0 && i >= 0)
		{
			ft_find_coor_piece_up(data, i, j);
			stop = ft_put_piece(data);
			j--;
			if (j < 0)
			{
				j = (*data)->size_piece_x - 1;
				i--;
			}
		}
		ft_block_up_incr(data);
		if (ft_check_touch(data, (*data)->y_pl_touch, (*data)->x_pl_touch) == 0)
			stop = ft_catch_him(data);
	}
	ft_calc_coor(data);
	return (stop);
}
