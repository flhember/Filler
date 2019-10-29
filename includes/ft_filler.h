/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flhember <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 09:48:55 by flhember          #+#    #+#             */
/*   Updated: 2019/10/28 15:49:59 by flhember         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

# include "../libft/includes/libft.h"

typedef	struct			s_env
{
	int					nb_tour;
	int					put_piece;
	int					size_map_x;
	int					size_map_y;
	int					size_piece_x;
	int					size_piece_y;
	int					y_befor_p;
	int					y_after_p;
	int					decal_y_p;
	int					new_size_y_p;
	int					x_pl_last;
	int					y_pl_last;
	int					x_pl_touch;
	int					y_pl_touch;
	int					x_final;
	int					y_final;
	int					up_down;
	int					piece_x_first;
	int					piece_y_first;
	int					nb_piece_n;
	int					nb_piece_b;
	char				player;
	char				player_last;
	char				enemy;
	char				enemy_last;
	char				**map;
	char				**piece;
}						t_env;

int						ft_filler(void);
int						ft_get_map(t_env **data);
int						ft_get_piece(t_env **data);
int						ft_resolv(t_env **data);
int						ft_check_touch(t_env **data, int i, int j);
int						ft_get_data(t_env **data);
int						ft_put_piece(t_env **data);
int						ft_catch_him(t_env **data);
int						ft_catch_him_out(t_env **data);
int						ft_catch_up(t_env **data, int i, int j, int stop);
int						ft_catch_down(t_env **data, int i, int j, int stop);
int						ft_filling_end(t_env **data);
int						ft_reduce_piece(t_env **data);
int						ft_block_up(t_env **data, int i, int j, int stop);
int						ft_block_down(t_env **data, int i, int j, int stop);
void					ft_find_coor_piece_down(t_env **data, int i, int j);
void					ft_find_coor_piece_up(t_env **data, int i, int j);

#endif
