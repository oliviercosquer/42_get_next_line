/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:34:41 by ocosquer          #+#    #+#             */
/*   Updated: 2015/06/27 20:51:53 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	index;
	unsigned int	len1;
	unsigned int	len2;
	int				diff;

	if (n == 0)
		return (0);
	index = 0;
	len1 = ft_strlen((char*)s1);
	len2 = ft_strlen((char*)s2);
	diff = 0;
	n = n - 1;
	while (index < len1 && index < len2 && s1[index] == s2[index] && index < n)
	{
		index++;
	}
	diff = (unsigned char)s1[index] - (unsigned char)s2[index];
	return (diff);
}
