/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:27:05 by ocosquer          #+#    #+#             */
/*   Updated: 2014/09/28 23:18:28 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		length;
	int		index;
	char	*new_str;

	length = ft_strlen((char*)str);
	index = 0;
	new_str = (char*)malloc(sizeof(char) * length + 1);
	if (new_str)
	{
		while (index < length)
		{
			new_str[index] = str[index];
			index++;
		}
	}
	return (new_str);
}
