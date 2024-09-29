/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:37:00 by javperez          #+#    #+#             */
/*   Updated: 2023/12/07 17:46:44 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include "../ft_printf/ft_printf.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	int		result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\v'
		|| nptr[i] == '\r' || nptr[i] == '\n' || nptr[i] == '\f')
		i++;
	if (nptr[i] == '-')
	{
		if (nptr[i + 1] == '+')
			return (0);
		sign = -1;
		i++;
	}
	if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

void	send_string_bitwise(int pid, const char *message)
{
	int		i;
	int		j;
	char	c;
	int		bit;

	i = 0;
	while (i < ft_strlen(message))
	{
		c = message[i];
		j = 7;
		while (j >= 0)
		{
			bit = (c >> j) & 1;
			if (bit == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			j --;
		}
		i ++;
	}
}

void	send_new_line(int pid)
{
	int		i;
	int		j;
	char	*str;
	char	c;
	int		bit;

	str = "\n";
	i = 0;
	while (i < ft_strlen(str))
	{
		c = str[i];
		j = 7;
		while (j >= 0)
		{
			bit = (c >> j) & 1;
			if (bit == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			j --;
		}
		i ++;
	}
}

int	main(int argc, char **argv)
{
	int	server_pid;

	server_pid = ft_atoi(argv[1]);
	if (argc != 3)
	{
		write(1, "\e[1;91mUse: ./client <PID> <'Text here'>\n", 40);
		return (1);
	}
	if (*argv[2] == '\0')
	{
		write(1, "\e[1;91m⛔ Empty string, try again\n", 34);
		return (1);
	}
	if (kill(server_pid, 0) == 0)
	{
		send_string_bitwise(server_pid, argv[2]);
		usleep(50000);
		send_new_line(server_pid);
		write(1, "\n\e[1;37m✅ Message sent \e[1;32msuccessfully\n", 44);
	}
	else
		write(1, "\e[1;91m⛔ Please enter a valid \e[1;96mPID\n", 42);
	return (0);
}
