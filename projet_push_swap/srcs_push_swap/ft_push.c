/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 19:27:50 by lcabanes          #+#    #+#             */
/*   Updated: 2019/01/16 19:28:18 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_nb *stacks[2], char c)
{
	t_nb	*tmp;

	tmp = *(stacks + ((c - 'a' + 1) % 2));
	if (tmp != NULL)
	{
		*(stacks + ((c - 'a' + 1) % 2)) = tmp->next;
		tmp->next = *(stacks + (c - 'a'));
		*(stacks + (c - 'a')) = tmp;
	}
}