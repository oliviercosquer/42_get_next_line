/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:00:25 by ocosquer          #+#    #+#             */
/*   Updated: 2013/12/08 16:22:36 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	unsigned int	length_s2;
	unsigned int	index;

	length_s2 = ft_strlen((char*)s2);
	index = 0;
	while (index < length_s2 && index < n)
	{
		s1[index] = s2[index];
		index++;
	}
	while (index < n)
	{
		s1[index] = '\0';
		index++;
	}
	return (s1);
}
