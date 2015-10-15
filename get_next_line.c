/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/28 23:16:27 by ocosquer          #+#    #+#             */
/*   Updated: 2015/07/06 17:17:22 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	int					eol;
	int					char_read;
	int					ret_code;	
	static	t_buffer	*buffers;
	char				*buffer;

	ret_code = -2;
	char_read = 0;

	buffer = ft_gnl_get_buffer(&buffers, fd);
	if (line == NULL || fd < 1 || !buffer)
		return (-1);
	*line = (*line) ? NULL : *line;

	if (ft_strlen(buffer) > 0)
		ft_gnl_getnext(line, buffer);
	eol = ft_strchr(buffer, '\n') ? 1 : 0;
	while (!eol && (char_read = read(fd, buffer, BUFF_SIZE)))
	{
		eol = ft_strchr(buffer, '\n') ? 1 : 0;
		buffer[char_read] = '\0';
		ft_gnl_getnext(line, buffer);
	}
	ret_code = (char_read == 0 && ft_strlen(buffer) == 0) ? 0 : ret_code;
	ret_code = ((char_read > 0 || eol) && ret_code == -2) ? 1 : ret_code;
	ret_code = (ret_code == -2) ? -1 : ret_code;
	/*if (ret_code == 0 || ret_code == -1)
		ft_gnl_del_buffer(&buffers, fd);*/
	return (ret_code);
}

void	ft_gnl_getnext(char **line, char *buffer)
{
	char	*end_of_line;
	char	*tmp;
	char	*tmp2;
	int		len;

	end_of_line = ft_strchr(buffer, '\n');
	len = 0;
	if (end_of_line)
	{
		tmp = *line;
		*line = ft_strsub(buffer, 0, end_of_line - buffer);
		len = ft_strlen(end_of_line + 1);
		ft_memmove(buffer, end_of_line + 1, len);
	}
	else
	{
		tmp = *line;
		*line = ft_strdup(buffer);
	}
	if (tmp)
	{
		tmp2 = *line;
		*line = ft_strjoin(tmp, *line);
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
	}
	ft_bzero(buffer + len, BUFF_SIZE - len - 1);
}

char	*ft_gnl_get_buffer(t_buffer **buffers, int fd)
{
	t_buffer			*buff;
	t_buffer			*new_buff;

	buff = *buffers;
	new_buff = NULL;
	(void)new_buff;//TODO
	if (buff && buff->fd == fd)
		return (buff->buffer);
	while (buff && buff->next)
	{
		if (buff->fd == fd)
			return (buff->buffer);
		buff = buff->next;
	}
	return (ft_gnl_add_buffer(buffers, fd));
}

char	*ft_gnl_add_buffer(t_buffer **buffers, int fd)
{
	t_buffer	*new_buff;

	new_buff = (t_buffer *)malloc(sizeof(t_buffer));
	if (new_buff)
	{
		new_buff->fd = fd;
		new_buff->next = NULL;
		new_buff->buffer = ft_strnew(BUFF_SIZE + 1);
		while(*buffers && (*buffers)->next)
			*buffers = (*buffers)->next;
		if (*buffers)
			(*buffers)->next = new_buff;
		else
			*buffers = new_buff;
	}
	return (new_buff->buffer);
}

void		ft_gnl_del_buffer(t_buffer **buffers, int fd)
{
	t_buffer	*prev;
	t_buffer	*cur;
	t_buffer	*next;

	(void)next;//TODO
	if (*buffers)
	{
		prev = *buffers;
		cur = prev->next;
		while (cur && cur->fd != fd)
		{
			prev = cur;
			cur = cur->next;
		}
		if (cur && cur->fd == fd)
		{
			prev->next = cur->next;
			ft_strdel(&cur->buffer);
			free(cur);
		}
	}
}
