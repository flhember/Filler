/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 16:45:53 by flhember          #+#    #+#             */
/*   Updated: 2019/10/23 13:59:35 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

static int	ft_get_size_map(t_env **data, char *data_map)
{
	int		i;

	i = 0;
	while (*data_map != ' ')
		data_map++;
	(*data)->size_map_y = ft_atoi(data_map);
	data_map++;
	while (*data_map != ' ')
		data_map++;
	(*data)->size_map_x = ft_atoi(data_map);
	if (!((*data)->map = (char **)ft_memalloc(sizeof(char*) *
					((*data)->size_map_y + 1))))
		return (0);
	return (1);
}

static void	ft_check_player(t_env **data, char *data_player)
{
	if (data_player[10] == '1')
	{
		(*data)->player_last = 'o';
		(*data)->player = 'O';
		(*data)->enemy_last = 'x';
		(*data)->enemy = 'X';
	}
	if (data_player[10] == '2')
	{
		(*data)->player_last = 'x';
		(*data)->player = 'X';
		(*data)->enemy_last = 'o';
		(*data)->enemy = 'O';
	}
}

int			ft_get_data(t_env **data)
{
	char	*tmp;

	tmp = NULL;
	if (get_next_line(0, &tmp) && !ft_strncmp(tmp, "$$$ exec p", 9)
			&& (tmp[10] == '1' || tmp[10] == '2'))
		ft_check_player(data, tmp);
	else
		return (-1);
	tmp ? ft_strdel(&tmp) : tmp;
	if (get_next_line(0, &tmp))
	{
		if (!(ft_get_size_map(data, tmp)))
		{
			tmp ? ft_strdel(&tmp) : tmp;
			return (-1);
		}
		tmp ? ft_strdel(&tmp) : tmp;
	}
	return (0);
}
