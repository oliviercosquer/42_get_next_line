/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:25:22 by ocosquer          #+#    #+#             */
/*   Updated: 2013/12/01 20:07:24 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int	index;

	index = ft_strlen(s1);
	while (*s2 != '\0')
	{
		s1[index] = *s2;
		index++;
		s2++;
	}
	s1[index] = '\0';
	return (s1);
}
