/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 10:47:46 by chafonta          #+#    #+#             */
/*   Updated: 2026/01/24 08:11:26 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_CHECKER_H
# define BONUS_CHECKER_H

# include "../includes/push_swap.h"
# include "get_next_line_bonus.h"

//		silent_pushswap_operations_p_bonus.c
void	s_pa(t_pushswap *data);
void	s_pb(t_pushswap *data);

//		silent_pushswap_operations_r_bonus.c
void	s_ra(t_pushswap *data);
void	s_rb(t_pushswap *data);
void	s_rr(t_pushswap *data);

//		silent_pushswap_operations_rr_bonus.c
void	s_rra(t_pushswap *data);
void	s_rrb(t_pushswap *data);
void	s_rrr(t_pushswap *data);

//		silent_pushswap_operations_s_bonus.c
void	s_sa(t_pushswap *data);
void	s_sb(t_pushswap *data);
void	s_ss(t_pushswap *data);

#endif
