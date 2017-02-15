/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpanov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 13:29:03 by dpanov            #+#    #+#             */
/*   Updated: 2017/02/15 16:18:15 by dpanov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (validator(argv[1]) == 0)
			ft_putstr("error\n");
	}
	else
		ft_putstr("usage: ./fillit file\n");
	return (0);
}
