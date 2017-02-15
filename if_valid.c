/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpanov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 17:16:22 by dpanov            #+#    #+#             */
/*   Updated: 2017/02/15 15:47:10 by dpanov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		fc(int tetri[4][4], int x, int y)
{
	if (tetri[y + 1][x] == 1 && tetri[y + 2][x] == 1
	&& tetri[y + 2][x + 1] == 1)
		return (1);
	if (tetri[y + 1][x] == 1 && tetri[y + 2][x] == 1
	&& tetri[y + 2][x - 1] == 1)
		return (1);
	if (tetri[y + 1][x] == 1 && tetri[y + 1][x + 1] == 1
	&& tetri[y + 1][x + 2] == 1)
		return (1);
	if (tetri[y + 1][x] == 1 && tetri[y][x + 1] == 1
	&& tetri[y + 2][x] == 1)
		return (1);
	if (tetri[y][x + 1] == 1 && tetri[y + 1][x + 1] == 1
	&& tetri[y + 2][x + 1] == 1)
		return (1);
	if (tetri[y + 1][x] == 1 && tetri[y][x + 1] == 1
	&& tetri[y][x + 1] == 1)
		return (1);
	if (tetri[y + 1][x] == 1 && tetri[y + 1][x - 1] == 1
	&& tetri[y + 1][x - 2] == 1)
		return (1);
	if (tetri[y + 1][x + 2] == 1 && tetri[y][x + 2] == 1
	&& tetri[y][x + 1] == 1)
		return (1);
	return (0);
}

int		fb(int tetri[4][4], int x, int y)
{
	if (tetri[y + 1][x] == 1 && tetri[y + 1][x + 1] == 1
	&& tetri[y + 2][x + 1] == 1)
		return (1);
	if (tetri[y + 1][x] == 1 && tetri[y + 1][x - 1] == 1
	&& tetri[y + 2][x - 1] == 1)
		return (1);
	if (tetri[y][x + 1] == 1 && tetri[y + 1][x] == 1
	&& tetri[y + 1][x - 1] == 1)
		return (1);
	return (fc(tetri, x, y));
}

int		fa(int tetri[4][4], int x, int y)
{
	if (tetri[y][x + 1] == 1 && tetri[y + 1][x] == 1
	&& tetri[y + 1][x + 1] == 1)
		return (1);
	if (tetri[y][x + 1] == 1 && tetri[y][x + 2] == 1
	&& tetri[y][x + 3] == 1)
		return (1);
	if (tetri[y + 1][x] == 1 && tetri[y + 2][x] == 1
	&& tetri[y + 3][x] == 1)
		return (1);
	if (tetri[y][x + 1] == 1 && tetri[y + 1][x + 1] == 1
	&& tetri[y][x + 2] == 1)
		return (1);
	if (tetri[y + 1][x] == 1 && tetri[y + 1][x + 1] == 1
	&& tetri[y + 1][x - 1] == 1)
		return (1);
	if (tetri[y + 1][x] == 1 && tetri[y + 1][x - 1] == 1
	&& tetri[y + 2][x] == 1)
		return (1);
	if (tetri[y + 1][x] == 1 && tetri[y + 1][x + 1] == 1
	&& tetri[y + 2][x] == 1)
		return (1);
	if (tetri[y][x + 1] == 1 && tetri[y + 1][x + 1] == 1
	&& tetri[y + 1][x + 2] == 1)
		return (1);
	return (fb(tetri, x, y));
}

int		if_valid(int tetri[4][4])
{
	int x;
	int y;
	int f[2];

	y = -1;
	f[0] = 0;
	f[1] = 0;
	while (y++ < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tetri[y][x] == 1)
			{
				f[0]++;
				if (f[0] == 1)
					f[1] = fa(tetri, x, y);
			}
			x++;
		}
	}
	if (f[0] == 4 && f[1] == 1)
		return (1);
	else
		return (0);
}

int		validator(char *str)
{
	t_opens	opens;
	int		tetri[4][4];

	ft_memset(opens.j, 0x00, 20);
	opens.j[3] = open(str, O_RDONLY);
	while (read(opens.j[3], &opens.ch, 1) > 0)
	{
		opens.j[4]++;
		if (opens.ch == '.')
			tetri[0][opens.j[2]] = 0;
		if (opens.ch == '#')
			tetri[0][opens.j[2]] = 1;
		if (opens.ch == '\n')
			opens.j[1]++;
		else
			opens.j[2]++;
		if (opens.j[4] % 21 == 0 && opens.ch != '\n')
			return (0);
		if (opens.j[2] == 16)
			asset_vvar(&opens, tetri);
	}
	if ((4 + 5 * (opens.j[0] - 1)) == opens.j[1] && opens.j[0] < 27)
		return (opener(str, opens.j[0]));
	return (0);
}
