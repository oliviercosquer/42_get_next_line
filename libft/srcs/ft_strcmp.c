/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:07:19 by ocosquer          #+#    #+#             */
/*   Updated: 2015/06/27 20:50:27 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	int	index;
	int	len1;
	int	len2;
	int	diff;

	index = 0;
	len1 = ft_strlen((char*)s1);
	len2 = ft_strlen((char*)s2);
	diff = 0;
	while (index < len1 && index < len2 && s1[index] == s2[index])
	{
		index++;
	}
	diff = (unsigned char)s1[index] - (unsigned char)s2[index];
	return (diff);
}
