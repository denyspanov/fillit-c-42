/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpanov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 14:48:26 by dpanov            #+#    #+#             */
/*   Updated: 2017/02/15 14:50:36 by dpanov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putstr(char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		write(1, &src[i], 1);
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	counter;
	char	*str;

	str = (char *)b;
	if (len == 0)
		return (str);
	counter = 0;
	while (counter < len)
	{
		str[counter] = (char)c;
		counter++;
	}
	return (b);
}

void	printsolution(int **board, t_bd *ss)
{
	int i;
	int j;

	i = 0;
	while (i < ss->b_s)
	{
		j = 0;
		while (j < ss->b_s)
		{
			if (board[i][j] != 0)
				ft_putchar((board[i][j] + 16) + '0');
			else
				ft_putstr(".");
			j++;
		}
		ft_putstr("\n");
		i++;
	}
}
