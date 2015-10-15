/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:52:07 by ocosquer          #+#    #+#             */
/*   Updated: 2015/07/05 12:36:53 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnew(size_t size)
{
	char	*ptr;

	ptr = (char*)malloc(sizeof(char) * (size + 1));
	if (ptr != NULL)
	{
		ft_bzero(ptr, size + 1);
	}
	return (ptr);
}
