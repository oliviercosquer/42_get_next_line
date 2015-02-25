/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 18:58:00 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/11 01:43:22 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_atoi(const char *str)
{
	int	negative;
	int	value;

	negative = 1;
	value = 0;
	while (*str == ' ' || ft_isprint(*str) == 0)
		str++;
	negative = (*str == '-' && !ft_isdigit(*str)) ? -1 : negative;
	str += (*str == '+' || *str == '-') ? 1 : 0;
	while (*str && negative != 0 && ft_isdigit(*str))
	{
		negative = (ft_isdigit(*str)) ? negative : 0;
		value = (value * 10) + (*str - '0');
		str++;
	}
	return (value * negative);
}
