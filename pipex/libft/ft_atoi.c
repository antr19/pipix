/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarsha <fmarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 23:03:34 by fmarsha           #+#    #+#             */
/*   Updated: 2022/06/16 16:33:52 by fmarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c);

int	ft_isspace(char c)
{
	int	term1;
	int	term2;

	term1 = (c == '\t' || c == '\n' || c == '\v');
	term2 = (c == '\f' || c == '\r' || c == ' ');
	return (term1 || term2);
}

int	ft_atoi(const char *str)
{
	int	num;
	int	sign;

	num = 0;
	sign = -1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		str++;
	else if (*str == '+')
	{
		str++;
		sign = 1;
	}
	else
		sign = 1;
	while (*str && ft_isdigit(*str))
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num * sign);
}
