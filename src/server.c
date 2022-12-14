/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmallawa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:15:09 by rmallawa          #+#    #+#             */
/*   Updated: 2022/10/03 14:27:46 by rmallawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minitalk.h"

static void	response(unsigned int *c_pid)
{
	kill(*c_pid, SIGUSR1);
	*c_pid = 0;
}

static void	handler_s(int sig, siginfo_t *siginfo, void *optional)
{
	static unsigned char	c = 0;
	static int				i = 0;
	static unsigned int		c_pid = 0;

	(void)optional;
	if (!c_pid)
		c_pid = siginfo->si_pid;
	c |= (sig == SIGUSR1);
	if (++i == 8)
	{
		i = 0;
		if (!c)
			return (response(&c_pid));
		ft_putchar(c);
		c = 0;
		kill(c_pid, SIGUSR2);
	}
	else
		c = c << 1;
}

int	main(void)
{
	struct sigaction	sa;

	ft_putstr("Mandatory part!\n");
	ft_putstr("Server is actually running\n");
	ft_putstr("PID : ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	sa.sa_sigaction = handler_s;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, 0) == -1)
		return (EXIT_FAILURE);
	if (sigaction(SIGUSR2, &sa, 0) == -1)
		return (EXIT_FAILURE);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
