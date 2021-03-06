/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op15_lfork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:26:08 by upopee            #+#    #+#             */
/*   Updated: 2018/05/03 06:30:49 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cpu_types.h"
#include "sdl_types.h"
#include "vm_types.h"
#include "cpu.h"
#include "vm.h"
#include "cpu_verbose.h"
#include "vm_verbose.h"
#include "cpu_debug.h"

int		lfork_instr(t_vcpu *cpu, t_process *p, t_player *pl)
{
	t_vmctrl	*ctrl;
	t_jobctrl	*jobs;
	t_process	*child;
	int16_t		index;

	ctrl = cpu->ctrl;
	jobs = cpu->jobs;
	secure_fetch(CPU_MEM, jump_to(p->pc, OPBC_SIZE), CPU_ARG, ARG_INDSZ);
	index = TOI16(CPU_ARG[0]);
	if ((child = dup_process(cpu, pl, p, jump_to(p->pc, index))) != NULL)
	{
		if (ctrl->flags & CWF_SLOW)
			ctrl->sleep_time = 1000000 /
								(ctrl->cycles_sec * jobs->nb_processes);
		ARG_DEB ? log_this(ADW, D_ARG_DIR, 1, TOI16(CPU_ARG[0])) : 0;
		INS_DEB ? log_this(IDW, D_LFORK, IDA, child->pid, index, child->pc) : 0;
		INS_VERB ? ft_printf(V_LFORK, IVA, index, p->pc + index) : 0;
	}
	else
		ft_putstr_fd(CWE_MALLOC, STDERR_FILENO);
	return (ARG_INDSZ);
}
