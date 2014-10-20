/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 19:29:33 by ocosquer          #+#    #+#             */
/*   Updated: 2014/09/28 23:18:49 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	index;
	char	*str;

	index = 0;
	str = (char*)malloc(sizeof(char) * len + 1);
	if (str != 0)
	{
		while (index < len)
		{
			str[index] = s[index + start];
			index++;
		}
		str[len] = '\0';
	}
	return (str);
}
