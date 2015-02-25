/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:49:14 by ocosquer          #+#    #+#             */
/*   Updated: 2013/12/01 20:37:21 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*str_found;
	size_t	i_s1;
	size_t	i_s2;
	size_t	l_s1;
	size_t	l_s2;

	str_found = 0;
	i_s1 = 0;
	i_s2 = 0;
	l_s1 = ft_strlen((char*)s1);
	l_s2 = ft_strlen((char*)s2);
	str_found = (l_s2 == 0) ? (char*)s1 : 0;
	while ((i_s1 < l_s1) && str_found == 0 && i_s1 < n)
	{
		str_found = &((char*)s1)[i_s1];
		while ((i_s2 < l_s2) && (i_s2 + i_s1) < n)
		{
			str_found = (s1[i_s1 + i_s2] == s2[i_s2]) ? str_found : 0;
			i_s2++;
		}
		i_s2 = 0;
		i_s1++;
	}
	str_found = (ft_strlen((char*)s2) > n) ? 0 : str_found;
	return (str_found);
}
