/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 15:28:39 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/11 02:03:42 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strtrim(char const *s)
{
	char	*new_str;
	int		start;
	int		end;
	int		len;

	new_str = (char*)s;
	start = 0;
	len = ft_strlen((char*)s);
	end = len - 1;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	if ((end - start + 1) > 0)
		new_str = ft_strsub((char*)s, start, (size_t)(end - start + 1));
	else
		new_str = ft_strnew(1);
	return (new_str);
}
