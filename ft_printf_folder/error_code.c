/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 23:59:07 by lcabanes          #+#    #+#             */
/*   Updated: 2018/02/04 00:00:33 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	error_code(char *error_message)
{
	ft_putstr(error_message);
	ft_putchar('\n');
	exit(-1);
}
