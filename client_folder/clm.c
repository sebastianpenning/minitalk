/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clm.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/19 15:18:55 by spenning      #+#    #+#                 */
/*   Updated: 2024/03/19 20:41:04 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	len_status_start(pid_t pid, int len_status, c_msg_t *g_msg)
{
	int sleepindex;

	sleepindex = 0;
	while (g_msg->len_status != 2)
	{
		kill(pid, SIGUSR2);
		while (g_msg->len_status != 2 && sleepindex < 100000)
			sleepindex++;
	}
	if (VERBOSE == 1)
	{
		ft_putstr_fd("send sigusr2 lenstatus: ", STDOUT_FILENO);
		ft_putnbr_fd(len_status, STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
}

void	len_status_sending(pid_t pid, c_msg_t *g_msg)
{
	int sleepindex;

	sleepindex = 0;
	while (g_msg->len_status != 4)
	{
		kill(pid, SIGUSR1);
		while (g_msg->len_status != 2 && sleepindex < 100000)
			sleepindex++;
	}
	if (VERBOSE == 1)
		ft_putstr_fd("send sigusr1 len\n", STDOUT_FILENO);
}

void	len_status_end(pid_t pid, int len_status, c_msg_t *g_msg)
{
	int sleepindex;

	sleepindex = 0;
	while (g_msg->len_status != 6)
	{
		kill(pid, SIGUSR2);
		while (g_msg->len_status != 2 && sleepindex < 100000)
			sleepindex++;
	}
	if (VERBOSE == 1)
	{
		ft_putstr_fd("send sigusr2 lenstatus: ", STDOUT_FILENO);
		ft_putnbr_fd(len_status, STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
}

int	len_status_confirmation(void)
{
	if (VERBOSE == 1)
		ft_putstr_fd("len confirmation 2 \n", STDOUT_FILENO);
	return (2);
}

int	len_status_received(void)
{
	if (VERBOSE == 1)
		ft_putstr_fd("message received len \n", STDOUT_FILENO);
	return (4);
}
