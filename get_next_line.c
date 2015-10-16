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
	static t_buffer	*buff_lst;
	t_buffer 		*buff;
	int				ret;
	int				eol;

	buff = ft_gnl_get_buffer(&buff_lst, fd);
	if (!line || fd < 1 || !buff)// || !*line)
		return (-1);
	ret = buff->ret_code;
	*line = NULL;//(*line) ? NULL : *line;
	eol = 0;
	while (ret > 0 && !eol && buff->ret_code > 0)
	{
		buff->char_read = 0;
		if (!buff->buffer[0])
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
	printf("%zu\n", ft_strlen(buff->buffer));
	if (ret == 0 || ret == -1)
		ft_gnl_del_buffer(&buff_lst, fd);
	return (ret);
}

void	ft_gnl_getnext(char **line, char *buffer)
{
	int		len;
	char	*tmp;
	char	*tmp2;
	char	*eol;
	
	eol = ft_strchr(buffer, '\n');
	len = (eol) ? (eol - buffer) : (int)ft_strlen(buffer);
	tmp = (*line) ? *line : NULL;
	*line = ft_strsub(buffer, 0, len);
	tmp2 = *line;
	if (tmp)
	{
		*line = ft_strjoin(tmp, tmp2);
		ft_strdel(&tmp);
	}
	if (tmp2 && tmp2 != *line)
		ft_strdel(&tmp2);
	if (eol)
	{
		ft_memmove(buffer, eol + 1, ft_strlen(eol + 1));
		ft_bzero(buffer + len, BUFF_SIZE - ft_strlen(eol));
	}
	else
		ft_bzero(buffer + ft_strlen(eol), BUFF_SIZE + 1);
}

void	ft_gnl_getnext2(char **line, char *buffer)
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
		len = ft_strlen(end_of_line + 1);
		len = (len) ? len : 1;
		*line = ft_strsub(buffer, 0, end_of_line - buffer);
		ft_memmove(buffer, end_of_line + 1, len);
	}
	else
	{
		tmp = *line;
		*line = ft_strdup(buffer);
		//ft_putendl(*line);
	}
	if (tmp)
	{
		tmp2 = *line;
		*line = ft_strjoin(tmp, *line);
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
	}
	printf("len sub: %ld\nbuffer + len: '%s'\n bzero: %'d'\n", end_of_line - buffer, buffer  + len, BUFF_SIZE - len - 1);
//ft_putendl(*line);
	ft_bzero(buffer + len, BUFF_SIZE - len - 1);
}

t_buffer	*ft_gnl_get_buffer(t_buffer **buffers, int fd)
{
	t_buffer	*tmp_buff;
	t_buffer	*new_buff;

	tmp_buff = *buffers;
	while (tmp_buff && tmp_buff->next)
	{
		if (tmp_buff->fd == fd)
			return (tmp_buff);
		tmp_buff = tmp_buff->next;
	}
	if (tmp_buff && tmp_buff->fd == fd)
		return (tmp_buff);
	new_buff = (t_buffer *)malloc(sizeof(t_buffer));
	if (new_buff)
	{
		new_buff->fd = fd;
		new_buff->ret_code = 1;
		new_buff->next = NULL;
		new_buff->buffer = ft_strnew(BUFF_SIZE + 1);
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
