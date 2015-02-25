/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:07:19 by ocosquer          #+#    #+#             */
/*   Updated: 2013/12/01 20:08:21 by ocosquer         ###   ########.fr       */
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
	diff = (int)s1[index] - (int)s2[index];
	diff = (diff < 0) ? -1 : diff;
	diff = (diff > 0) ? 1 : diff;
	return (diff);
}
