/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 19:31:52 by ocosquer          #+#    #+#             */
/*   Updated: 2014/09/29 00:12:58 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;

	str = (char*)malloc(sizeof(char) * (ft_strlen((char*)s1) +
				ft_strlen((char*)s2)) + 1);
	i = 0;
	if (str)
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
		while (*s2)
		{
			str[i] = *s2;
			s2++;
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
