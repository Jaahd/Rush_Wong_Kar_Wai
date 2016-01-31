#include "game_2048.h"

int			align_down(int **tbl, int len)
{
	int		i;
	int		j;
	int		cpt;

	cpt = 0;
	while (cpt < len)
	{
		i = (len * (len - 1)) + cpt;
		while (i > cpt)
		{
			j = i - len;
			while (j >= cpt)
			{
				if (switch_values(tbl, i, j))
					break ;
				j -= len;
			}
			i -= len;
		}
		cpt++;
	}
	return (0);
}

int			down_arrow(int **tbl, int len)
{
	int		i;
	int		j;
	int		cpt;

	cpt = 0;
	while (cpt < len)
	{
		i = (len * (len - 1)) + cpt;
		while (i > cpt)
		{
			j = i - len;
			while (j >= cpt)
			{
				if (add_values(tbl, i, j))
					break ;
				j -= len;
			}
			i -= len;
		}
		cpt++;
	}
	align_down(tbl, len);
	return (0);
}

int			align_up(int **tbl, int len)
{
	int		i;
	int		j;
	int		cpt;

	cpt = 0;
	while (cpt < len)
	{
		i = cpt;
		while (i < ((len - 1) * len) + cpt)
		{
			j = i + len;
			while (j <= cpt + ((len - 1) * len))
			{
				if (switch_values(tbl, i, j))
					break ;
				j += len;
			}
			i += len;
		}
		cpt++;
	}
	return (0);
}

int			up_arrow(int **tbl, int len)
{
	int		i;
	int		j;
	int		cpt;

	cpt = 0;
	while (cpt < len)
	{
		i = cpt;
		while (i < ((len - 1) * len) + cpt)
		{
			j = i + len;
			while (j <= cpt + ((len - 1) * len))
			{
				if (add_values(tbl, i, j))
					break ;
				j += len;
			}
			i += len;
		}
		cpt++;
	}
	align_up(tbl, len);
	return (0);
}

