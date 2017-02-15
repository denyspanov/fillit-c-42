/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpanov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 13:36:06 by dpanov            #+#    #+#             */
/*   Updated: 2017/02/15 14:55:48 by dpanov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	filler(t_tet *p, int tetri[4][4])
{
	t_pos	pos;
	int		f_p[2];
	int		flag;

	flag = 0;
	pos.y = -1;
	while (++pos.y < 4)
	{
		pos.x = -1;
		while (++pos.x < 4)
		{
			if (tetri[pos.y][pos.x] == 1 && flag != 0)
			{
				p[0].x[flag - 1] = pos.x - f_p[1];
				p[0].y[flag - 1] = pos.y - f_p[0];
				flag++;
			}
			if (tetri[pos.y][pos.x] == 1 && flag == 0)
			{
				f_p[0] = pos.y;
				f_p[1] = pos.x;
				flag++;
			}
		}
	}
}

void	placer(int **board, t_pos *pos, t_tet *p, t_bd *ss)
{
	board[pos->y][pos->x] = pos->s;
	board[pos->y + p[ss->counter].y[0]][pos->x + p[ss->counter].x[0]] = pos->s;
	board[pos->y + p[ss->counter].y[1]][pos->x + p[ss->counter].x[1]] = pos->s;
	board[pos->y + p[ss->counter].y[2]][pos->x + p[ss->counter].x[2]] = pos->s;
	if (ss->counter == ss->figur - 1)
		printsolution(board, ss);
}

int		solver(int **board, t_tet *p, t_bd *ss)
{
	t_pos pos;

	pos.y = 0;
	if (ss->counter >= ss->figur)
		return (1);
	while (pos.y < ss->b_s)
	{
		pos.x = -1;
		while (++pos.x < ss->b_s)
		{
			if (is_safe(board, p, &pos, ss))
			{
				pos.s = p[ss->counter].c;
				placer(board, &pos, p, ss);
				ss->counter++;
				if (solver(board, p, ss))
					return (1);
				ss->counter--;
				pos.s = 0;
				placer(board, &pos, p, ss);
			}
		}
		pos.y++;
	}
	return (0);
}

int		doker(int n, t_tet *p, t_bd *ss)
{
	int i;
	int j;
	int **board;

	board = (int**)malloc(sizeof(int*) * n);
	i = 0;
	while (i < n)
	{
		j = 0;
		board[i] = (int*)malloc(sizeof(int) * n);
		while (j < n)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
	if (solver(board, p, ss) == 0)
	{
		ss->b_s++;
		ss->counter = 0;
		doker(ss->b_s, p, ss);
	}
	return (1);
}

int		opener(char *str, int n)
{
	t_tet	mas[n];
	t_opens opens;
	t_bd	ss;

	asset_var(&ss, n);
	ft_memset(opens.i, 0x00, 12);
	opens.i[0] = open(str, O_RDONLY);
	while (read(opens.i[0], &opens.ch, 1) > 0)
	{
		if (opens.ch == '.')
			opens.tetri[0][opens.i[2]] = 0;
		if (opens.ch == '#')
			opens.tetri[0][opens.i[2]] = 1;
		if (opens.ch != '\n')
			opens.i[2]++;
		if (opens.i[2] == 16)
		{
			opens.i[2] = 0;
			filler(&mas[opens.i[1]], opens.tetri);
			mas[opens.i[1]].c = opens.i[1] + 1;
			opens.i[1]++;
		}
	}
	return (doker(ss.b_s, mas, &ss));
}
