/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:24:43 by flhember          #+#    #+#             */
/*   Updated: 2019/10/23 14:25:40 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

static int	ft_get_size_piece(t_env **data, char *data_piece)
{
	int		i;

	i = 0;
	while (*data_piece != ' ')
		data_piece++;
	(*data)->size_piece_y = ft_atoi(data_piece);
	data_piece++;
	while (*data_piece != ' ')
		data_piece++;
	(*data)->size_piece_x = ft_atoi(data_piece);
	if (!((*data)->piece = (char **)ft_memalloc(sizeof(char*) *
					((*data)->size_piece_y + 1))))
		return (0);
	return (1);
}

static int	ft_fill_piece(t_env **data)
{
	int		i;
	int		res;
	char	*tmp;

	i = 0;
	res = 0;
	tmp = NULL;
	while (i < (*data)->size_piece_y)
	{
		res = get_next_line(0, &tmp);
		if (res == 0)
			return (-1);
		if (res == 1)
		{
			(*data)->piece[i] = ft_strsub(tmp, 0, (*data)->size_piece_x);
			i++;
		}
		tmp ? ft_strdel(&tmp) : tmp;
	}
	(*data)->piece[(*data)->size_piece_y] = NULL;
	return (0);
}

int			ft_get_piece(t_env **data)
{
	int		res;
	char	*tmp;

	tmp = NULL;
	res = get_next_line(0, &tmp);
	if (res == 1)
	{
		if (!(ft_get_size_piece(data, tmp)))
		{
			tmp ? ft_strdel(&tmp) : tmp;
			return (-1);
		}
	}
	tmp ? ft_strdel(&tmp) : tmp;
	if (ft_fill_piece(data) == -1)
		return (-1);
	if (ft_reduce_piece(data) == -1)
		return (-1);
	return (0);
}

int			ft_get_map(t_env **data)
{
	int		i;
	int		res;
	char	*tmp;

	i = 0;
	res = 1;
	tmp = NULL;
	while (i < (*data)->size_map_y)
	{
		res = get_next_line(0, &tmp);
		if (res == 0)
			return (-1);
		if (res == 1 && (ft_strchr(tmp, '.') || (ft_strchr(tmp, 'O'))
					|| (ft_strchr(tmp, 'X'))))
		{
			(*data)->map[i] = ft_strsub(tmp, (ft_strlen(tmp) -
						(*data)->size_map_x),
					(*data)->size_map_x);
			i++;
		}
		tmp ? ft_strdel(&tmp) : tmp;
	}
	(*data)->map[(*data)->size_map_y] = NULL;
	return (0);
}
