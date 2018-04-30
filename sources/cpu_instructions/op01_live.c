/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op01_live.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:17:53 by upopee            #+#    #+#             */
/*   Updated: 2018/04/30 17:54:13 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cpu_types.h"
#include "vm_types.h"
#include "cpu.h"
#include "vm.h"
#include "cpu_verbose.h"
#include "cpu_debug.h"

int		live_instr(t_vcpu *cpu, t_process *p, t_player *pl, t_gamectrl *g)
{
	uint32_t	nbl;
	uint32_t	alive;

	secure_fetch(CPU_MEM, jump_to(p->pc, OPBC_SIZE), CPU_ARG, ARG_DIRSZ);
	ARG_DEB ? log_this(ADW, D_ARG_DIR, 1, CPU_ARG[0]) : 0;
	INS_VERB ? ft_printf(V_LIVE, IVA, CPU_ARG[0]) : 0;
	alive = REG_MAXVALUE - TOI32(CPU_ARG[0]) + 1;
	p->last_live = cpu->tick;
	++g->n_lives;
	if (alive > 0 && alive <= MAX_PLAYERS
	&& player_exists(TOU8(alive), g) && ++g->p_lives)
	{
		g->winner = alive;
		g->players[alive - 1].last_live = p->last_live;
		nbl = ++(g->players[alive - 1].nb_lives);
		if (g->alpha == 0 || nbl > g->players[g->alpha - 1].nb_lives)
			g->alpha = alive;
		else if (g->alpha != alive && nbl == g->players[g->alpha - 1].nb_lives)
			g->alpha = 0;
		INS_DEB ? log_this(IDW, D_LIVEPL, IDA, p->pid, alive) : 0;
		LIV_VERB ? ft_printf(V_ALIVE, alive, pl->header.pname) : 0;
	}
	else
		INS_DEB ? log_this(IDW, D_LIVEPR, IDA, p->pid) : 0;
	return (ARG_DIRSZ);
}
