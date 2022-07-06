/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarsha <fmarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:34:20 by fmarsha           #+#    #+#             */
/*   Updated: 2021/10/27 23:19:56 by fmarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n_len;

	n_len = ft_strlen(needle);
	if (!n_len)
		return ((char *)haystack);
	while (*haystack && len-- >= n_len)
	{
		if (!ft_strncmp(haystack, needle, n_len))
			return ((char *)haystack);
		haystack++;
	}
	return (0);
}
