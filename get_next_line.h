/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivier <olivier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/28 23:19:38 by ocosquer          #+#    #+#             */
/*   Updated: 2015/07/06 17:17:36 by olivier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 512
# include "libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef	struct	s_buffer
{
	char				*buffer;
	int					fd;
	struct	s_buffer	*next;
}				t_buffer;
int			get_next_line(int fd, char **line);
void		ft_gnl_getnext(char **line, char *buffer);
char		*ft_gnl_get_buffer(t_buffer **buffers, int fd);
char		*ft_gnl_add_buffer(t_buffer **buffers, int fd);
void		ft_gnl_del_buffer(t_buffer **buffers, int fd);
#endif
