/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocosquer <ocosquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:46:34 by ocosquer          #+#    #+#             */
/*   Updated: 2014/09/28 23:22:41 by ocosquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>

void	ft_bzero(void *byte, size_t len);
void	*ft_memmove(void *s1, const void *s2, size_t n);
size_t	ft_strlen(char *str);
char	*ft_strdup(const char *str);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strchr(const char *str, int c);
void	ft_memdel(void **ap);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);
void	ft_putstr(char const *s);
void	ft_putnbr(int n);
#endif
