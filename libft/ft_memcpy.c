/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:01:41 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/11 01:44:56 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned int	index;
	char			*char1;
	char			*char2;

	index = 0;
	char1 = (char*)s1;
	char2 = (char*)s2;
	while (index < n)
	{
		char1[index] = char2[index];
		index++;
	}
	return (s1);
}
