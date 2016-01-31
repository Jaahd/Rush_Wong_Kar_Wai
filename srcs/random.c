#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "game_2048.h"

static int		rand_pos(int len)
{
	int		case_num;

	case_num = rand() % (len * len);
	return (case_num);
}

static int		rand_nb(void)
{
	int		nb;

	nb = rand() % 10;
	if (nb == 0)
		nb = 4;
	else
		nb = 2;
	return (nb);
}

void		rand_nb_in_pos(int **tbl, int len, int again)
{
	int		i;
	int		cpt;
	int 	case_num;

	while (again > 0)
	{
		i = 0;
		cpt = 0;
		while (i < (len * len))
		{
			if ((*tbl)[i] == 0)
				cpt++;
			i++;
		}
		if (cpt > 0)
		{
			case_num = rand_pos(len);
			while ((*tbl)[case_num] != 0)
				case_num = rand_pos(len);
			(*tbl)[case_num] = rand_nb();
		}
		again--;
	}
}

void		init_tbl(int **tbl, int len)
{
	int		i;

	i = 0;
	while (i < ((len * len)))
	{
		(*tbl)[i] = 0;
		i++;
	}
	rand_nb_in_pos(tbl, len, 2);
}
