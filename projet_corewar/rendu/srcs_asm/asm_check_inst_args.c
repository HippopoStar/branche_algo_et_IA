/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_inst_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 17:26:44 by lcabanes          #+#    #+#             */
/*   Updated: 2019/07/10 19:54:30 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"

/*
** Registre en premiere position : 0b01000000 0x40
** Registre en deuxieme position : 0b00010000 0x10
** Registre en troisieme position : 0b00000100 0x04
**
** Direct en premiere position : 0b10000000 0x80
** Direct en deuxieme position : 0b00010000 0x20
** Direct en troisieme position : 0b00001000 0x08
**
** Indirect en premiere position : 0b11000000 0xc0
** Indirect en deuxieme position : 0b00110000 0x30
** Indirect en troisieme position : 0b00001100 0x0c
**
** 01 live
**		|          DIR          |                       |
** 02 ld
**		|          DIR      IND | REG                   |
** 03 st
**		| REG                   | REG               IND |
** 04 add
**		| REG                   | REG                   | REG
** 05 sub
**		| REG                   | REG                   | REG
** 06 and
**		| REG      DIR      IND | REG      DIR      IND | REG
** 07 or
**		| REG      DIR      IND | REG      DIR      IND | REG
** 08 xor
**		| REG      DIR      IND | REG      DIR      IND | REG
** 09 zjmp
**		|          DIR          |                       |
** 10 ldi
**		| REG      DIR      IND | REG      DIR          | REG
** 11 sti
**		| REG                   | REG      DIR      IND | REG      DIR
** 12 fork
**		|          DIR          |                       |
** 13 lld
**		|          DIR      IND | REG                   |
** 14 lldi
**		| REG      DIR      IND | REG      DIR          | REG
** 15 lfork
**		|          DIR          |                       |
** 16 aff
**		| REG
*/

/*
**	ft_putstr("'asm_check_register'\n");
*/

static int	asm_check_register(char op_code, size_t i)
{
	if (i == 0 && (op_code == (char)3 || op_code == (char)4\
				|| op_code == (char)5 || op_code == (char)6\
				|| op_code == (char)7 || op_code == (char)8\
				|| op_code == (char)10 || op_code == (char)11\
				|| op_code == (char)14 || op_code == (char)16))
	{
		return (1);
	}
	else if (i == 1 && (op_code == (char)2 || op_code == (char)3\
				|| op_code == (char)4 || op_code == (char)5\
				|| op_code == (char)6 || op_code == (char)7\
				|| op_code == (char)8 || op_code == (char)10\
				|| op_code == (char)11 || op_code == (char)13\
				|| op_code == (char)14))
	{
		return (1);
	}
	else if (i == 2 && (op_code == (char)4 || op_code == (char)5\
				|| op_code == (char)6 || op_code == (char)7\
				|| op_code == (char)8 || op_code == (char)10\
				|| op_code == (char)11 || op_code == (char)14))
	{
		return (1);
	}
	return (0);
}

/*
**	ft_putstr("'asm_check_direct'\n");
*/

static int	asm_check_direct(char op_code, size_t i)
{
	if (i == 0 && (op_code == (char)1 || op_code == (char)2\
				|| op_code == (char)6 || op_code == (char)7\
				|| op_code == (char)8 || op_code == (char)9\
				|| op_code == (char)10 || op_code == (char)12\
				|| op_code == (char)13 || op_code == (char)14\
				|| op_code == (char)15))
	{
		return (1);
	}
	else if (i == 1 && (op_code == (char)6 || op_code == (char)7\
				|| op_code == (char)8 || op_code == (char)10\
				|| op_code == (char)11 || op_code == (char)14))
	{
		return (1);
	}
	else if (i == 2 && op_code == (char)11)
	{
		return (1);
	}
	return (0);
}

/*
**	ft_putstr("'asm_check_indirect'\n");
*/

static int	asm_check_indirect(char op_code, size_t i)
{
	if (i == 0 && (op_code == (char)2 || op_code == (char)6\
				|| op_code == (char)7 || op_code == (char)8\
				|| op_code == (char)10 || op_code == (char)13\
				|| op_code == (char)14))
	{
		return (1);
	}
	else if (i == 1 && (op_code == (char)3 || op_code == (char)6\
				|| op_code == (char)7 || op_code == (char)8\
				|| op_code == (char)11))
	{
		return (1);
	}
	return (0);
}

/*
**		ft_putstr("'asm_check_inst_args' : ");
**		ft_putnbr((int)i);
**		ft_putchar('\n');
*/

int			asm_check_inst_args(t_asm_inst *inst)
{
	size_t	i;

	i = 0;
	while (i < inst->nb_of_args)
	{
		if ((inst->arg + i)->check == (char)1\
				&& !asm_check_register(inst->op_code, i))
			return (0);
		else if ((inst->arg + i)->check == (char)2\
				&& !asm_check_direct(inst->op_code, i))
			return (0);
		else if ((inst->arg + i)->check == (char)3\
				&& !asm_check_indirect(inst->op_code, i))
			return (0);
		i++;
	}
	return (1);
}
