/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/28 23:16:27 by ocosquer          #+#    #+#             */
/*   Updated: 2015/02/15 23:57:01 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	int				eol;
	int				char_read;
	static char		buffer[BUFF_SIZE];

	if (*line)
		*line = NULL;
	eol = ft_strchr(buffer, '\n') ? 1 : 0;
	if (ft_strlen(buffer) > 0)
		ft_gnl_getnext(line, buffer);
	while (!eol && (char_read = read(fd, buffer, BUFF_SIZE)))
	{
		eol = ft_strchr(buffer, '\n') ? 1 : 0;
		ft_gnl_getnext(line, buffer);
	}
	if (char_read == 0 || ft_strlen(buffer) == 0)
		return (0);
	if (char_read > 0 || eol)
		return (1);
	return (-1);
}

void	ft_gnl_getnext(char **line, char *buffer)
{
	int		pos_n;
	int		len;
	char	*tmp;
	char	*tmp2;

	len = ft_strlen(buffer);
	if (ft_strchr(buffer, '\n'))
	{
		pos_n = ft_strchr(buffer, '\n') - buffer;
		if (ft_strlen(*line))
		{
			tmp = *line;
			tmp2 = ft_strsub(buffer, 0, pos_n);
			*line = ft_strjoin(*line, tmp2);
			ft_strdel(&tmp2);
			ft_strdel(&tmp);
		}
		else
			*line = ft_strsub(buffer, 0, pos_n);
		ft_memmove(buffer, buffer + pos_n + 1, len - pos_n + 1);
		ft_bzero(buffer + len, pos_n);
	}
	else
		ft_gnl_getnext2(line, buffer);
}

void	ft_gnl_getnext2(char **line, char *buffer)
{
	char	*tmp2;
	int		len;

	len = ft_strlen(buffer);
	if (ft_strlen(*line))
	{
		tmp2 = *line;
		*line = ft_strjoin(*line, buffer);
		ft_strdel(&tmp2);
	}
	else
	{
		*line = ft_strdup(buffer);
	}
	ft_bzero(buffer, len);
}
