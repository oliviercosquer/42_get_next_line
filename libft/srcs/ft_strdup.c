/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:27:05 by ocosquer          #+#    #+#             */
/*   Updated: 2015/06/28 19:51:07 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

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
		new_str[length] = '\0';
	}
	return (new_str);
}
