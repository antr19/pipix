/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarsha <fmarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 01:52:57 by fmarsha           #+#    #+#             */
/*   Updated: 2021/10/27 23:37:10 by fmarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t count, size_t size);

int	count_words(char const *s, char c)
{
	int			num;

	num = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			num++;
		s++;
	}
	return (num);
}

size_t	len_i(char c1, int i)
{
	if (c1 == '\0' && !i)
		return (1);
	return (0);
}

char	**ft_rs(char const *s, char c, char **ss)
{
	size_t	l;
	int		i;
	int		st;

	i = -1;
	st = -1;
	l = 1;
	while (s[++i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			*ss++ = ft_substr(s, st + 1, l + len_i(s[i + 1], s[i] == c));
			if (!*(ss - 1))
				return (0);
			l = 0;
		}
		if (s[i] == c)
			st = i;
		else
			l++;
	}
	return (ss - count_words(s, c));
}

char	**ft_split(char const *s, char c)
{
	char	**ss;

	if (!s)
		return (0);
	ss = (char **)ft_calloc(sizeof(char *) * (count_words(s, c) + 1), 1);
	if (!ss)
		return (0);
	return (ft_rs(s, c, ss));
}
