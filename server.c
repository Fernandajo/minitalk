/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:18:48 by fjoestin          #+#    #+#             */
/*   Updated: 2024/04/25 13:13:38 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libraries/ft_printf/ft_printf.h"
#include "libraries/Libft/libft.h"
#include <stdlib.h>
#include <signal.h>

void	signal_handler(int signal)
{
	static unsigned char	ch;
	static int				i = 0;
	
	if (signal == SIGUSR1)
		ch |= (1 << i);
	else if (signal == SIGUSR2)
		ch |= (0 << i);
	i++;
	if (i == 8)
	{
		ft_putchar_fd(ch, 1);
		i = 0;
		ch = 0;
	}
}

void	recieving_signals(void)
{
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
}

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	
	while(1)
		recieving_signals();
	return (0);
}
