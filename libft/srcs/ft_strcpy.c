/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:43:15 by ocosquer          #+#    #+#             */
/*   Updated: 2013/12/01 20:08:52 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strcpy(char *s1, const char *s2)
{
	int	length_s2;
	int	index;

	length_s2 = ft_strlen((char*)s2);
	index = 0;
	while (index < length_s2)
	{
		s1[index] = s2[index];
		index++;
	}
	s1[index] = '\0';
	return (s1);
}
