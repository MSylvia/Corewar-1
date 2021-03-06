/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op04_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:19:44 by upopee            #+#    #+#             */
/*   Updated: 2018/05/03 06:30:20 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cpu_types.h"
#include "sdl_types.h"
#include "vm_types.h"
#include "cpu.h"
#include "vm.h"
#include "cpu_verbose.h"
#include "cpu_debug.h"

int		add_instr(t_vcpu *cpu, t_process *p)
{
	uint32_t	*r;
	uint8_t		r_a;
	uint8_t		r_b;
	uint8_t		r_dst;

	r = p->registers;
	r_a = TOU8(CPU_ARG[0]);
	r_b = TOU8(CPU_ARG[1]);
	r_dst = TOU8(CPU_ARG[2]);
	r[r_dst - 1] = TOU32(TOI32(r[r_a - 1]) + TOI32(r[r_b - 1]));
	p->carry = (r[r_dst - 1] == 0);
	if (INS_DEB)
		log_this(IDW, D_ADD, IDA, r_a, r_b, r[r_dst - 1], r_dst, p->carry);
	INS_VERB ? ft_printf(V_ADD, IVA, r_a, r_b, r_dst) : 0;
	return (0);
}
