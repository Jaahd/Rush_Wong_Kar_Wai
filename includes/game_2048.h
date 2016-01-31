/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avacher <avacher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 22:25:52 by avacher           #+#    #+#             */
/*   Updated: 2016/01/31 22:25:52 by avacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2048_H
# define GAME_2048_H

# include <ncurses.h>
# include "libft.h"

enum		e_const
{
	WIN_VALUE = 2048
};

int			resize(WINDOW *toto, int len);
int			switch_values(int **tbl, int i, int j);
int			add_values(int **tbl, int i, int j);
int			get_keys(WINDOW *game_win, int **tbl, int len);
int			left_arrow(int **tbl, int len);
int			right_arrow(int **tbl, int len);
int			up_arrow(int **tbl, int len);
int			down_arrow(int **tbl, int len);
void		init_tbl(int **tbl, int len);
int			check_victory(int *tbl, int len);
int			check_defeat(int *tbl, int len);
int			display_message(WINDOW *game_win, int message_condition);
void		rand_nb_in_pos(int **tbl, int len, int again);
void		set_grid_y(WINDOW *field, int parent_y, int parent_x, int len);
void		set_grid_x(WINDOW *field, int parent_y, int parent_x, int len);
int			winorlose(WINDOW *game_win, int *tbl, int len, int *win);
int			display_values(WINDOW *game_win, int *tbl, int len);

#endif
