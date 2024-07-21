/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:18:45 by fjoestin          #+#    #+#             */
/*   Updated: 2024/04/25 13:39:30 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libraries/ft_printf/ft_printf.h"
#include "libraries/Libft/libft.h"
#include <stdlib.h>
#include <signal.h>

void	message(int pid, char *message)
{
	int	i;
	int	j;
	int	letter;
	
	i = 0;
	while (message[i] != '\0')
	{
		letter = message[i];
		j = 0;
		while (j < 8)
		{
			if ((letter >> j & 1) == 1)
			{
				kill(pid, SIGUSR1);
			}
			else
			{
				kill(pid, SIGUSR2);
			}
			usleep(100);
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		message(pid, argv[2]);
		message(pid, "\n");
	}
	else
		ft_printf("Wrong amount of arguments\n");
	return(0);
}
