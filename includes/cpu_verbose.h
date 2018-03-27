/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpu_verbose.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:28:30 by upopee            #+#    #+#             */
/*   Updated: 2018/03/27 06:16:37 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPU_VERBOSE_H
# define CPU_VERBOSE_H

# define P_CURR_OP	"> {yellow}%s {magenta}(Op. %d){blue} at PC %u\n"
# define P_RNO		"{cyan}R%hhu{eoc}"
# define P_PC		"(PC: {magenta}%u{eoc})"
# define P_HEX		"[{yellow}0x%.2x{eoc}]"
# define P_INT		"[{yellow}%+d{eoc}]"
# define P_HEX_INT	P_HEX " <-> " P_INT

# define P_ARG_OK	"{green}Bytecode OK{eoc} - fetching %hhu args\n"
# define P_ARG_KO	"{red}Bytecode KO{eoc} - PC >> {yellow}+%hhd{eoc}\n"
# define P_ARG_PMPT	" {blue}#%hhu:{eoc} "
# define P_ARG_REG	P_ARG_PMPT "[{cyan}REGISTER{eoc}] | " P_HEX_INT "\n"
# define P_ARG_IND	P_ARG_PMPT "[{magenta}INDIRECT{eoc}] | " P_HEX_INT "\n"
# define P_IND_MOD	"      %% IDX_MOD | " P_HEX_INT "\n"
# define P_ARG_DIR	P_ARG_PMPT "[{yellow}DIRECT{eoc}]   | " P_HEX_INT "\n"

# define LIVE_OK	"{green}LIVE OK:{eoc} Player %u is alive !\n"
# define LIVE_KO	"{red}LIVE KO:{eoc} Player %u does not exist\n"

# define LD_IND		"{green}LD OK:{eoc} " P_PC " >> " P_RNO " | " P_HEX "\n"
# define LD_DIR		"{green}LD OK:{eoc} " P_HEX " >> " P_RNO "\n"
# define LD_KO		"{red}LD KO:{eoc} " P_RNO " does not exists\n"

# define ST_IND		"{green}ST OK:{eoc} " P_RNO " >> " P_PC " | " P_HEX "\n"
# define ST_REG		"{green}ST OK:{eoc} " P_RNO " >> " P_RNO " | " P_HEX "\n"
# define ST_KO		"{red}ST KO:{eoc} " P_RNO " does not exists\n"

# define ADD_OK1	"{green}ADD OK:{eoc} " P_RNO " + " P_RNO " >> " P_RNO
# define ADD_OK		ADD_OK1 " | " P_HEX_INT "\n"
# define ADD_KO		"{red}ADD KO:{eoc} One of the three parameters is invalid\n"

# define SUB_OK1	"{green}SUB OK:{eoc} " P_RNO " - " P_RNO " >> " P_RNO
# define SUB_OK		SUB_OK1 " | " P_HEX_INT "\n"
# define SUB_KO		"{red}SUB KO:{eoc} One of the three parameters is invalid\n"

# define AND_OK1	"{green}AND OK:{eoc} " P_HEX " & " P_HEX " >> " P_RNO
# define AND_OK		AND_OK1 " | " P_HEX "\n"
# define AND_KO		"{red}AND KO:{eoc} " P_RNO " does not exists\n"

# define OR_OK1		"{green}OR OK:{eoc} " P_HEX " | " P_HEX " >> " P_RNO
# define OR_OK		OR_OK1 " | " P_HEX "\n"
# define OR_KO		"{red}OR KO:{eoc} " P_RNO " does not exists\n"

# define XOR_OK1	"{green}XOR OK:{eoc} " P_HEX " ^ " P_HEX " >> " P_RNO
# define XOR_OK		XOR_OK1 " | " P_HEX "\n"
# define XOR_KO		"{red}XOR KO:{eoc} " P_RNO " does not exists\n"

# define ZJMP_OK1	"{green}ZJMP OK:{eoc} [Carry = 1] moving PC of " P_INT
# define ZJMP_OK	ZJMP_OK1 " >> PC" P_INT "\n"
# define ZJMP_KO	"{red}ZJMP KO:{eoc} [Carry = 0] continuing to next op\n"

# define LDI_OK1	"{green}LDI OK:{eoc} " P_INT " + " P_INT " <-> " P_PC
# define LDI_OK		LDI_OK1 " >> " P_RNO " | " P_HEX "\n"
# define LDI_KO		"{red}LDI KO:{eoc} " P_RNO " does not exists\n"

# define STI_OK1	"{green}STI OK:{eoc} " P_RNO " >> " P_INT " + " P_INT
# define STI_OK		STI_OK1 " <-> " P_PC " | " P_HEX "\n"
# define STI_KO		"{red}STI KO:{eoc} " P_RNO " does not exists\n"

# define LLD_IND	"{green}LLD OK:{eoc} " P_PC " >> " P_RNO " | " P_HEX "\n"
# define LLD_DIR	"{green}LLD OK:{eoc} " P_HEX " >> " P_RNO "\n"
# define LLD_KO		"{red}LLD KO:{eoc} " P_RNO " does not exists\n"

# define LLDI_OK1	"{green}LLDI OK:{eoc} " P_INT " + " P_INT " <-> " P_PC
# define LLDI_OK	LLDI_OK1 " >> " P_RNO " | " P_HEX "\n"
# define LLDI_KO	"{red}LLDI KO:{eoc} " P_RNO " does not exists\n"

# define AFF_OK1	"{green}AFF OK:{eoc} Printed '{yellow}%c{eoc}' from " P_RNO
# define AFF_OK		AFF_OK1 "\n"
# define AFF_KO		"{red}AFF KO:{eoc} " P_RNO " does not exists\n"

#endif
