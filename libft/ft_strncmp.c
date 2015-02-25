/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:34:41 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/11 01:49:21 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	index;
	unsigned int	len1;
	unsigned int	len2;
	int				diff;

	index = 0;
	len1 = ft_strlen((char*)s1);
	len2 = ft_strlen((char*)s2);
	diff = 0;
	n = n - 1;
	while (index < len1 && index < len2 && s1[index] == s2[index] && index < n)
	{
		index++;
	}
	diff = (int)s1[index] - (int)s2[index];
	diff = (diff < 0) ? -1 : diff;
	diff = (diff > 0) ? 1 : diff;
	return (diff);
}
