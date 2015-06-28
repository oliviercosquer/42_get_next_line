/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strljoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 01:40:53 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/11 01:54:59 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strljoin(const char *s1, const char *s2, int n)
{
	char	*str;
	int		length;
	int		i;
	int		j;

	length = ft_strlen((char *)s1) + n;
	str = NULL;
	str = (char *)malloc(sizeof(char) * length + 1);
	i = 0;
	j = 0;
	if (str && s1 && s2)
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
		while (s2[j] && j < n)
		{
			str[i + j] = s2[j];
			j++;
		}
		str[length] = '\0';
	}
	return (str);
}
