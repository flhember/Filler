/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:23:33 by flhember          #+#    #+#             */
/*   Updated: 2019/10/22 16:00:34 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

static int	ft_check_piece_map(t_env **data, int i, int j)
{
	i = (*data)->piece_y_first - i;
	j = (*data)->piece_x_first - j;
	i = (*data)->y_pl_last - i;
	j = (*data)->x_pl_last - j;
	if (i >= (*data)->size_map_y || j >= (*data)->size_map_x || j < 0 || i < 0)
		return (1);
	if ((*data)->map[i][j] == (*data)->player
		|| (*data)->map[i][j] == (*data)->player_last)
	{
		(*data)->put_piece++;
		return (0);
	}
	if ((*data)->map[i][j] && (*data)->map[i][j] == '.')
		return (0);
	return (1);
}

int			ft_put_piece(t_env **data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	(*data)->put_piece = 0;
	while (i >= 0 && i < (*data)->new_size_y_p)
	{
		while (j >= 0 && j < (*data)->size_piece_x)
		{
			if ((*data)->piece[i][j] == '*')
				if (ft_check_piece_map(data, i, j) == 1)
					return (0);
			j++;
		}
		j = 0;
		i++;
	}
	if ((*data)->put_piece == 1)
		return (1);
	return (0);
}
