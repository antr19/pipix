/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarsha <fmarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:47:24 by fmarsha           #+#    #+#             */
/*   Updated: 2021/10/27 22:57:17 by fmarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_len_int(int n)
{
	int	len;

	if (n > 0)
		len = 0;
	else
		len = 1;
	if (!n)
		return (1);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*loop(int n, char *s)
{
	if (n / 10 == 0)
		*s = '0' - n;
	else
	{
		s = loop(n / 10, s);
		*s = '0' - n % 10;
	}
	return (++s);
}

char	*ft_itoa(int n)
{
	char	*s;

	s = (char *)malloc(ft_len_int(n) + 1);
	if (!s)
		return (0);
	if (n >= 0)
		*loop(-n, s) = 0;
	else
	{
		*s = '-';
		*loop(n, s + 1) = 0;
	}
	return (s);
}
