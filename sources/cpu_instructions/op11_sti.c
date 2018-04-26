/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op11_sti.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:24:39 by upopee            #+#    #+#             */
/*   Updated: 2018/04/25 19:04:14 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cpu_types.h"
#include "vm_types.h"
#include "cpu.h"
#include "vm.h"
#include "cpu_verbose.h"
#include "cpu_debug.h"

int		sti_instr(t_vcpu *cpu, t_process *p)
{
	uint32_t	*r;
	uint16_t	pc_dst;
	int16_t		index;
	uint8_t		r_src;

	r = p->registers;
	r_src = TOU8(CPU_ARG[0]);
	decode_arg(cpu->memory, p, (CPU_OPBC >> 4) & 3, CPU_ARG + 1);
	decode_arg(cpu->memory, p, (CPU_OPBC >> 2) & 3, CPU_ARG + 2);
	index = TOI16((TOI32(CPU_ARG[1]) + TOI32(CPU_ARG[2])) % IDX_MOD);
	pc_dst = jump_to(p->pc, index);
	secure_store(pc_dst, CPU_MEM, r[r_src - 1], REG_SIZE);
	INS_DEB ? log_this(IDW, D_STI, IDA,
		r[r_src - 1], r_src, CPU_ARG[1], CPU_ARG[2], pc_dst) : 0;
	INS_VERB ? ft_printf(V_STI, IVA, r_src, CPU_ARG[1], CPU_ARG[2],
		CPU_ARG[1], CPU_ARG[2], CPU_ARG[1] + CPU_ARG[2], pc_dst) : 0;
	return (0);
}
