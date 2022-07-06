/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarsha <fmarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:11:14 by fmarsha           #+#    #+#             */
/*   Updated: 2021/10/15 22:29:49 by fmarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlen(const char *s);

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	d_len;
	size_t	s_len;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (d_len >= dstsize)
		return (dstsize + s_len);
	else
	{
		i = 0;
		while ((d_len + i++) < (dstsize - 1) && src[i - 1])
			dst[d_len + i - 1] = src[i - 1];
		dst[d_len + i - 1] = 0;
		return (d_len + s_len);
	}
}
