/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:47:59 by ocosquer          #+#    #+#             */
/*   Updated: 2013/12/01 20:36:47 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	int	len_dst;
	int	len_src;
	int	ind_src;
	int	total_len;
	int	max;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen((char*)src);
	ind_src = 0;
	max = (int)n - len_dst - 1;
	total_len = len_dst + len_src;
	if (max > 0)
	{
		dst[len_dst + max] = '\0';
	}
	while (ind_src < max)
	{
		dst[ind_src + len_dst] = src[ind_src];
		ind_src++;
	}
	if ((int)n < len_dst)
	{
		total_len = len_src + (int)n;
	}
	return (total_len);
}
