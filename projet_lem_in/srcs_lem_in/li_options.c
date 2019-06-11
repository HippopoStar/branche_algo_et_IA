/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 22:33:57 by lcabanes          #+#    #+#             */
/*   Updated: 2019/06/07 22:44:28 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		li_options(t_data *data, int argc, char **argv)
{
	if ((data->options = ft_options(argc, argv, "hcl", 0)) == -1)
	{
		return (0);
	}
	else
	{
		data->help = (data->options >> ('h' - 'a')) % 2;
		data->color = (data->options >> ('c' - 'a')) % 2;
		data->display_steps = (size_t)((data->options >> ('l' - 'a')) % 2);
	}
	return (1);
}