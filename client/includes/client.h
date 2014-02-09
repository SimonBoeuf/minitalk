/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboeuf <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 16:40:43 by sboeuf            #+#    #+#             */
/*   Updated: 2014/02/09 16:40:45 by sboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CLIENT_H_
# define _CLIENT_H_

# include <sys/types.h>
# include <signal.h>
# include <unistd.h>
# include "../../libft/libft.h"

void	send_str(int pid, char *str);
int		send_char(int pid, char c);

#endif
