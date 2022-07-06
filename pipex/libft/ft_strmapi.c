/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarsha <fmarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:08:26 by fmarsha           #+#    #+#             */
/*   Updated: 2021/10/27 22:58:19 by fmarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ss;
	int		i;

	if (!s)
		return (0);
	ss = (char *)malloc(ft_strlen(s) + 1);
	if (!ss)
		return (0);
	i = -1;
	while (s[++i])
		ss[i] = (*f)(i, s[i]);
	ss[i] = 0;
	return (ss);
}
