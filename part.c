/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpanov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 15:11:32 by dpanov            #+#    #+#             */
/*   Updated: 2017/02/15 15:48:07 by dpanov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		safe_p2(int **board, t_tet *p, t_pos *pos, t_bd *ss)
{
	if ((pos->x + p[ss->counter].x[2]) >= ss->b_s)
		return (0);
	if ((pos->y + p[ss->counter].y[0]) >= ss->b_s)
		return (0);
	if ((pos->y + p[ss->counter].y[1]) >= ss->b_s)
		return (0);
	if ((pos->y + p[ss->counter].y[2]) >= ss->b_s)
		return (0);
	if (board[pos->y + p[ss->counter].y[0]][pos->x + p[ss->counter].x[0]] != 0)
		return (0);
	if (board[pos->y + p[ss->counter].y[1]][pos->x + p[ss->counter].x[1]] != 0)
		return (0);
	if (board[pos->y + p[ss->counter].y[2]][pos->x + p[ss->counter].x[2]] != 0)
		return (0);
	return (1);
}

int		is_safe(int **board, t_tet *p, t_pos *pos, t_bd *ss)
{
	if (board[pos->y][pos->x] != 0)
		return (0);
	if ((pos->x + p[ss->counter].x[0]) < 0)
		return (0);
	if ((pos->x + p[ss->counter].x[1]) < 0)
		return (0);
	if ((pos->x + p[ss->counter].x[2]) < 0)
		return (0);
	if ((pos->y + p[ss->counter].y[0]) < 0)
		return (0);
	if ((pos->y + p[ss->counter].y[1]) < 0)
		return (0);
	if ((pos->y + p[ss->counter].y[2]) < 0)
		return (0);
	if ((pos->x + p[ss->counter].x[0]) >= ss->b_s)
		return (0);
	if ((pos->x + p[ss->counter].x[1]) >= ss->b_s)
		return (0);
	return (safe_p2(board, p, pos, ss));
}

void	asset_var(t_bd *ss, int n)
{
	ss->b_s = 2;
	ss->figur = n;
	ss->counter = 0;
}

void	asset_vvar(t_opens *opens, int tetri[4][4])
{
	opens->j[2] = 0;
	opens->j[0] += if_valid(tetri);
}
