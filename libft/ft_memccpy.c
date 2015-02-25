/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:17:23 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/11 01:54:06 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned int	index;
	int				found;
	char			*char1;
	char			*char2;
	char			*ptr;

	char1 = (char*)s1;
	char2 = (char*)s2;
	index = 0;
	found = 0;
	ptr = 0;
	while (index < n && found == 0)
	{
		found = (char2[index] == ((char)c)) ? 1 : 0;
		ptr = (found == 1) ? &char1[index + 1] : 0;
		char1[index] = (found == 0) ? char2[index] : char2[index];
		index++;
	}
	return (ptr);
}
