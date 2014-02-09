/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboeuf <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 16:37:44 by sboeuf            #+#    #+#             */
/*   Updated: 2014/02/09 16:37:46 by sboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/server.h"

void	catch_1(int s, siginfo_t *info, void *context)
{
	pid_t	pid;

	(void)context;
	pid = info->si_pid;
	add_bit_to_char(pid, s - SIGUSR1);
}

void	catch_2(int s, siginfo_t *info, void *context)
{
	pid_t	pid;

	(void)context;
	pid = info->si_pid;
	add_bit_to_char(pid, s - SIGUSR2 + 1);
}
