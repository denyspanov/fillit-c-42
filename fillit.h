/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpanov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 14:01:32 by dpanov            #+#    #+#             */
/*   Updated: 2017/02/15 16:10:27 by dpanov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILLIT_FILLIT_H
# define _FILLIT_FILLIT_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct	s_tet
{
	int			c;
	int			x[3];
	int			y[3];
}				t_tet;
typedef	struct	s_bd
{
	int			b_s;
	int			figur;
	int			counter;
}				t_bd;
typedef	struct	s_pos
{
	int			x;
	int			y;
	int			s;
}				t_pos;
typedef	struct	s_opens
{
	int			tetri[4][4];
	int			i[3];
	int			j[5];
	char		ch;
}				t_opens;
int				validator(char *str);
void			ft_putstr(char *src);
void			*ft_memset(void *b, int c, size_t len);
int				opener(char *str, int n);
int				doker(int n, t_tet *p, t_bd *ss);
void			printsolution(int **board, t_bd *ss);
int				is_safe(int **board, t_tet *p, t_pos *pos, t_bd *ss);
void			asset_var(t_bd *ss, int n);
void			asset_vvar(t_opens *opens, int tetri[4][4]);
int				if_valid(int tetri[4][4]);
#endif
