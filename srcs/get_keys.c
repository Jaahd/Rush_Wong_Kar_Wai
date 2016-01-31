#include "game_2048.h"

int			switch_values(int **tbl, int i, int j)
{
	if ((*tbl)[i] != 0)
		return (1);
	if ((*tbl)[j] != 0)
	{
		(*tbl)[i] = (*tbl)[j];
		(*tbl)[j] = 0;
		return (1);
	}
	return (0);
}

int			add_values(int **tbl, int i, int j)
{
	if ((*tbl)[i] > 0 && (*tbl)[j] && (*tbl)[i] != (*tbl)[j])
		return (1);
	if ((*tbl)[i] > 0 && (*tbl)[i] == (*tbl)[j])
	{
		(*tbl)[i] += (*tbl)[j];
		(*tbl)[j] = 0;
		return (1);
	}
	return (0);
}

int				get_keys(WINDOW *game_win, int **tbl, int len)
{
	int				key;

	key = wgetch(game_win);
	if (key == 27)
		return (1);
	if(key == KEY_DOWN)	
		down_arrow(tbl, len);
	if(key == KEY_UP)	
		up_arrow(tbl, len);
	if(key == KEY_LEFT)	
		left_arrow(tbl, len);
	if(key == KEY_RIGHT)
		right_arrow(tbl, len);
	if (key == KEY_DOWN || key == KEY_RIGHT || key == KEY_LEFT || key == KEY_UP)
		rand_nb_in_pos(tbl, len, 1);
	return 0;
}
