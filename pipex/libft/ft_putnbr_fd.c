/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarsha <fmarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:41:20 by fmarsha           #+#    #+#             */
/*   Updated: 2021/10/19 02:15:31 by fmarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar_fd(char c, int fd);

static void	loop(int n, int fd)
{
	if (n / 10 == 0)
		ft_putchar_fd('0' - n, fd);
	else
	{
		loop(n / 10, fd);
		ft_putchar_fd('0' - n % 10, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n >= 0)
		loop(-n, fd);
	else
	{
		ft_putchar_fd('-', fd);
		loop(n, fd);
	}
}
