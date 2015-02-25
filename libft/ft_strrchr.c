/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:01:27 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/11 01:49:38 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(const char *str, int c)
{
	int		length;
	int		index;
	char	*found;

	length = ft_strlen((char*)str) + 1;
	index = 0;
	found = 0;
	while ((index < length))
	{
		if (str[index] == c)
		{
			found = &((char*)str)[index];
		}
		index++;
	}
	return (found);
}
