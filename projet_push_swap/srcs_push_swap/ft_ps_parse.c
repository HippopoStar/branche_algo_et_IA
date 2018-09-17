/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:44:29 by lcabanes          #+#    #+#             */
/*   Updated: 2018/09/17 15:22:12 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int		ft_ps_str_is_digit(char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (!ft_isdigit(*(str + i)))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int		ft_ps_str_is_zero(char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) != '0')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_ps_load_stack(t_nb **stacks)
{
	while (*(stacks + 1) != NULL)
	{
		ft_ps_push(stacks, 'a');
	}
}

void	ft_ps_parse(t_nb **stacks, int argc, char **argv)
{
	int		index;
	int		nb;

	index = 1;
	while (index < argc)
	{
		if (!ft_ps_str_is_digit(*(argv + index)))
		{
			ft_putstr("Error\n");
			exit(0);
		}
		nb = ft_atoi(*(argv + index));
		if (!(nb == 0 && !ft_ps_str_is_zero(*(argv + index))))
		{
			ft_ps_add_elem(stacks, 'b', nb);
		}
		else
		{
			ft_putstr("Error\n");
			exit(0);
		}
		index++;
	}
	ft_ps_load_stack(stacks);
}
