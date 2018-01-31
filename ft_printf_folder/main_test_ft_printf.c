/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_ft_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 17:52:23 by lcabanes          #+#    #+#             */
/*   Updated: 2018/01/31 18:58:09 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(int argc, char **argv)
{
	char	*a;
	int		b;
	char	c;

	a = "42Born2Code";
	b = 42;
	c = 'y';
	if (argc != 2)
	{
		ft_putstr("Passez en argument au programme la phrase a ecrire");
	}
	else
	{
		ft_printf(*(argv + 1), a, b, c);
	}
	return (0);
}
