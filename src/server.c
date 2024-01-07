/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 00:45:21 by isouaidi          #+#    #+#             */
/*   Updated: 2024/01/07 05:40:50 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	handler(int signal)
{
	static unsigned char	c = 0;
	static int				bit_count = 0;

	if (signal == SIGUSR1)
		c |= 1 << bit_count;
	bit_count++;
	if (bit_count == 8)
	{
		if (c == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", c);
		bit_count = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	act;

	ft_printf("pid : %d\n", getpid());
	act.sa_flags = 0;
	bzero(&act, sizeof(act));
	act.sa_handler = handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
