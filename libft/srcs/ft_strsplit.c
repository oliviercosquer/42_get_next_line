/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 15:29:09 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/11 02:03:08 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_getnextstr(char const *s, char c)
{
	int		start;
	int		end;
	char	*str;

	start = 0;
	end = 0;
	str = 0;
	while (s[start] == c)
		start++;
	end = 1;
	while (s[start + end] != c && s[start + end] != '\0')
		end++;
	str = ft_strsub(s, start, end);
	return (str);
}

size_t	ft_countelemstr(char const *s, char c)
{
	int		nb_elem;
	size_t	i;
	size_t	len;

	nb_elem = 0;
	i = 0;
	len = ft_strlen((char*)s);
	while (i < len)
	{
		while (s[i] == c && i < len && s[i] != '\0')
			i++;
		while (s[i] != c && i < len && s[i] != '\0')
			i++;
		nb_elem += (i <= len && s[i - 1] != c) ? 1 : 0;
		i++;
	}
	return (nb_elem);
}

char	**ft_strsplit(char const *s, char c)
{
	size_t	nb_elem;
	char	**str;
	size_t	i;
	char	*cur;
	char	*src;

	i = 0;
	nb_elem = ft_countelemstr(s, c);
	src = (char*)s;
	str = ft_memalloc(nb_elem);
	while (i < nb_elem)
	{
		cur = ft_getnextstr(src, c);
		str[i] = cur;
		i++;
		src = ft_strstr(s, cur) + ft_strlen(cur);
	}
	return (str);
}
