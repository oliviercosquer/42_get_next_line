/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:26:23 by ocosquer          #+#    #+#             */
/*   Updated: 2014/09/28 23:17:42 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *byte, size_t len)
{
	char			*tmp_str;
	unsigned int	index;

	tmp_str = (char *)byte;
	index = 0;
	while (index < len)
	{
		tmp_str[index] = 0;
		index++;
	}
}
