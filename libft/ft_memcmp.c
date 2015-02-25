/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 18:35:14 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/11 01:54:12 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				diff;
	unsigned int	index;
	unsigned char	*str1;
	unsigned char	*str2;

	diff = 0;
	index = 0;
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	while (index < n && diff == 0)
	{
		diff = ((int)str1[index] - (int)str2[index]);
		index++;
	}
	return (diff);
}
