/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 19:31:52 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/11 01:58:49 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	index;
	char	*str1;
	char	*str2;

	str = (char *)malloc(sizeof(char) * (ft_strlen((char*)s1) +
		ft_strlen((char*)s2)) + 1);
	index = -1;
	str1 = (char*)s1;
	str2 = (char*)s2;
	if (str != NULL)
	{
		while (str1[++index] != '\0')
			str[index] = str1[index];
		while (*str2 != '\0')
		{
			str[index] = *str2;
			str2++;
			index++;
		}
		str[index] = '\0';
	}
	return (str);
}
