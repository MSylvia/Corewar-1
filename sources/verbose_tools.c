/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 05:12:38 by upopee            #+#    #+#             */
/*   Updated: 2018/04/29 05:00:28 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cpu_types.h"
#include "vm_types.h"
#include "cpu.h"
#include "vm_verbose.h"
#include "cpu_verbose.h"
#include "cpu_debug.h"
#include "vm.h"

/*
** -- PRINT THE MSG PARAM AND RETURNS A FAILURE STATUS
*/

int		err_msg(char *msg)
{
	ft_printf(msg);
	return (FAILURE);
}

/*
** -- PRINTS MEMORY ON STDOUT
*/

int		dump_stop(t_cwvm *vm, uint32_t *breakpoint)
{
	ft_printf((vm->ctrl.flags & CWF_SDMP ? CW_SDMPH : CW_DUMPH), vm->cpu.tick);
	debug_memory(vm->arena, vm->a_flags, NULL);
	if (vm->ctrl.flags & CWF_SDMP)
	{
		sleep(DUMP_WAIT);
		*breakpoint += vm->ctrl.dump_cycles;
		return (FALSE);
	}
	return (TRUE);
}

/*
** -- PRINT PC MOVEMENT (CALLED IF THE CORRESPONDING VERBOSE FLAG IS SET)
*/

void	verb_pcmove(uint32_t pc, uint8_t *memory, uint8_t nb_bytes)
{
	ft_printf(V_PCPRINT, nb_bytes, pc, jump_to(pc, nb_bytes));
	while (nb_bytes--)
		ft_printf(V_CELL, memory[pc++]);
	ft_putchar('\n');
}

/*
** -- PRINT READ INSTRUCTION IN ARG DEBUG WINDOW
*/

void	debug_pcmove(uint32_t pc, uint8_t *memory, uint8_t nb_bytes)
{
	char		buff[64];
	uint32_t	ret;
	uint8_t		loops;

	ret = 0;
	loops = nb_bytes;
	while (loops--)
		ret += ft_sprintf(buff + ret, D_CELL, memory[pc++]);
	log_this(ADW, D_ARGREAD, buff, nb_bytes);
}
