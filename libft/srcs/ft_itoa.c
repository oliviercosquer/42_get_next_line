/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 15:31:01 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/11 01:54:01 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_reversestr(char *str)
{
	char	*new_str;
	int		len_str;
	int		index;

	len_str = ft_strlen(str) - 1;
	new_str = ft_strnew(len_str);
	index = 0;
	while (index <= len_str)
	{
		new_str[index] = str[len_str - index];
		index++;
	}
	return (new_str);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		negative;
	int		tmp_n;
	int		length;
	int		index;

	negative = (n < 0) ? -1 : 1;
	tmp_n = n;
	length = 0;
	index = 0;
	while (tmp_n != 0)
	{
		length++;
		tmp_n /= 10;
	}
	s = ft_strnew(length + 1);
	while (index < length)
	{
		s[index] = n % 10 * negative + '0';
		index++;
		n /= 10;
	}
	s[index] = (negative == -1) ? '-' : s[index];
	s[index] = (length == 0) ? '0' : s[index];
	return (ft_reversestr(s));
}
