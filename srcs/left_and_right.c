/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_and_right.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avacher <avacher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 22:25:52 by avacher           #+#    #+#             */
/*   Updated: 2016/01/31 22:25:52 by avacher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int			align_left(int **tbl, int len)
{
	int		i;
	int		j;
	int		cpt;

	cpt = 0;
	while (cpt < len)
	{
		i = cpt * len;
		while (i < len + (cpt * len))
		{
			j = i + 1;
			while (j < len + (cpt * len))
			{
				if (switch_values(tbl, i, j))
					break ;
				j++;
			}
			i++;
		}
		cpt++;
	}
	return (0);
}

int					left_arrow(int **tbl, int len)
{
	int		i;
	int		j;
	int		cpt;

	cpt = 0;
	while (cpt < len)
	{
		i = cpt * len;
		while (i < (len + (cpt * len)))
		{
			j = i + 1;
			while (j < len + (cpt * len))
			{
				if (add_values(tbl, i, j))
					break ;
				j++;
			}
			i++;
		}
		cpt++;
	}
	align_left(tbl, len);
	return (0);
}

static int			align_right(int **tbl, int len)
{
	int		i;
	int		j;
	int		cpt;

	cpt = 0;
	while (cpt < len)
	{
		i = len - 1 + (cpt * len);
		while (i > (cpt * len))
		{
			j = i - 1;
			while (j >= (cpt * len))
			{
				if (switch_values(tbl, i, j))
					break ;
				j--;
			}
			i--;
		}
		cpt++;
	}
	return (0);
}

int					right_arrow(int **tbl, int len)
{
	int		i;
	int		j;
	int		cpt;

	cpt = 0;
	while (cpt < len)
	{
		i = len - 1 + (cpt * len);
		while (i > (cpt * len))
		{
			j = i - 1;
			while (j >= (cpt * len))
			{
				if (add_values(tbl, i, j))
					break ;
				j--;
			}
			i--;
		}
		cpt++;
	}
	align_right(tbl, len);
	return (0);
}
