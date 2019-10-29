/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_catch_down.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:59:41 by flhember          #+#    #+#             */
/*   Updated: 2019/10/22 15:58:19 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

void		ft_find_coor_piece_down(t_env **data, int i, int j)
{
	int		flag;

	flag = 0;
	while (!flag && i < (*data)->new_size_y_p)
	{
		while (!flag && j < (*data)->size_piece_x)
		{
			if ((*data)->piece[i][j] == '*')
			{
				(*data)->piece_y_first = i;
				(*data)->piece_x_first = j;
				flag = 1;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

static void	ft_find_coor_map_down(t_env **data, int i, int j)
{
	int		flag;

	flag = 0;
	while (i >= 0 && !flag)
	{
		while (j >= 0 && !flag)
		{
			if (((*data)->map[i][j] == (*data)->player_last)
					|| ((*data)->map[i][j] == (*data)->player))
			{
				flag = 1;
				(*data)->x_pl_last = j;
				(*data)->y_pl_last = i;
			}
			j--;
		}
		j = (*data)->size_map_x - 1;
		i--;
	}
}

static int	ft_try_piece_down(t_env **data, int i, int j, int stop)
{
	while (stop == 0 && i >= 0)
	{
		ft_find_coor_map_down(data, i, j);
		stop = ft_put_piece(data);
		if (stop == 0)
		{
			(*data)->x_pl_last--;
			j = (*data)->x_pl_last;
			i = (*data)->y_pl_last;
			if (j < 0)
			{
				(*data)->y_pl_last--;
				j = (*data)->size_map_x - 1;
				i = (*data)->y_pl_last;
			}
		}
	}
	return (stop);
}

static int	ft_change_strat_to_up(t_env **data)
{
	int		ret;

	ret = 1;
	if ((*data)->up_down == 1)
	{
		(*data)->y_pl_last = 0;
		(*data)->x_pl_last = 0;
		ret = ft_catch_up(data, 0, 0, 0);
	}
	return (ret);
}

int			ft_catch_down(t_env **data, int i, int j, int stop)
{
	int		i_piece;
	int		j_piece;

	stop = 0;
	i_piece = 0;
	j_piece = 0;
	while (stop == 0)
	{
		i = (*data)->size_map_y - 1;
		j = (*data)->size_map_x - 1;
		ft_find_coor_piece_down(data, i_piece, j_piece);
		stop = ft_try_piece_down(data, i, j, stop);
		j_piece++;
		if (!stop && j_piece >= (*data)->size_piece_x)
		{
			j_piece = 0;
			i_piece++;
			if (i_piece >= (*data)->new_size_y_p)
			{
				stop = ft_change_strat_to_up(data);
				return (stop);
			}
		}
	}
	return (0);
}
