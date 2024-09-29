/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:19:41 by javperez          #+#    #+#             */
/*   Updated: 2023/12/18 17:54:42 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>
#include "../ft_printf/ft_printf.h"


void	signal_handler(int sig)
{
	static int	bit_count = 0;
	static char	g_message = 0;

	if (sig == SIGUSR1)
		g_message = (g_message << 1) | 1;
	else if (sig == SIGUSR2)
		g_message = (g_message << 1);
	bit_count++;
	if (bit_count == 8)
	{
		ft_printf("%c", g_message);
		bit_count = 0;
		g_message = 0;
	}
}

int	main(void)
{
	int	server_pid;

	server_pid = getpid();
	ft_printf("📪 \e[1;97mSERVER PID: %d\n", server_pid);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		sleep (1);
	return (0);
}
