/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpu.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 16:22:49 by upopee            #+#    #+#             */
/*   Updated: 2018/03/02 16:50:51 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPU_H
# define CPU_H

/*
** --------- CPU CORE ------------
*/

/*
** --------- CPU TOOLS ------------
*/

void	init_cpu(t_vcpu *cpu);
void 	load_process(t_vcpu *cpu, uint8_t *process_regs, uint8_t *process_pc);

/*
**	-------- CPU _DEBUG  ---------
*/

void	print_memory(char *name, uint8_t *s, uint32_t len, uint8_t *pc);
void	print_cpu(t_vcpu *cpu);

#endif
