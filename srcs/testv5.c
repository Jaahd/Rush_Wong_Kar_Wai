#include <ncurses.h>
#include <unistd.h>
#include "game_2048.h"

void    set_grid_x(WINDOW *field, int parent_y, int parent_x, int len)
{
	int     i;
	int     j;

	i = 1;
	while (i < len)
	{
		j = 0;
		while (j <= parent_y) 
		{
			mvwprintw(field, j, ((parent_x / len) * i), "|");
			j++;
		}
		i++;
	}
}

void    set_grid_y(WINDOW *field, int parent_y, int parent_x, int len)
{
	int     i;
	int     j;

	i = 1;
	while (i < len)
	{
		j = 0;
		while (j <= parent_x)
		{
			mvwprintw(field, ((parent_y / len) * i), j, "-");
			j++;
		}
		i++;
	}
}

int			resize(WINDOW *field, int len)
{
	int		new_x;
	int		new_y;

	getmaxyx(field, new_y, new_x);
	wclear(field);
	set_grid_x(field, new_y, new_x, len);
	set_grid_y(field, new_y, new_x, len);
	return 0;
}
