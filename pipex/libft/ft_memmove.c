/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarsha <fmarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:30:22 by fmarsha           #+#    #+#             */
/*   Updated: 2021/10/15 17:30:22 by fmarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*d;

	if (!dest && !src)
		return (0);
	d = dest;
	if (dest < src)
	{
		while (n--)
			*(char *)(dest++) = *(char *)(src++);
	}
	else
	{
		while (n--)
			*(char *)(dest + n) = *(char *)(src + n);
	}
	return (d);
}
