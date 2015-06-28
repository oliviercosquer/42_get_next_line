/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:40:55 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/11 01:45:26 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memset(void *byte, int character, size_t len)
{
	unsigned char	new_char;
	char			*new_array;
	unsigned int	length;

	length = 0;
	new_char = (unsigned char)character;
	new_array = (char*)byte;
	while (length < len)
	{
		new_array[length] = new_char;
		length++;
	}
	return (byte);
}
