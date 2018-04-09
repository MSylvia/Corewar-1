/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 02:06:49 by upopee            #+#    #+#             */
/*   Updated: 2018/04/09 08:35:15 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cpu_types.h"
#include "corewar_types.h"
#include "corewar_verbose.h"
#include "corewar.h"

/*
** -- PRINTS THE GIVEN MEMORY CELL IN THE RIGHT COLOR
*/

uint32_t		print_cell(char *buff, uint8_t mem_cell, uint8_t player_no)
{
	if (player_no == 1)
		return (ft_sprintf(buff, PCCOLOR_P1, mem_cell));
	else if (player_no == 2)
		return (ft_sprintf(buff, PCCOLOR_P2, mem_cell));
	else if (player_no == 3)
		return (ft_sprintf(buff, PCCOLOR_P3, mem_cell));
	else if (player_no == 4)
		return (ft_sprintf(buff, PCCOLOR_P4, mem_cell));
	else if (mem_cell != 0)
		return (ft_sprintf(buff, MEMSET_COLOR, mem_cell));
	else
		return (ft_sprintf(buff, MEMZERO_COLOR, mem_cell));
}

/*
** -- PRINT MEMORY CONTENT (IN HEX)
**    > Print the cpu->pc in red, and the filled memory cells in yellow
*/

void			print_memory(t_cwdata *env, char *win)
{
	char		buff[PRINT_BUFF_SIZE];
	uint32_t	i;
	uint32_t	ret;

	i = 0;
	ret = 0;
	win != NULL ? clear_window(win) : (void)0;
	win != NULL ? ret += ft_sprintf(buff, MEM_HEADER, env->cpu.tick) : (void)0;
	while (i < MEM_SIZE)
	{
		if ((i & (BPL - 1)) == 0)
			ret += ft_sprintf(buff + ret, MEM_VALUE, ((i / BPL) * BPL));
		ret += print_cell(buff + ret, env->arena[i], is_pc_val(i, env));
		i++;
		if ((i & (BPL - 1)) == 0)
			ret += ft_sprintf(buff + ret, "\n");
	}
	win != NULL ? ret += ft_sprintf(buff + ret, MEM_FOOTER,
			env->control.to_die, env->control.last_check,
			env->control.max_checks, env->control.nb_processes) : (void)0;
	log_this(win, 0, buff);
}

/*
** -- PRINTS THE N ARGS FROM GIVEN START
**    > mod = 1 : Prints the reg numbers line
**    > mod = 2 : Prints the separator line
**    > mod = 4 : Prints the registers content spaced by separators
*/

static uint32_t	print_nregs(char *dst, uint32_t *r, uint8_t s, uint8_t mod)
{
	uint8_t		i;
	uint32_t	ret;

	ret = 0;
	ret += ft_sprintf(dst + ret, mod & 3 ? REG_BEGL1 : REG_BEGL2);
	i = s + (REG_NUMBER >> 1);
	if (mod == (1 << 0))
		while (s++ < i)
			ret += ft_sprintf(dst + ret, REGN, s);
	else if (mod == (1 << 1))
		while (s++ < i)
			ret += ft_sprintf(dst + ret, REG_SEPL);
	else if (mod == (1 << 2))
		while (s++ < i)
		{
			ret += ft_sprintf(dst + ret, r[s - 1] ?
								REGSET_COLOR : REGZERO_COLOR, r[s - 1]);
			ret += ft_sprintf(dst + ret, REG_SEPH);
		}
	return (ret);
}

/*
** -- PRINT REGISTERS HEADER AND CONTENT (IN HEX)
*/

void			print_registers(t_process *p, char *win)
{
	char		buff[PRINT_BUFF_SIZE * 4];
	uint32_t	ret;

	win ? clear_window(win) : (void)ret;
	if (p == NULL)
	{
		log_this(win, 0, REG_HEADER, 0, 0);
		return ;
	}
	ret = 0;
	ret += ft_sprintf(buff, REG_HEADER, p->carry, p->timer);
	ret += print_nregs(buff + ret, p->registers, 0, (1 << 0));
	ret += print_nregs(buff + ret, p->registers, 0, (1 << 2));
	ret += print_nregs(buff + ret, p->registers, 0, (1 << 1));
	ret += print_nregs(buff + ret, p->registers, (REG_NUMBER >> 1), (1 << 2));
	ret += print_nregs(buff + ret, p->registers, (REG_NUMBER >> 1), (1 << 0));
	log_this(win, 0, buff);
}

// void			vm_log(char *win, char *msg, ...)
// {
// 	va_list	args;
//
// 	if (win)
//
// 	va_start(args, msg);
// 	va_end(args);
// }
