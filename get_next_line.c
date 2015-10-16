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

void	ft_display_buffer(t_buffer *buffer)
{
	ft_putstr("FD:");
	printf("'%d'", buffer->fd);
//	ft_putnbr(buffer->fd);
	ft_putstr(";");
	ft_putstr("\nContent:");
	ft_putendl(buffer->buffer);
}

void	ft_print_buffers(t_buffer *buffers)
{
	ft_putendl("Liste des Files descriptors ouverts:");
	while (buffers)
	{
		ft_display_buffer(buffers);
		buffers = buffers->next;
	}
}
int		get_next_line(int fd, char **line)
{
	static t_buffer	*buff_lst;
	static t_buffer *buff;
	int				ret;
	int				eol;

	buff = ft_gnl_get_buffer(&buff_lst, fd);
	if (!line || fd < 1 || !buff)// || !*line)
		return (-1);
	else
		ret = buff->ret_code;
	*line = (*line) ? NULL : *line;
	eol = 0;
	while (ret > 0 && !eol && buff->ret_code > 0)
	{
		buff->char_read = 0;
		if (!ft_strlen(buff->buffer))
		{
			buff->char_read = read(buff->fd, buff->buffer, BUFF_SIZE);
			buff->buffer[buff->char_read] = '\0';
		}
		ft_gnl_getnext(line, buff->buffer);
		eol = ft_strchr(buff->buffer, '\n') ? 1 : 0;
		ret = (buff->char_read == 0 && ft_strlen(buff->buffer) == 0) ? 0 : ret;
		ret = ((buff->char_read > 0 || eol) && ret == -2) ? 1 : ret;
		ret = (ret == -1 || buff->char_read == -1) ? -1 : ret;
		buff->ret_code = ret;
	}
	if (ret == 0 || ret == -1)
		ft_gnl_del_buffer(&buff_lst, fd);
	return (ret);
}
/*int		get_next_line(int fd, char **line)
{
	return (get_next_line2(fd, line));
	int					eol;
	int					char_read;
	int					ret_code;
	static	t_buffer	*fd_lst;
	t_buffer			*cur_fd;

	ret_code = -2;
	char_read = 0;

	//ft_print_buffers(buffers);
	cur_fd = ft_gnl_get_buffer(&fd_lst, fd);
	if (line == NULL || fd < 1 || !cur_fd->buffer)
		return (-1);
	*line = (*line) ? NULL : *line;
	if (ft_strlen(cur_fd->buffer) > 0)
		ft_gnl_getnext(line, cur_fd->buffer);
	eol = ft_strchr(cur_fd->buffer, '\n') ? 1 : 0;
	if (cur_fd->ret_code <= 0)
	{
		ret_code = cur_fd->ret_code;
		return (ret_code);
	}
	while (!eol && (char_read = read(fd, cur_fd->buffer, BUFF_SIZE)))
	{
		eol = ft_strchr(cur_fd->buffer, '\n') ? 1 : 0;
		cur_fd->buffer[char_read] = '\0';
		ft_gnl_getnext(line, cur_fd->buffer);
	}
	ret_code = (char_read == 0 && ft_strlen(cur_fd->buffer) == 0) ? 0 : ret_code;
	ret_code = ((char_read > 0 || eol) && ret_code == -2) ? 1 : ret_code;
	ret_code = (ret_code == -2) ? -1 : ret_code;
	cur_fd->ret_code = ret_code;
	if (ret_code == 0 || ret_code == -1)
		ft_gnl_del_buffer(&fd_lst, fd);
	return (ret_code);
}*/

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

t_buffer	*ft_gnl_get_buffer(t_buffer **buffers, int fd)
{
	t_buffer			*buff;

	buff = *buffers;
	while (buff)
	{
		if (buff->fd == fd)
		{
			//printf("buffer '%d' exist!\n", fd);
			return (buff);
		}
		buff = buff->next;
	}
	//printf("buffer '%d' not found!\n", fd);
	return (ft_gnl_add_buffer(buffers, fd));
}

t_buffer	*ft_gnl_add_buffer(t_buffer **buffers, int fd)
{
	t_buffer	*new_buff;
	t_buffer	*tmp_buff;

	new_buff = (t_buffer *)malloc(sizeof(t_buffer));
	tmp_buff = *buffers;
	if (new_buff)
	{
		new_buff->fd = fd;
		new_buff->ret_code = 1;
		new_buff->next = NULL;
		new_buff->buffer = ft_strnew(BUFF_SIZE + 1);
		while(tmp_buff && tmp_buff->next)
			tmp_buff = tmp_buff->next;
		if (tmp_buff)
			tmp_buff->next = new_buff;
		else
			*buffers = new_buff;
	}
	return (new_buff);
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
