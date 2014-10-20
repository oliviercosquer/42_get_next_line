/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:52:07 by ocosquer          #+#    #+#             */
/*   Updated: 2013/12/01 20:38:55 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr;

	ptr = (char*)malloc(size + 1);
	if (ptr != NULL)
	{
		ft_bzero(ptr, size + 1);
	}
	return (ptr);
}
