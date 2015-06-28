/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:49:14 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/11 01:49:55 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	char	*str_found;
	int		i_s1;
	int		i_s2;
	int		l_s1;
	int		l_s2;

	str_found = 0;
	i_s1 = 0;
	i_s2 = 0;
	l_s1 = ft_strlen((char*)s1);
	l_s2 = ft_strlen((char*)s2);
	str_found = (l_s2 == 0) ? (char*)s1 : 0;
	while ((i_s1 < l_s1) && str_found == 0)
	{
		str_found = &((char*)s1)[i_s1];
		while ((i_s2 < l_s2))
		{
			str_found = (s1[i_s1 + i_s2] == s2[i_s2]) ? str_found : 0;
			i_s2++;
		}
		i_s2 = 0;
		i_s1++;
	}
	return (str_found);
}
