/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarsha <fmarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 00:36:46 by fmarsha           #+#    #+#             */
/*   Updated: 2021/10/27 20:58:17 by fmarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	ss_len;
	char	*ss;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start > s_len)
	{
		ss = (char *)malloc(1);
		if (ss)
			*ss = 0;
		return (ss);
	}
	else if ((s_len - start) > len)
		ss_len = len + 1;
	else
		ss_len = s_len - start + 1;
	ss = (char *)malloc(ss_len);
	if (ss)
		ft_strlcpy(ss, s + start, ss_len);
	return (ss);
}
