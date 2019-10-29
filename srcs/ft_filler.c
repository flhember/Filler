/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:26:02 by flhember          #+#    #+#             */
/*   Updated: 2019/10/23 14:24:22 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

static void	ft_reboot(t_env **data)
{
	(*data)->y_pl_last = 0;
	(*data)->x_pl_last = 0;
	(*data)->y_pl_touch = 0;
	(*data)->x_pl_touch = 0;
	(*data)->up_down = 0;
	(*data)->size_piece_y = 0;
	(*data)->size_piece_x = 0;
	(*data)->new_size_y_p = 0;
	(*data)->piece_y_first = 0;
	(*data)->piece_x_first = 0;
	(*data)->y_final = 0;
	(*data)->x_final = 0;
}

static void	ft_free_map_piece(t_env **data, int flag, int i)
{
	if ((*data)->map)
	{
		while ((*data)->map[i])
		{
			ft_strdel(&(*data)->map[i]);
			i++;
		}
	}
	i = 0;
	if (i < (*data)->new_size_y_p)
	{
		while ((*data)->piece[i])
		{
			ft_strdel(&(*data)->piece[i]);
			i++;
		}
		free((*data)->piece);
	}
	ft_reboot(data);
	if (flag == 1)
	{
		if ((*data)->map)
			free((*data)->map);
		free(*data);
	}
}

int			ft_filler(void)
{
	t_env	*data;

	data = NULL;
	if (!(data = (t_env*)ft_memalloc(sizeof(t_env))))
		return (-1);
	if (ft_get_data(&data) == -1)
		return (-1);
	while (1)
	{
		data->nb_tour += 1;
		if (ft_get_map(&data) == -1)
			break ;
		if (ft_get_piece(&data) == -1)
			break ;
		if (ft_resolv(&data) == -1)
			break ;
		ft_printf("%d %d\n", data->y_final, data->x_final);
		ft_free_map_piece(&data, 0, 0);
	}
	ft_free_map_piece(&data, 1, 0);
	return (0);
}
