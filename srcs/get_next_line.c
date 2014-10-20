/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/28 23:16:27 by ocosquer          #+#    #+#             */
/*   Updated: 2014/09/29 00:17:52 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

int		get_next_line(int fd, char **line)
{
	int				eof;
	int				char_read;
	static char		buffer[BUFF_SIZE];

	eof = 0;
	eof = ft_strchr(buffer, '\n') ? 1 : 0;
	if (ft_strlen(buffer) > 0)
		ft_gnl_getnext(line, buffer);
	while (eof == 0 && (char_read = read(fd, buffer, BUFF_SIZE)))
	{
		eof = ft_strchr(buffer, '\n') ? 1 : 0;
		ft_gnl_getnext(line, buffer);
	}
	eof = (char_read > 0) ? 1 : 0;
	return (eof);
}

void	ft_gnl_getnext(char **line, char *buffer)
{
	int		pos_n;
	int		len;
	char	*tmp;
	char	*tmp2;

	tmp = ft_strdup(*line);
	len = ft_strlen(buffer);
	if (ft_strchr(buffer, '\n'))
	{
		pos_n = ft_strchr(buffer, '\n') - buffer;
		if (ft_strlen(*line))
		{
			tmp2 = ft_strsub(buffer, 0, pos_n);
			*line = ft_strjoin(tmp, tmp2);
			ft_strdel(&tmp2);
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
//	char	*tmp2;
	int		len;

	len = ft_strlen(buffer);
	if (ft_strlen(*line))
	{
	//	tmp2 = *line;
		*line = ft_strjoin(*line, buffer);
	}
	else
	{
		*line = ft_strdup(buffer);
	}
	ft_bzero(buffer, len);
}
