/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:02:37 by isouaidi          #+#    #+#             */
/*   Updated: 2024/01/07 05:40:45 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	sendbit(int pid, int bit)
{
	if (bit)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			ft_printf("Erreur lors de l'envoi du signal");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			ft_printf("Erreur lors de l'envoi du signal");
			exit(EXIT_FAILURE);
		}
	}
}

void	send_char(int pid, char c)
{
	int	bit_count;

	bit_count = 0;
	while (bit_count < 8)
	{
		sendbit(pid, (c >> bit_count) & 1);
		usleep(100);
		bit_count++;
	}
	usleep(50);
}

int	main(int ac, char **av)
{
	pid_t		pid;
	int			i;

	i = 0;
	if (ac != 3)
	{
		ft_printf("probleme arguement");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(av[1]);
	while (av[2][i])
	{
		send_char(pid, av[2][i]);
		i++;
	}
	send_char(pid, '\0');
}
