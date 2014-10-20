/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/28 23:19:38 by ocosquer          #+#    #+#             */
/*   Updated: 2014/09/29 00:01:52 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 12
# include "libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

int			get_next_line(int fd, char **line);
void		ft_gnl_getnext(char **line, char *buffer);
void		ft_gnl_getnext2(char **line, char *buffer);
#endif
