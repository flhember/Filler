/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reduce_piece.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:20:04 by flhember          #+#    #+#             */
/*   Updated: 2019/10/23 13:52:11 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

static void	ft_find_first_i(t_env **data)
{
	int		i;
	int		j;
	int		flag;

	i = 0;
	flag = 0;
	(*data)->y_befor_p = 0;
	while (!flag && i < (*data)->size_piece_y)
	{
		j = 0;
		while (!flag && j < (*data)->size_piece_x)
		{
			if ((*data)->piece[i][j] == '*')
			{
				(*data)->y_befor_p = i;
				flag = 1;
			}
			j++;
		}
		i++;
	}
}

static void	ft_find_last_i(t_env **data)
{
	int		i;
	int		j;
	int		flag;
	int		cmpt;

	flag = 0;
	cmpt = 0;
	(*data)->y_after_p = 0;
	i = (*data)->size_piece_y - 1;
	while (!flag && i >= 0)
	{
		j = (*data)->size_piece_x - 1;
		while (!flag && j >= 0)
		{
			if ((*data)->piece[i][j] == '*')
			{
				(*data)->y_after_p = cmpt;
				flag = 1;
			}
			j--;
		}
		cmpt++;
		i--;
	}
}

static void	ft_free_piece(t_env **data)
{
	int		i;

	i = 0;
	while ((*data)->piece[i])
	{
		ft_strdel(&(*data)->piece[i]);
		i++;
	}
	free((*data)->piece);
}

static int	ft_realloc_piece(t_env **data, int i)
{
	int		j;
	int		size_alloc;
	char	**new_piece;

	i = 0;
	j = 0;
	size_alloc = (*data)->size_piece_y
		- (*data)->y_befor_p - (*data)->y_after_p;
	if (!(new_piece = (char **)ft_memalloc(sizeof(char*) * (size_alloc + 1))))
		return (-1);
	while (j < size_alloc)
	{
		new_piece[j] = ft_strdup((*data)->piece[(*data)->y_befor_p + j]);
		j++;
	}
	new_piece[size_alloc] = NULL;
	ft_free_piece(data);
	(*data)->piece = new_piece;
	(*data)->decal_y_p = (*data)->y_befor_p + (*data)->y_after_p + 1;
	(*data)->new_size_y_p = size_alloc;
	return (0);
}

int			ft_reduce_piece(t_env **data)
{
	ft_find_first_i(data);
	ft_find_last_i(data);
	if (ft_realloc_piece(data, 0) == -1)
		return (-1);
	return (0);
}
