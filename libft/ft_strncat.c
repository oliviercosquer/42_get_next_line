/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:35:56 by ocosquer          #+#    #+#             */
/*   Updated: 2013/12/01 20:11:41 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned int	length_s1;
	unsigned int	index;

	length_s1 = ft_strlen((char*)s1);
	index = 0;
	while (index < n && s2[index] != '\0')
	{
		s1[index + length_s1] = s2[index];
		index++;
	}
	s1[index + length_s1] = '\0';
	return (s1);
}
