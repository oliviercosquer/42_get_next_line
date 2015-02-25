/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 12:04:22 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/11 01:53:04 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memalloc(size_t size)
{
	char			*ptr;
	unsigned int	index;

	ptr = (char*)malloc(size);
	index = 0;
	while (index < size && ptr != 0)
	{
		ptr[index] = 0;
		index++;
	}
	return (void*)ptr;
}
