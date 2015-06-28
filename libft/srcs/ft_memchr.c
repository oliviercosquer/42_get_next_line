/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:36:04 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/11 01:44:37 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			*str;
	char			character;
	char			*ptr;
	unsigned int	index;

	str = (char*)s;
	character = (char)c;
	ptr = 0;
	index = 0;
	while (index < n && ptr == 0)
	{
		if (str[index] == character)
		{
			ptr = &str[index];
		}
		index++;
	}
	return ((void*)ptr);
}
