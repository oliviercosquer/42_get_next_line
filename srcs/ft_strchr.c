/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:42:18 by ocosquer          #+#    #+#             */
/*   Updated: 2014/09/28 23:18:14 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		length;
	int		index;
	char	*found;

	length = ft_strlen((char*)str) + 1;
	index = 0;
	found = 0;
	while (str && (index < length) && found == 0)
	{
		if (str[index] == c)
		{
			found = (char *)&str[index];
		}
		index++;
	}
	return (found);
}
