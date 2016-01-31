#include <stdlib.h>
#include <ncurses.h>
#include "game_2048.h"

int			check_victory(int *tbl, int len)
{
	int			i;

	i = 0;
	while (i < (len * len))
	{
		if (tbl[i] >= WIN_VALUE)
			return (1);
		i++;
	}
	return (0);
}

int			check_defeat(int *tbl, int len)	
{
	int			*tmp;
	int			i;
	
	tmp = (int *)malloc(sizeof(int) * (len * len));
	i = 0;
	while (i < (len * len))
	{
		tmp[i] = tbl[i];
		i++;
	}
	left_arrow(&tmp, len);
	right_arrow(&tmp, len);
	up_arrow(&tmp, len);
	down_arrow(&tmp, len);
	i = 0;
	while (i < (len * len))
	{
		if (tmp[i] == 0)
		{
			free(tmp);
			return (0);
		}
		i++;
	}
	free(tmp);
	return (1);	
}

int			winorlose(WINDOW *game_win, int *tbl, int len, int *win)
{
	if (check_victory(tbl, len) && *win != 1)
	{
		*win = 1;
		display_values(game_win, tbl, len);
		display_message(game_win, 1);
		while(TRUE)
			if (wgetch(game_win))
				break ;
	}
	if (check_defeat(tbl, len))
	{
		display_values(game_win, tbl, len);
		display_message(game_win, 0);
		while (TRUE)
			if (wgetch(game_win) == 27)
				break ;
		return (1);
	}
	return (0);
}

int			display_message(WINDOW *game_win, int message_condition)
{
	int			y;
	int			x;

	getmaxyx(game_win, y, x);
	y = y / 2;
	x = (x / 2) - 4;
	wmove(game_win, y, x);
	if (message_condition == 1)
		wprintw(game_win, "YOU WIN!");
	if (message_condition == 0)
		wprintw(game_win, "YOU LOSE");
	return (0);
}
